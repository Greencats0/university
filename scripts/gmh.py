#!/usr/bin/env python3.5

# Get math homework listings

from selenium import webdriver
import time

driver = webdriver.Firefox()

url = "https://www.saplinglearning.com/ibiscms/login/"

driver.get(url)

time.sleep(1)

driver.find_element_by_css_selector("input[id='username']").send_keys("jareddyreson@csu.fullerton.edu")
driver.find_element_by_css_selector("input[id='password']").send_keys("#i9E7*N#gp8u^k")
driver.find_element_by_css_selector("input[id='submitButton']").click()

time.sleep(2)

driver.get("http://www.saplinglearning.com/ibiscms/course/view.php?id=105170")

table = driver.find_element_by_css_selector("td[class='date']")

print(table)
