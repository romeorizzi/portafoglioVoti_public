"""
* user:  VR481889
* fname: LORENZO
* lname: MIOSO
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:22:04.330130
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

N = int(input())
quadri = list(map(int,input().split()))
#print(quadri)

sogni = [0] * N
for i in range(N) :
    if i % 2 == 0 or i % 3 == 0 or i % 5 == 0 :
        for j in range(i) :
            if (i - j) % 2 == 0 or (i - j) % 3 == 0 :
                sogni[i] = max(sogni[i], sogni[j] + quadri[i])
    #print(sogni)
        

print(max(sogni))
