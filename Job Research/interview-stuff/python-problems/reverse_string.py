#!/usr/bin/env python3.5

def reverse_string(string: str):
	return "".join([string[-index] for index, element in enumerate(string, 1)])

print(reverse_string("Hello World"))

