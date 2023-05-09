from linecache import getline
import numpy as np
import re

text = re.compile('totrecorded')
num = re.compile('\d+\.\d+')

cell = 0

for el, col in enumerate(open('brilcalc.log')):
    for match in re.finditer(text, col): cell = el + 3

l = getline('brilcalc.log', cell)

answ = 0

for match in re.finditer(num, l): 
     answ = float(match.group())

print('Total recorded luminosity: {:.1f} fb-1'.format(answ/1000))


