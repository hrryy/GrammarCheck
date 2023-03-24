import requests
from bs4 import BeautifulSoup

url = "https://www.bestbuy.ca/en-ca"
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.89 Safari/537.36"}
res = requests.get(url, headers=headers)
soup = BeautifulSoup(res.text, "html.parser")

items = soup.find_all("li", attrs={"class": "productItemContainer_1KkmO"})

for item in items:
    name = item.find("span", attrs={"class:", "truncate_gQkhK"}).get_text()
    price = item.find(
        "span", attrs={"class:", "screenReaderOnly_2mubv large_3uSI_"}).get_text()
    save = item.find(
        "span", attrs={"class:", "productSaving_3T6HS top_3-SyT"}).get_text()
    link = item.find("a", attrs={"class:", "link_3hcyN"})["href"]
    link = "https://www.bestbuy.ca/" + link

    print(f"name : {name}")
    print(f"price : {price}")
    print(f"save : {save}")
    print(f"link : {link}")
    print("-"*100)
