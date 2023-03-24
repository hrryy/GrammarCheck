import requests
from bs4 import BeautifulSoup

url = "https://www.google.com"
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.89 Safari/537.36"}
res = requests.get(url, headers=headers)
soup = BeautifulSoup(res.text, "html.parser")

print(soup)

with open("mygoogle.html", "w", encoding="utf8") as f:
    f.write(res.text)
