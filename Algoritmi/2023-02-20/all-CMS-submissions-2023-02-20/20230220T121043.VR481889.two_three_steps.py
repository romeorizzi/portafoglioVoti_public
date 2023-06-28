"""
* user:  VR481889
* fname: LORENZO
* lname: MIOSO
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:10:43.095792
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

N = int(input())
quadri = list(map(int,input().split()))

sogni = quadri.copy()
for i in range(N) :
    print(sogni)
    if i % 2 == 0 or i % 3 == 0 :
        for j in range(i) :
            if (i - j) % 2 == 0 or (i - j) % 3 == 0 :
                sogni[i] = max(sogni[i], sogni[i] + sogni[j])

print(max(sogni))
