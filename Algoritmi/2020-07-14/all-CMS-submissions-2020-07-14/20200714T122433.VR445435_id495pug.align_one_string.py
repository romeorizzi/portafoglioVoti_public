"""
* user:  VR445435_id495pug
* fname: MATTEO
* lname: ZEGGIOTTI
* task:  align_one_string
* score: 2.0
* date:  2020-07-14 12:24:33.396115
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

#memoize = {}
def align2(a, b, first=False):
#    if (a,b) in memoize:
#        return memoize[(a,b)]
    if len(a) == 0 and len(b) == 0:
        return 0, ''
    if len(b) == 0:
        return cost[len(a)], '*'*(len(a))
    if len(a) == 0:
        return float("inf"), ''
    seq = ""
    min_cost = float("inf")
    if a[0] == b[0]:
        if len(b) == 1:
            new, sub = align2(a[1:len(a)], [])
            if new < min_cost:
                min_cost = new
                seq = a[0] + sub
        else:
            for i in range(1,len(a)):
                if a[i] == b[1] and i - 1<len(cost):
                    new, sub = align2(a[i:len(a)], b[1:len(b)])
                    new += cost[i-1]

                    if new < min_cost:
                        min_cost = new
                        seq = a[0] + '*'*(i-1) + sub


    if first:
        for i in range(0, len(cost)):
            if a[i] == b[0]:
                new, sub = align2(a[i:len(a)], b[0:len(b)])
                new += cost[i]

                if new < min_cost:
                    min_cost = new
                    seq = '*'*i + sub

    return min_cost, seq




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


n, _ = align2(a,b, True)




if n < float("inf"):
    print(n)
else:
    print("-1")
