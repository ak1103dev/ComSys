#!/usr/bin/python
# -*- coding: utf-8 -*-

import subprocess
import sys

filename = sys.argv[1].split('.cpp')[0]
p = subprocess.Popen("g++ " + filename + ".cpp && ./a.out", stdout=subprocess.PIPE, shell=True)
previous = -1
isSort = True

for num in p.stdout.read().strip().split('\n'):
    try:
        if int(num) < int(previous):
            isSort = False
            break
        previous = num
    except:
        continue

text = '=' * 5
if isSort:
    print '\033[1;32m' + text + ' Pass ' + text + '\033[1;m'
else :
    print '\033[1;31m' + text + ' Fail ' + text + '\033[1;m'
    
