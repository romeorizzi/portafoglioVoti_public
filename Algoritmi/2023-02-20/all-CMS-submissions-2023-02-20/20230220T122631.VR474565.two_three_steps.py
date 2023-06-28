"""
* user:  VR474565
* fname: MATTIA
* lname: SANTI
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:26:31.322207
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-
N = int(input())

GGG = [0 for _ in range(N)] #Array contenete il val del ricordo i
somma_max =  [0 for _ in range(N)] #Array somme max i-esime

GGG = list(map(int,input().strip().split()))

somma_max[N-1] = GGG[N-1]
#Casi base
if( N >= 2):
	somma_max[N-2] = GGG[N-2]
if(N >= 3):
	somma_max[N-3] = GGG[N-3] + GGG[N-1]

for i in range(N-4, -1, -1):
	somma_max[i] = GGG[i] + max(somma_max[i+2], somma_max[i+3]);

print(somma_max[0])

