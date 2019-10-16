#!/usr/bin/env python3.5

from selenium import webdriver
import time

url = "https://www.wileyplus.com/WileyCDA/Section/id-WILEYPLUS_LOGIN.html"
driver = webdriver.Firefox()
driver.get(url)

time.sleep(2)

driver.find_element_by_css_selector("input[id='email']").send_keys("jareddyreson@csu.fullerton.edu")
password_field = driver.find_element_by_name("password")
driver.execute_script("arguments[0].click();", password_field)
password_field.send_keys("sample password")
driver.find_element_by_css_selector("input[id='Login']").click()
