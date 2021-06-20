import requests
import re
from bs4 import BeautifulSoup

def get_IP():
	ip = None
	with open('../../IP') as file:
		return file.readlines()[0].strip()


r = requests.get(get_IP() + 'index.php?page=redirect&site=khrib9a')
script = r.text
soup = BeautifulSoup(script, 'html.parser')
s = soup.find('center')
print(s.text)