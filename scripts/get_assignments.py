#!/usr/bin/env python3.5

import login
from starbucksautoma import adding_events, time_struct
from datetime import datetime, timedelta

myclass = login.csuf_portal_handler(headless=True)
myclass.base_login()
myclass.titanium_login()
myclass.get_recent_events()
myclass.kill_driver()

def example():
	# this code is meant to be an framework for adding assignment events directly into Google Calendar
	bot = adding_events.GoogleEventHandler()
	
	#Tuesday, September 10, 7:00 PM
	homework_event = "Tuesday, September 10, 8:00 PM"
	homework_event_time_start = datetime.strptime(homework_event, "%A, %B %d, %I:%M %p")
	homework_event_time_end = homework_event_time_start+timedelta(hours=1)
	
	add_to_calendar = time_struct.time_struct(homework_event_time_start, homework_event_time_end, "Example Homework Event")

	bot.add_event(add_to_calendar)
