import requests
import json
from bs4 import BeautifulSoup
r = requests.get('https://github.com/trending')
soup = BeautifulSoup(r.text, 'lxml')
repository_names_info = soup.find_all(class_='text-normal')
repository_stars_info = soup.find_all(class_="Link Link--muted d-inline-block mr-3")
print(repository_names_info)
print(repository_stars_info)
print(soup.get_text())