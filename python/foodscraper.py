from bs4 import BeautifulSoup
import urllib2
from xlwt import Workbook

response = urllib2.urlopen('http://caldining.berkeley.edu/menus/summer-menu-2016-week1')
html = response.read()

soup = BeautifulSoup(html, 'html.parser')
foods = []

for i in range(7):
    foods.append([])
    for j in range(3):
        foods[i].append([])

dates = soup.find_all('p', {"class" : "title2"})

for date in dates:
    value = date.next_sibling.next_sibling.children
    print (date.contents[1].string)
    for num in value:
        if num.name == 'tbody':
            for t in num.children:
                if t.name == 'tr':
                    for x in t.children:
                        if x.name == "td":
                            for a in x.children:
                                print(a['style'])
                                print ('++++++++++++++')
