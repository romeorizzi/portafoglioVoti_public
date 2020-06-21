"""
* user:  VR439670
* fname: LUCCHESE
* lname: MARCO
* task:  Prob1_tree_split_out
* score: 0.0
* date:  2019-09-04 11:16:45.643158
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

from __future__ import print_function
import sys
sys.setrecursionlimit(100000)
if sys.version_info < (3, 0):
    input = raw_input # in python2, raw_input svolge la funzione della primitiva input in python3

"""Template per soluzione in python per il problema tree_split_out
Romeo Rizzi, per l'appello di algoritmi 2019-09-04
"""

MAX_N = 1000000

seq = list(map(int,input().split()))

# in questo template di soluzione mi limito a ricopiare l'input in output (non sarŕ mai la soluzione corretta tranne che per alberi di un solo nodo):
c=0;
for val in seq:
    if(c==0):
        print(val)
        c+=1
    else:
        if (val%2==0):
            print(val)
        elif (val==0):
            print(val)
        else
            continue
    
print()
