import requests
from bs4 import BeautifulSoup
data = {
	'sujet':'42',
	'valeur':'42'
}

def get_IP():
	ip = None
	with open('../../IP') as file:
		return file.readlines()[0].strip()



r = requests.post(get_IP() + 'index.php?page=survey', data=data)
soup = BeautifulSoup(r.content, 'html.parser')
result = soup.find('h2')
print(result.text)
