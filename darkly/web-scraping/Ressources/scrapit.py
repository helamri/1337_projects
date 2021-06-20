import requests
from bs4 import BeautifulSoup
import re
from urllib.request import urlopen

urls_count = 0 #18279
def scrape(response):
    global urls_count
    soup = BeautifulSoup(response.content, 'html.parser')
    result = ''
    for tag in soup.find_all('a', href=True)[1:]:
        if tag['href'] == 'README':
            with open("sitemap.txt", "a") as file:
                result = response.request.url + tag['href'] + '\n'
                urls_count += 1
                print(f"Urls scrapped: {urls_count}", end="\r")
                file.write(result)
        else:
            r = requests.get(response.request.url + tag['href'])
            scrape(r)
    return 

def get_IP():
	ip = None
	with open('../../IP') as file:
		return file.readlines()[0].strip()



r = requests.get(get_IP() + ".hidden/")
scrape(r)
total_urls_checked = 0
print(f"There is {urls_count} will be checked")
with open('sitemap.txt') as sitemap:
   
    line = sitemap.readline()
    while line:
        total_urls_checked += 1
        print(f"Urls checked : {total_urls_checked}/{urls_count}", end="\r")
        with urlopen(line) as response:
            html = response.read().decode('utf-8')
            lst = re.findall(r"([a-fA-F\d]{33})", html)
            if lst:
                print('\nHere is the flag ' + lst[0])
                print(line)
                exit(0)
        line = sitemap.readline()