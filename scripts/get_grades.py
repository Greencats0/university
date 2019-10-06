#!/usr/bin/env python3.5

import login

myclass = login.csuf_portal_handler(headless=False)
myclass.base_login()
myclass.titanium_login()
myclass.find_grades()
myclass.kill_driver()
