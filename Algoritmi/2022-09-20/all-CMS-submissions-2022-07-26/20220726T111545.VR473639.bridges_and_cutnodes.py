"""
* user:  VR473639
* fname: ANDREA
* lname: CINELLI
* task:  esamebridges_and_cutnodes
* score: 0.0
* date:  2022-07-26 11:15:45.601121
"""
t, n, m = map(int, input().strip().split())


n_comp = [0] + [1] * (n - 1)
brid = [False] * m

edg = {}

# Per ogni vertice salvo a quali vertici è connesso
v_conn = [ [] for v in range(n)]
for i in range(m):
    u,v = map(int, input().strip().split())
    v_conn[u].append(v)
    v_conn[v].append(u)
    edg[(u, v)] = i
    edg[(v, u)] = i


time = 1
low = [None] * n
discorvery_t = [None] * n

def dfs(h, v, dad):
    global time, discorvery_t, low, brid, n_comp
    assert h <= n

    low[v] = discorvery_t[v] = time
    time += 1
    
    n_ch_v = 0
    for z in v_conn[v]:
        if discorvery_t[z] == None:
            n_ch_v += 1
            dfs(h + 1, z, v)

            low[v] = min(low[v], low[z])
            if low[z] > discorvery_t[v]:
                brid[edg[(v, z)]] = True
            if low[z] >= discorvery_t[v]:
                n_comp[v] += 1
            
        elif z != dad:
            low[v] = min(low[v], discorvery_t[z])
    assert low[v] <= discorvery_t[v]
    if v == 0:
        assert n_comp[v] == n_ch_v

dfs(0, 0, 0)

assert n<=20

if t == 1:
    for e_index in range(m):
        if bridges[e_index]:
            print(1)
        else:
            print(0)
if t == 2:
    for v in range(n):
        if num_components[v] > 1:
            print(1)
        else:
            print(0)