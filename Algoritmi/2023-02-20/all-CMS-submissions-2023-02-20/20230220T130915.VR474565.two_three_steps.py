"""
* user:  VR474565
* fname: MATTIA
* lname: SANTI
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 13:09:15.527166
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

with open('input.txt') as f:
	n = int(f.readline())
	val = list(map(int,f.readline().split())) #Array contenete il val del ricordo i

somma_max =  [0 for _ in range(n)] #Array somme max i-esime

somma_max[n-1] = val[n-1]
#Casi base
if(n >= 2):
	somma_max[n-2] = val[n-2]
if(n >= 3):
	somma_max[n-3] = val[n-3] + val[n-1]

for i in range(n-4, -1, -1):
	somma_max[i] = val[i] + max(somma_max[i+2], somma_max[i+3]);

with open('output.txt', 'w') as f:
    f.write(somma_max[0])

    
