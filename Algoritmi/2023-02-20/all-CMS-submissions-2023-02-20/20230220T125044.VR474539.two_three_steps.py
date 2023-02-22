"""
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:50:44.269792
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

N = int(input())
GGG = list(map(int,input().split()))

def sol(i):
    if i + 2 < N and i + 3 < N:
        return GGG[i] + max(sol(i + 2), sol(i + 3))
    if i + 2 < N:
        return GGG[i] + sol(i + 2)
    if i + 3 < N:
        return GGG[i] + sol(i + 3)
    else:
        return GGG[i]

print(sol(0))
