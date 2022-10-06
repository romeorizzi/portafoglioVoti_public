"""
* user:  VR472500
* fname: MATTEO
* lname: MARJANOVIC
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 10:42:33.273017
"""
#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**9)

def convoglio(N, lev, nodes, const):
    assert lev >= 0 and lev <= N
    #print(N, lev, nodes, const)
    res = []
    for c in const:
        #print("sono quiiis")
        if c[0] == lev and c[1] in nodes:
            #print("sono qui")
            tmp = nodes[:]
            tmp.remove(c[1])
            ric = convoglio(N, lev+1, tmp, const)
            if lev == N-1:
                res.append([f"{lev} {c[1]}"])
            else:
                for r in ric:
                    res.append([f"{lev} {c[1]}"] + r)
        else:
            continue
    #print("RES", res)

    return res

MAXN=100000
MAXM=200000
N, M = map(int,input().strip().split())
assert 0 <= N <= MAXN
assert 0 <= M <= MAXM
print(f"{N}, {M}")
const = []
for i in range(M):
    u,v = map(int,input().strip().split())
    assert 0 <= u < N
    assert 0 <= v < N
    # print(f"message={u}, ship={v}")
    const.append([u, v])
turing = [f"{el[0]} {el[1]}" for el in const[:N]]
nodes = [i for i in range(N)]
    
result = convoglio(N, 0, nodes, const)
if len(result) == 1 and result[0] == turing:
    print(-1)
else:
    for r in result:
        if r != turing:
            for line in r:
                print(line)
            break

exit(0)
