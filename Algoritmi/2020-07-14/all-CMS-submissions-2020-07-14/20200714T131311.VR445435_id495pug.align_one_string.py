"""
* user:  VR445435_id495pug
* fname: MATTEO
* lname: ZEGGIOTTI
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 13:13:11.394929
"""
#!/usr/bin/env python3
import sys

sys.setrecursionlimit(10**9)
m, n, p = input().rstrip().split(" ")
m = int(m)
n = int(n)
p = int(p)
aa = input().rstrip()
bb = input().rstrip()
cost = list(map(int, input().rstrip().split(" ")))

memoize = {}
def align2(a, b, first=False):
    if (a, b) in memoize:
        return memoize[(a, b)]
    if len(a) == 0 and len(b) == 0:
        return 0, ''
    if len(b) == 0:
        return 0, '*'*(len(a))
    if len(a) == 0:
        return float("inf"), ''
    seq = ""
    min_cost = float("inf")
    if a[0] == b[0]:
        if len(b) == 1:
            new, sub = align2(a[1:len(a)], "")
            new+=cost[len(a) - 1]
            if new < min_cost:
                min_cost = new
                seq = a[0] + sub
        else:
            for i in range(1,len(a)):
                new = 0
                if i<len(cost):

                    new, sub = align2(a[i:len(a)], b[1:len(b)])
                    new += cost[i-1]

                    if new < min_cost:
                        min_cost = new
                        seq = a[0] + '*'*(i-1) + sub
    else:
        for i in range(0, len(a)):
            if a[i] == b[0] and i < len(cost):

                new, sub = align2(a[i:len(a)], b[0:len(b)])
                new += cost[i]

                if new < min_cost:
                    min_cost = new
                    seq = '*' * i + sub

    if first:
        for i in range(0, len(a)):
            if a[i] == b[0] and i<len(cost):

                new, sub = align2(a[i:len(a)], b[0:len(b)])
                new += cost[i]

                if new < min_cost:
                    min_cost = new
                    seq = '*'*i + sub
    memoize[(a,b)] = (min_cost, seq)
    return min_cost, seq



'''
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
'''

n, s = align2(aa,bb, True)

print(s)


if n < float("inf"):
    print(n)
else:
    print("-1")
