"""
* user:  VR472347
* fname: MATTEO
* lname: GRELLA
* task:  esamebridges_and_cutnodes
* score: 32.0
* date:  2022-07-26 11:45:42.333931
"""
import sys
sys.setrecursionlimit(10**9)

t, n, m = map(int, input().strip().split())

bridges = [False] * m
num_components = [0] + [1] * (n - 1)

edges = {}
nei = [ [] for v in range(n)]
for i in range(m):
	u,v = map(int, input().strip().split())
	nei[u].append(v)
	nei[v].append(u)
	edges[(u, v)] = i
	edges[(v, u)] = i


time = 1
opent = [None] * n
low = [None] * n

def dfs(h, v, dad):
	global time, opent, low, bridges, num_components
	assert h <= n

	low[v] = opent[v] = time
	time += 1
	num_children_v = 0
	for z in nei[v]:
		if opent[z] == None:
			num_children_v += 1
			dfs(h + 1, z, v)
			low[v] = min(low[v], low[z])
			if low[z] > opent[v]:
				bridges[edges[(v, z)]] = True
			if low[z] >= opent[v]:
				num_components[v] += 1
		elif z != dad:
			low[v] = min(low[v], opent[z])
	assert low[v] <= opent[v]
	if v == 0:
		assert num_components[v] == num_children_v

dfs(0, 0, 0)

for e_index in range(m):
	print(1) if bridges[e_index] else print(0)
    