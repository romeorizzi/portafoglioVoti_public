"""
* user:  VR481889
* fname: LORENZO
* lname: MIOSO
* task:  esameincr_subseq_with_drops
* score: 10.0
* date:  2022-07-26 09:19:39.565357
"""
#!/usr/bin/python3


g, n_elements, k = list(map(int, input().split()))

S = list(map(int, input().split()))

def lis_k_drops(S,k):
	colonne = []
	for i in S:
		colonne = incolonna(colonne,i)
	#print(colonne)
	return colonne


def lis_k_drops_len(S,k):
	if k == len(S):
		return k
	if k == 0:
		return len(lis_k_drops(S,k))

	len_k_0 = len(lis_k_drops(S,k))
	if k + len_k_0 > len(S):
		return len(S)
	else:
		return k + len_k_0

	 	
def lis_k_drops_nseq(S,k):
	colonne = lis_k_drops(S,k)
	if k == len(S):
		return 1
	if k == 0:
		reps = count_reps(colonne)
		n_sequences = prod(reps)
		return n_sequences
	else :
		elems = count_elems(colonne)
		n_sequences = prod(elems)
		return n_sequences


def incolonna(colonne,val):
	if not colonne:
		colonne.append([val])
		return colonne
	else:
		for c in colonne:
			if c[len(c)-1] >= val:
				c.append(val)
				return colonne
		colonne.append([val])
		return colonne

def count_reps(colonne):
	reps = [0 for _ in range(len(colonne))]
	for i in range(len(colonne)):
		top = colonne[i][len(colonne[i])-1]
		for j in colonne[i]:
			if j == top:
				reps[i] += 1
	#print(reps)
	return reps

def count_elems(colonne):
	elems = [0 for _ in range(len(colonne))]
	for i in range(len(colonne)):
		elems[i] = len(colonne[i])
	#print(elems)
	return elems

def prod(arr):
	res = 1
	if arr :
		for i in arr:
			res *= i
		return res
	else:
		return 0
	

#print(g, n_elements, k, S)

if g == 1:
	print(lis_k_drops_len(S,k))
if g == 2:
	print(lis_k_drops_nseq(S,k))

