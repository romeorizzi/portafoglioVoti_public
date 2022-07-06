"""
* user:  VR472361
* fname: ELIA
* lname: PERANTONI
* task:  k_up_1_down_seq
* score: 47.0
* date:  2022-06-29 13:05:10.231362
"""
#!/usr/bin/env python3
from functools import lru_cache
import sys

sys.setrecursionlimit(1000000000)

g, n, k = [int(word) for word in input().split()]


@lru_cache(maxsize=None)
def f(at, len):
    if len == 0:
        if at == 0:
            return 1
        else:
            return 0

    res = 0

    res += f(at, len - 1)
    if at - 1 >= 0:
        res += f(at - 1, len - 1)
    res += f(at + k, len - 1)

    return res


@lru_cache(maxsize=None)
def gen(at, len):
    if len == 0:
        if at == 0:
            return ["0"]
        else:
            return []

    strs = []


    if at - 1 >= 0:
        strs += gen(at - 1, len - 1)
    strs += gen(at, len - 1)
    strs += gen(at + k, len - 1)

    strs = [str(at) + " " + s for s in strs]

    return strs


if g == 1:
    print(f(0, n - 1) % 1000000007)
elif g == 4:
    for s in gen(0, n-1):
        print(s)
