"""
* user:  VR481889
* fname: LORENZO
* lname: MIOSO
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:36:29.801579
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

f_in = open("input.txt", "r")
f_out = open("output.txt", "w")
#f_in = open("input0.txt", "r")
#f_out = open("output0.txt", "w")


N = int(f_in.readline())
quadri = list(map(int,f_in.readline().split()))
#print(quadri)

sogni = [0] * N
for i in range(N) :
    #if i % 2 == 0 or i % 3 == 0 or i % 5 == 0 :
    for j in range(i) :
        if (i - j) >= 2:
            sogni[i] = max(sogni[i], sogni[j] + quadri[i])
    #print(sogni)
        

#print(str(max(sogni)))
f_out.write(str(max(sogni)))
