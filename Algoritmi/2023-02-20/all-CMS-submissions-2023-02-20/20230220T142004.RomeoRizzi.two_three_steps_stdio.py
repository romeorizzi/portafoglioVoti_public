"""
* user:  RomeoRizzi
* fname: Romeo
* lname: Rizzi
* task:  esame_two_three_steps_stdio
* score: 0.0
* date:  2023-02-20 14:20:04.853399
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

n = int(input())
val = map(int,input().split())

dyn = [0,0,0]
for i in reversed(range(n)):
    dyn[i%3] = val[i] + max(dyn[(i+2)%3], dyn[i%3])

print(dyn[0])

    
