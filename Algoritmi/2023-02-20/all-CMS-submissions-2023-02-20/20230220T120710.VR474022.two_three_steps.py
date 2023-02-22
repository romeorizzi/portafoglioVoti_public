"""
* user:  VR474022
* fname: FILIPPO
* lname: ZICHE
* task:  esame_two_three_steps
* score: 50.0
* date:  2023-02-20 12:07:10.787790
"""

from functools import lru_cache

n = 0
piastrelle = []

@lru_cache(maxsize=1024)
def solve(current):

    # memoizziamo
    #if current in cache:
    #    return cache[current]

    # siamo usciti
    if current >= n:
        return 0

    # Prova ogni step
    step_2 = solve(current + 2)
    step_3 = solve(current + 3)

    result = piastrelle[current] + max(step_2, step_3)
    #cache[current] = result
    return result

with open("input.txt") as f:
    lines = [line for line in f]
    n = int(lines[0])
    piastrelle = [int(x) for x in lines[1].split()]

cache = {}
res = solve(0)

with open("output.txt", "w") as f:
    f.write(str(res))