"""
* user:  VR473639
* fname: ANDREA
* lname: CINELLI
* task:  esamebridges_and_cutnodes
* score: 0.0
* date:  2022-07-26 10:33:23.263523
"""
from functools import lru_cache


t, n, m = tuple(map(int,input().split()))

e = []
v = set()


for i in range(m):
    v1,v2 = tuple(map(int,input().split()))
    e.append((v1,v2))
    v.add(v1)
    v.add(v2)

def check_connected(vert, arc):
    for a in arc:
        if a[0]<

print(v.pop())
print(v.pop())

    