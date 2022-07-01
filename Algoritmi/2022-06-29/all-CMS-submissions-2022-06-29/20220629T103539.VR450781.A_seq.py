"""
* user:  VR450781
* fname: MARIN
* lname: JEREGHI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 10:35:39.868706
"""
#!/usr/bin/env python3

def find_inc(start,l):
	# given start index count the len of ascending sequence
	count = 0
	last_seen = l[start]
	# print(start,last_seen)
	lenght = range(start+1, len(l),+1)
	for ind in lenght:
		# print(l[ind], l[start],l[ind] > l[start])
		if l[ind] > last_seen:
			count += 1
			last_seen = l[ind]
		else:
		 	return count
	return count

def find_desc(start,l):
	count = 1
	last_seen = l[start]
	lenght = range(start+1, len(l),+1)
	for ind in lenght:
		if l[ind] < last_seen:
			count += 1
			last_seen = l[ind]
		else:
			return count
	return count

def max_inc(l):
	s0 = l[0]
	m_inc = 1
	for i in range(len(l)):
		print("find \t", i)
		c = find_inc(i,l)
		print("count = ",c)


def max_len(sep, last, index, rising):
	if index >= len(sep):
		return 0
	res_excluded = max_len(sep, last, index+1, rising)
	if (not rising and sep[index] >= last) or (sep[index] == last):
		return res_excluded
	res_included = 1 + max_len(sep,sep[index], index+1, sep[index]>last)
	return  max(res_excluded, res_included)

def f_s(seq, cord, last, index, count, rising):
	if count == cord:
		return 1
	if index >= len(seq):
		return 0
	res_excluded = f_s(seq,cord,last,index+1,count,rising)
	if (not rising and seq[index] >= last) or seq[index] == last:
		return res_excluded

	res_included = f_s(seq,cord, seq[index], index+1, count+1, seq[index]>last)
	return res_excluded + res_included


if __name__ == "__main__":
	s = []
	q = 1
	n = 1
	# print('aa',input().strip().split())
	# print('bb',input().strip().split())
	with open('input.txt') as f_in:
		lines = map(int,f_in.readline().strip().split())
		# s = [line.rstrip().split() for line in lines]
		# q = lines[0]
		# n = lines[1]
		s = map(int,f_in.readline().strip().split())
	#s = [0, 9, 8, 5, 2, 1, 4, 7]
	#s = [3,3,3,3,3]
	s1 = list(s)
	#print(n,q,s1)
	#m = max_len(s1,-1,0,True)
	assert 1 <= len(s1) <= 10000
	
	g = 1
	for i in range(len(s1)):
		incs = find_inc(i,s1)
		if incs>0:
			desc = find_desc(i+incs,s1)
			if g<desc+incs:
				g = desc+incs
	
	#print(g)
	with open('output.txt','w') as f_out:
		f_out.write(str(g))

	# desc = find_desc(6,s1)
	# incs = find_inc(6,s1)
	# print(desc, incs)

	#print(m)
	#res = f_s(s1,m,-1,0,0, True)

