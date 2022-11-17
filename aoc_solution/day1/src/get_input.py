#! /usr/bin/env python3
import requests

cookies = {"session": "<session_cookie_here>"}

url = "https://adventofcode.com/2015/day/1/input"

resp = requests.get(url, cookies = cookies)

print(resp.text)
