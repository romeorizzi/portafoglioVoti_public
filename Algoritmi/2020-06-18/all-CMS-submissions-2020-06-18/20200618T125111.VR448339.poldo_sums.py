"""
* user:  VR448339
* fname: FREGNAN
* lname: SEBASTIANO
* task:  poldo_sums
* score: 59.0
* date:  2020-06-18 12:51:11.512185
"""
#!usr/bin/env python3
# -*- coding: utf-8 -*-

import sys


def prefix_sum(array):
	ps = [0] * (len(array) + 1)
	for i in range(len(array)):
		ps[i + 1] = array[i] + ps[i]
	return ps


# in pratica ritorna gli indici dei panini che può mangiare tenendo conto che tra un panino e l'altro deve andare in
# palestra e soprattutto che il prossimo panino che mangia deve essere almeno quello precedente + tutti gli sforzi
# fatti in palestra, così da essere in forze per il prossimo panino
def poldo_sums(n, pan, gym):
	ps = prefix_sum(gym)
	
	best = [0] * n
	longest = [1] * n
	
	best_m = 0
	best_i = 0
	
	for j in range(n):
		best[j] = j
		for i in range(j):
			tot = pan[j] - (pan[i] + ps[j] - ps[i])
			if tot >= 0:
				if longest[j] <= longest[i] + 1:
					best[j] = i
					longest[j] = longest[i] + 1
				if longest[j] > best_m:
					best_m = longest[j]
					best_i = j
	
	best_seq = []
	while 0 <= best_i:
		best_seq.append(best_i)
		if best_i == best[best_i]:
			break
		best_i = best[best_i]
	return best_m, list(map(str, reversed(best_seq)))


DEBUG = False

if __name__ == '__main__':
	
	if DEBUG:
		sys.stdin = open("input1.txt", "r")
	
	n = int(input().strip())
	pan = [0] * n
	gym = [0] * n
	for i in range(n):
		pan[i], gym[i] = map(int, input().split())
	
	m, seq = poldo_sums(n, pan, gym)
	
	print(m)
	print(" ".join(seq))
	
	exit(0)
