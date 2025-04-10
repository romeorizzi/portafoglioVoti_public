"""
* user:  VR459645
* fname: FRANCESCA
* lname: ANNIBALETTI
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 13:22:39.267778
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

MAXN=100000
MEMO_risp=[None]*(MAXN+1)

# Funzione ricorsiva che calcola il massimo dei ricordi
def max_ricordi(n, ricordi, i):
	if i > n-1: 
		return 0
	if MEMO_risp[i]==None:
		MEMO_risp[i]= ricordi[i] + max(MEMO_risp[i+2],MEMO_risp[i+3])
	return MEMO_risp[i]
		

# Leggi il file di input
with open('input.txt', 'r') as f:
	N = map(int, f.readline().split())
	n=N[0]
	ricordi= map(int, f.readline().split(" "))

a=max_ricordi(n, ricordi, 0)

# Scrivi il file di output
with open('output.txt', 'w') as f:
	f.write(str(a))
	f.close()
