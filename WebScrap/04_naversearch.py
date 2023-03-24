from bs4 import BeautifulSoup
from urllib.request import urlopen
from urllib.parse import quote_plus
import pandas as pd
import csv

keyword = input("keyword: ")
url = f"https://m.search.naver.com/search.naver?where=nexearch&sm=top_hty&fbm=1&ie=utf8&query={quote_plus(keyword)}"
html = urlopen(url).read()
soup = BeautifulSoup(html, "html.parser")


total = soup.select(".api+txt_lines.total_tit")
searchlist = []

for i in total:
    temp = []
    temp.append(i.text)
    temp.append(i.attrs["href"])
    searchlist.append(temp)

file_name = "search.csv"
f = open(file_name, "w", encoding="utf-8-sig", newline="")
writer = csv.writer(f)
for i in searchlist:
    writer.writerow(i)

f.close()

df = pd.read_csv(file_name)
df.to_excel("search.xlsx")
