"""
* user:  VR472347
* fname: MATTEO
* lname: GRELLA
* task:  esameincr_subseq_with_drops
* score: 50.0
* date:  2022-07-26 12:22:14.121707
"""
from functools import lru_cache

g, n, k = map(int, input().split())
seq = list(map(int, input().split()))

@lru_cache(maxsize = None)
def maxseq(index, prev, k):
	global seq
	if index >= n:
		return 1
	take = 0
	take_wrong = 0
	if seq[index] > prev:
		take = 1 + maxseq(index+1, seq[index], k)
	leave = maxseq(index+1, prev, k)
	if k > 0 and seq[index] <= prev:
		take_wrong = 1 + maxseq(index+1, seq[index], k - 1)
	return max(take, leave, take_wrong)

@lru_cache(maxsize = None)
def n_best_sol(index, prev, k, equals):
	return1

if g == 1:
	n_max = 0
	for i in range(1,n):
		if n_max>n-i:
			break
		n_max = max(n_max, maxseq(i, seq[i-1], k))

	print(n_max)
	
if g == 2:

	print(n_seq_max)