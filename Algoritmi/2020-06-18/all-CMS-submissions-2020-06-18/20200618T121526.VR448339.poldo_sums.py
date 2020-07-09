"""
* user:  VR448339
* fname: FREGNAN
* lname: SEBASTIANO
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 12:15:26.760631
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
	
	for j in range(n):
		best_val = pan[j]
		best[j] = j
		for i in range(j):
			tot = pan[j] - (pan[i] + ps[j] - ps[i])
			if best_val < tot:
				best_val = tot
				best[j] = i
	
	best_seq = []
	best_m = 0
	for j in range(n - 1, 0, -1):
		i = j
		curr_seq = [i]
		curr_m = 1
		while 0 <= i != best[i]:
			i = best[i]
			curr_seq.append(i)
			curr_m += 1
		if curr_m >= best_m:
			best_seq = curr_seq
			best_m = curr_m
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
