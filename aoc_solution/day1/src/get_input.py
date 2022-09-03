#! /usr/bin/env python3
import requests

cookies = {"session": "53616c7465645f5f2ce9102ace19138016bc33216dbae16d73fce4fd5bffb9e1db4463a0115920e23071df98381b24c5f8d675b86a8126a311e8d00259f327b7"}

url = "https://adventofcode.com/2015/day/1/input"

resp = requests.get(url, cookies = cookies)

print(resp.text)
