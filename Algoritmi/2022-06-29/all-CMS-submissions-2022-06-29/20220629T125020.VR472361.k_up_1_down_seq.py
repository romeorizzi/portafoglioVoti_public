"""
* user:  VR472361
* fname: ELIA
* lname: PERANTONI
* task:  k_up_1_down_seq
* score: 14.0
* date:  2022-06-29 12:50:20.391074
"""
from functools import lru_cache
import sys

sys.setrecursionlimit(100000)

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


print(f(0, n - 1))
