"""
* user:  VR448339
* fname: FREGNAN
* lname: SEBASTIANO
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 10:31:21.371700
"""
#!usr/bin/env python3
# -*- coding: utf-8 -*-

import sys


def heap_property(i, heap):
	return heap[i] >= heap[(i - 1) // 2]


# heap property must be satisfied for each exuberant values
def check_heap_property(heap, exuberant, n_values):
	for i in range(n_values):
		if exuberant[i] and not heap_property(i, heap):
			return 0
	return 1


def check_good_reallocation(heap, exuberant, fixed, n_values):
	reallocatable_i = []
	for i in range(n_values - 1, 0, -1):
		if not fixed[i]:
			reallocatable_i.append(i)
	
	for i in range(n_values - 1, 0, -1):
		if exuberant[i]:
			if heap_property(i, heap):
				# all's well
				continue
			elif not fixed[(i - 1) // 2]:
				# can change parent
				if not fixed[i]:
					# simply switch parent and child
					temp = heap[i]
					heap[i] = heap[(i - 1) // 2]
					heap[(i - 1) // 2] = temp
				else:
					# must change parent
					j = (i - 1) // 2
					while j >= 0 and fixed[(j - 1) // 2]:
						j = (j - 1) // 2
					if j > 0:
						temp = heap[j]
						heap[j] = heap[(j - 1) // 2]
						heap[(j - 1) // 2] = temp
					else:
						# must search somewhere else
						return 0  # TODO per adesso
			else:
				# must change child
				j = i
				while j > 0 and fixed[(j - 1) // 2]:
					j = (j - 1) // 2
				if j > 0:
					temp = heap[i]
					heap[i] = heap[(i - 1) // 2]
					heap[(i - 1) // 2] = temp
				else:
					# must search somewhere else
					return 0  # TODO per adesso
	return 1


DEBUG = False

if __name__ == '__main__':
	
	if DEBUG:
		sys.stdin = open("input3.txt", "r")
	
	n, t = list(map(int, input().split()))
	x = list(map(int, input().split()))
	e = [e == '1' for e in input().split()]
	f = [f == '1' for f in input().split()]
	
	if t == 1:
		# check heap property
		print(check_heap_property(x, e, n))
	else:
		# check whether exists an F-stable reallocation of A that satisfies heap property
		print(check_good_reallocation(x, e, f, n))
	
	exit(0)
