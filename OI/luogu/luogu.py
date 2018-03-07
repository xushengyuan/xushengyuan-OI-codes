import re
import requests

html = requests.get('https://www.luogu.org/problemnew/show/P2327').content.decode('utf-8')
r = re.compile('(?<=<div class="lg-article am-g">)[\W\w]*?(?=</div>)',re.M)
texts=r.findall(html)
print(texts[0])