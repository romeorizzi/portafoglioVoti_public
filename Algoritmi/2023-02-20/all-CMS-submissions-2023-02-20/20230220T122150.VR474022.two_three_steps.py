"""
* user:  VR474022
* fname: FILIPPO
* lname: ZICHE
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:21:50.265896
"""

from functools import lru_cache

import sys
sys.setrecursionlimit(1000000)

n = 0
piastrelle = []

def solve(current, cache):

    # memoizziamo
    if current in cache:
        return cache[current]

    # siamo usciti
    if current >= n:
        return 0

    # Prova ogni step
    step_2 = solve(current + 2, cache)
    step_3 = solve(current + 3, cache)

    result = piastrelle[current] + max(step_2, step_3)
    cache[current] = result
    return result


def create_cache():

    cache = {}

    cache[n - 1] = 0
    cache[n - 2] = 0
    cache[n - 3] = piastrelle[n - 3] + cache[n - 1]

    # da n - 4 a 0
    for cur in reversed(range(0, n - 3)):
        cache[cur] = piastrelle[cur] + max(cache[cur + 2], cache[cur + 3])

    return cache


with open("input.txt") as f:
    lines = [line for line in f]
    n = int(lines[0])
    piastrelle = [int(x) for x in lines[1].split()]

cache = create_cache()
res = solve(0, cache)

with open("output.txt", "w") as f:
    f.write(str(res))