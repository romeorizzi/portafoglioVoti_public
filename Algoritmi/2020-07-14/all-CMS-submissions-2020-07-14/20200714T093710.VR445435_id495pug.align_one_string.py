"""
* user:  VR445435_id495pug
* fname: MATTEO
* lname: ZEGGIOTTI
* task:  align_one_string
* score: 2.0
* date:  2020-07-14 09:37:10.004172
"""
#!/usr/bin/env python3

m, n, p = input().rstrip().split(" ")
m = int(m)
n = int(n)
p = int(p)
a = input().rstrip()
b = input().rstrip()
cost = list(map(int, input().rstrip().split(" ")))


def align(b, created = "", pos=0, consec = 0):
    best_str = created
    
    if b == "" and len(created) == len(a):
        return cost[consec], best_str
    elif len(created) == len(a) or consec >= p :
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

n, _ = align(b=b)
if n < float("inf"):
    print(n)
else:
    print("-1")