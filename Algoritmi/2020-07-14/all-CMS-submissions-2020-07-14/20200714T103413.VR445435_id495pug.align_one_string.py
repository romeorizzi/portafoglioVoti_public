"""
* user:  VR445435_id495pug
* fname: MATTEO
* lname: ZEGGIOTTI
* task:  align_one_string
* score: 2.0
* date:  2020-07-14 10:34:13.779561
"""
#!/usr/bin/env python3
import sys

sys.setrecursionlimit(10**9)
m, n, p = input().rstrip().split(" ")
m = int(m)
n = int(n)
p = int(p)
a = input().rstrip()
b = input().rstrip()
cost = list(map(int, input().rstrip().split(" ")))
if m != len(a) or n != len(b) or p + 1 != len(cost):
    exit(1)

memoize = {}
def align2(a, b):
    if (a,b) in memoize:
        return memoize[(a,b)]
    consec = 0
    best_str = ""
    if len(a) == 0 and len(b) == 0:
        return 0, '', 0
    if len(a) == 0 and len(b) != 0:
        return float("inf"), '', 0
    elif consec >= p + 1 :
        return float("inf"), '', 0
    min_choice = float("inf")
    if b != "" and a != "" and b[0] == a[0]:
        min_choice, best_str, consec = align2(a[1:len(a)], b[1:len(b)])
        best_str = b[0] + best_str
        min_choice += cost[consec]
        consec = 0
    new_try, new_str, new_consec = align2(a[1:len(a)], b)
    new_str = "*" + new_str
    if new_try < min_choice:
        min_choice = new_try
        best_str = new_str
        consec = new_consec + 1
    memoize[(a,b)] = (min_choice, best_str, consec)
    return min_choice, best_str, consec


def align(b, created = "", pos=0, consec = 0):
    best_str = created
    if b == "" and len(created) == len(a):
        return cost[consec], best_str
    elif len(created) == len(a) or consec >= p + 1 :
        return float("inf"), best_str
    min_choice = float("inf")
    if b != "" and b[0] == a[pos]:
        min_choice, best_str = align(b[1:len(b)], created + b[0] , pos + 1, 0)
        min_choice += cost[consec]
    new_try, new_str = align(b, created + "*", pos + 1, consec + 1)
    if new_try < min_choice:
        min_choice = new_try
        best_str = new_str
    return min_choice, best_str

n,_,_ = align2(a,b)

if n < float("inf"):
    print(n)
else:
    print("-1")
