import requests
from bs4 import BeautifulSoup

url = input("url: ")

response = requests.get(url)

if response.status_code == 200:
    contents = BeautifulSoup(response.content, "html-parser")

    links = contents.find_all("a")
    for link in links:
        print(link.get("href"))

    images = contents.find_all("img")
    for image in images:
        print(image.get("src"))

    title = contents.find("title")
    print("Title: " + title.text)

else:
    print("Error from" + url)
