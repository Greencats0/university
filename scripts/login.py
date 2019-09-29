#!/usr/bin/env python3.5

from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException
from selenium.webdriver.firefox.options import Options

import time
import os
import shutil
from pprint import pprint as pp
import operator
from termcolor import colored

import urllib.request


class csuf_portal_handler():
	def __init__(self, headless=False):
		headless_ = Options()
		if(headless): headless_.headless = headless
		self.driver = webdriver.Firefox(options=headless_)

		self.titanium_url = "https://moodle-2019-2020.fullerton.edu/my/"
		self.base_login_url = "https://my.fullerton.edu"
		self.csuf_base_portal_url = "https://my.fullerton.edu/Portal/Dashboard/"
		self.run_audit_url = "https://tda.fullerton.edu/selfservice-batch/audit/create.html"
		self.manage_audit_url = "https://tda.fullerton.edu/selfservice-batch/audit/list.html"
		self.grades_url = "https://moodle-2019-2020.fullerton.edu/grade/report/overview/index.php"
		self.upcoming_events_url = "https://moodle-2019-2020.fullerton.edu/calendar/view.php?view=upcoming&course=1&time=1567230117"

	# LOGIN FUNCTIONS #

	def base_login(self):
		self.driver.get(self.base_login_url)
		with open("/home/jared/Applications/csuf-utils/credentials.txt", "r") as f:
			content = f.readlines()
		username = content[0].split(":")[1].strip()
		password = content[1].split(":")[1].strip()
		self.driver.find_element_by_css_selector("input[id='username']").send_keys("{}".format(username))
		self.driver.find_element_by_css_selector("input[id='password']").send_keys("{}".format(password))
		self.driver.find_element_by_css_selector("button[class='LoginButton']").click()
	def titanium_login(self):
		self.driver.get(self.titanium_url)
		time.sleep(5)
	def csuf_portal_login(self):
		self.driver.get(self.csuf_base_portal_url)
		time.sleep(5)

	# ACTION FUNCTIONS #

	def get_events(self):
		return self.driver.find_element_by_css_selector("div[class='card-text content calendarwrapper']").text

	def get_recent_events(self):
# use datetime to see if the time has passed.
# make the current date and create another datetime of the event time.
# if the event created is less than the current date, then you don't have to print it
		self.driver.get(self.upcoming_events_url)
		time.sleep(2)
		events = self.driver.find_elements_by_css_selector("div[class='event']")
		for event in events:
			try: 
				description = event.find_element_by_css_selector("div[class='description card-block calendar_event_due']").find_elements_by_tag_name("p")
				description_list = [element.text.strip() for element in description if element.text]
				description = "\n".join(description_list)
			except NoSuchElementException: description = ""

			event_title = event.find_element_by_css_selector("h3[class='name d-inline-block']").text
			event_time = event.find_element_by_css_selector("span[class='date pull-xs-right m-r-1']").text
			event_type = event.find_element_by_css_selector("div[class='d-inline-block mt-1 align-top']").find_element_by_css_selector("img[class='icon ']").get_attribute("src").split("/")[-3].capitalize()

			#attrs = self.driver.execute_script('var items = {}; for (index = 0; index < arguments[0].attributes.length; ++index) { items[arguments[0].attributes[index].name] = arguments[0].attributes[index].value }; return items;', event_type)
			#pp(attrs)
			if("Yesterday" not in event_time):
				print("="*75)
				print("[{}] {} @ {}".format(event_type, event_title, event_time))
				print("Description: {}".format(description))
				print("="*75)
	
	def find_grades(self):
		self.driver.get(self.grades_url)
		grade_view = self.driver.find_elements_by_xpath("//*[starts-with(@id, 'grade-report-overview-93391')]")
		mapping = {}
		for grade in grade_view:
			string_split = grade.text.split()
			if(grade.text and len(string_split) >= 6):
				string_split = grade.text.split()
				class_name = "{} {}".format(string_split[2], string_split[3])
				mapping[class_name] = grade.find_element_by_tag_name("a").get_attribute("href")
		grade_mapper = {}
		for key, value in mapping.items():
			self.driver.get(value)
			time.sleep(2)
			try: grade = self.driver.find_element_by_css_selector("td[class='level1 levelodd oddd1 baggb itemcenter  column-percentage']").text.replace("%", "").strip()
			except NoSuchElementException: grade = self.driver.find_element_by_css_selector("td[class='level1 levelodd oddd1 baggb itemcenter  column-grade']").text.replace("%", "").strip()
			if(isinstance(grade, str) and "-" in grade): grade = 0
			else: grade = float(grade)
			grade_mapper[key] = grade
		sorted_dictionary = sorted(grade_mapper.items(), key=operator.itemgetter(1), reverse=True)
		for element in sorted_dictionary:
			print(colored("Course {} --> {}%".format(element[0], element[1])), self.get_grade_color(element[1]))
	def get_grade_color(self, grade_amount: int):
		if(grade_amount >= 90 or grade_amount == 100): return "green"
		elif(grade_amount >= 80 and grade_amount <= 89): return "blue"
		elif(grade_amount >= 70 and grade_amount <= 79): return "yellow"
		elif(grade_amount >= 60 and grade_amount <= 69): return "magenta"
		else: return "red"
	def go_to_audit_page(self):
		self.driver.get(self.run_audit_url)
		time.sleep(5)

	def run_audit(self):
		print("[+] Running audit...")
		self.go_to_audit_page()
		self.driver.find_element_by_xpath("//select[@id='reportType']/option[text()='HTML']").click()
		self.driver.find_element_by_css_selector("input[title='Run Audit']").click()
		time.sleep(10)
		view_most_recent_audit()
	
	def view_most_recent_audit(self):
		print("[+] Getting most recent audit...")
		self.driver.get(self.manage_audit_url)
		time.sleep(5)
		self.driver.find_element_by_link_text("View Audit").click()
		time.sleep(4)
	def get_attributes(self, element):
		# returns a dictionary of attributes a given web element contains
		return self.driver.execute_script('var items = {}; for (index = 0; index < arguments[0].attributes.length; ++index) { items[arguments[0].attributes[index].name] = arguments[0].attributes[index].value }; return items;', element)
	def kill_driver(self):
		self.driver.quit()
		os.remove("geckodriver.log")
		shutil.rmtree("__pycache__")
