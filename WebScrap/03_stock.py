import requests
from bs4 import BeautifulSoup
import pandas as pd
import csv

url = "https://finance.naver.com/sise/sise_market_sum.naver?&page="
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.89 Safari/537.36"}

file_name = "stock.csv"
f = open(file_name, "w", encoding="utf-8-sig", newline="")
writer = csv.writer(f)

title = "N	종목명	현재가	전일비	등락률	액면가	시가총액	상장주식수	외국인비율	거래량	PER	ROE	토론실".split("\t")
writer.writerow(title)


for page in range(1, 4):
    res = requests.get(url+str(page), headers=headers)
    res.raise_for_status()
    soup = BeautifulSoup(res.text, "html.parser")

    rows = soup.find("table", attrs={"class": "type_2"}).find(
        "tbody").find_all("tr")
    for row in rows:
        cols = row.find_all("td")
        if len(cols) <= 1:
            continue
        data = [col.get_text().strip() for col in cols]
        # print(data)
        writer.writerow(data)
f.close()

df = pd.read_csv(file_name)
df.to_excel("stock.xlsx")
