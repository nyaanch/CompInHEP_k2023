from linecache import getline
import numpy as np
import re

def getSum():
    bar = re.compile('\|')
    text = re.compile('totrecorded')
    num = re.compile('\d+\.\d+')

    sum = 0
    arr = []

    for el, col in enumerate(open('brilcalc.log')):
        for match in re.finditer(text, col): 
            return sum
        
        for match in re.finditer(num, col): 
            arr.append(float(match.group()))

        if len(arr) > 1: sum += np.min(arr)
        
        arr = []

print('Total recorded luminosity: {:.1f} fb-1'.format(getSum()/1000))