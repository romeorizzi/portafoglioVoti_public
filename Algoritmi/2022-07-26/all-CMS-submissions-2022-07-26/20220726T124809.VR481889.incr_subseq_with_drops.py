"""
* user:  VR481889
* fname: LORENZO
* lname: MIOSO
* task:  esameincr_subseq_with_drops
* score: 50.0
* date:  2022-07-26 12:48:09.636622
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

	 	
def lis_k_drops_nseq(S,k):
	colonne = lis_k_drops(S,k)
	if k == len(S):
		return 1
	if k == 0:
		reps = count_reps(colonne)
		n_sequences = sum(reps)
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
	for i in range(len(reps)):
		if reps[i] == 1:
			reps[i] = 0
	#print(reps)
	return reps

def count_elems(colonne):
	elems = [0 for _ in range(len(colonne))]
	for i in range(len(colonne)):
		elems[i] = len(colonne[i])
	#print(elems)
	return elems

def lis(S):
	res = [1 for _ in range(len(S))]
	for i in range(len(S)):
		i_val = S[i]
		for j in range(i):
			if i_val > S[j] :
				res[i] = res[j] + 1
	return res

def lis_on_n_seq(S):
	res = 0
	for i in S:
		#print(i)
		n = lis_0_drops(i)
		res += n
		#print(n)

	#print(res)	
	return res
		

def lis_0_drops(S):
	return len(lis_k_drops(S,0))

def lis_1_drops(S):
	best_val = 0
	for i in range(1, len(S)):
		#res1 = max(lis(S[:i]))
		#res2 = max(lis(S[i:]))
		res1 = len(lis_k_drops(S[:i],0))
		res2 = len(lis_k_drops(S[i:],0))
		#print(res1, res2)
		#print(lis(S[:i]), lis(S[i:]), res1 + res2)
		best_val = max(best_val, res1 + res2)
	#print(best_val)
	return best_val

def drops(S):
	lis0 = len(lis_k_drops(S,0))
	drops = []
	for i in range(1, len(S)):
		#res1 = max(lis(S[:i]))
		#res2 = max(lis(S[i:]))
		res1 = len(lis_k_drops(S[:i],0))
		res2 = len(lis_k_drops(S[i:],0))
		#print(res1, res2)
		#print(lis(S[:i]), lis(S[i:]), res1 + res2)
		if res1 + res2 > lis0:
			drops.append((i,res1+res2-lis0))
	
	#print(drops)
	return drops

def best_drop(S):
	lis0 = len(lis_k_drops(S,0))
	best_drop_idx = -1
	best_drop_val = 0
	for i in range(1, len(S)):
		#res1 = max(lis(S[:i]))
		#res2 = max(lis(S[i:]))
		res1 = len(lis_k_drops(S[:i],0))
		res2 = len(lis_k_drops(S[i:],0))
		#print(res1, res2)
		#print(lis(S[:i]), lis(S[i:]), res1 + res2)
		if res1 + res2 > lis0 and res1 + res2 - lis0 > best_drop_val:
			best_drop_idx = i
			best_drop_val = res1 + res2 - lis0
	
	return (best_drop_idx, best_drop_val)


def best_drop_multi(S):

	best_drop_idx_seq = -1
	best_drop_idx_elem = -1
	best_drop_val = 0
	for i in range(len(S)):
		idx, val = best_drop(S[i])
		if val > best_drop_val:
			best_drop_idx_seq = i
			best_drop_idx_elem = idx
			best_drop_val = val

	return (best_drop_idx_seq, best_drop_idx_elem,best_drop_val)

def lis_k_drops_len(S,k):
	if k == len(S):
		return k
	if k == 0:
		return lis_0_drops(S)
	else:
		S = [S]
		while k > 0:
			#print(S)
			idx1, idx2, val = best_drop_multi(S)
			if idx1 == -1:
				break
			#print(best_drop_multi(S))
			S = split(S, idx1, idx2)
			k -= 1
		return(lis_on_n_seq(S))
			
			

def prod(arr):
	res = 1
	if arr :
		for i in arr:
			res *= i
		return res
	else:
		return 0

def split(arr, idx1, idx2):
	first_half = arr[:idx1]
	middle = arr[idx1]
	second_half = arr[idx1+1:]
	return first_half + [middle[:idx2] ,middle[idx2:]] + second_half
	
	

#print(g, n_elements, k, S)
#print(lis_1_drop(S))
#print(lis_on_n_seq([[1,2,3],[2,2,2]]))
#S = [S]
#print(S)
#idx1, idx2, val = best_drop_multi(S)
#print(best_drop_multi(S))
#S = split(S, idx1, idx2)
#print(S)
#print(lis_on_n_seq(S))


#print(best_drop(S))
#print(split(S,2))

if g == 1:
	print(lis_k_drops_len(S,k))
if g == 2:
 	print(lis_k_drops_nseq(S,k))

