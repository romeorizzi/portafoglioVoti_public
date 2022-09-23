"""
* user:  VR472500
* fname: MATTEO
* lname: MARJANOVIC
* task:  esame_convoglio
* score: 15.0
* date:  2022-09-20 11:35:38.764529
"""
#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**9)

def convoglio(N, lev, nodes, const):
    assert lev >= 0 and lev <= N
    if str(nodes) in MEMO:
        return MEMO[str(nodes)]
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
    MEMO[str(nodes)] = res
    return res

MEMO = {}

MAXN=100000
MAXM=200000
N, M = map(int,input().strip().split())
assert 0 <= N <= MAXN
assert 0 <= M <= MAXM
# print(f"{N}, {M}")
const = []
for i in range(M):
    u,v = map(int,input().strip().split())
    assert 0 <= u < N
    assert 0 <= v < N
    # print(f"message={u}, ship={v}")
    const.append([u, v])
turing = set([f"{el[0]} {el[1]}" for el in const[:N]])
nodes = [i for i in range(N)]
    
result = convoglio(N, 0, nodes, const)
if len(result) == 1 and set(result[0]) == turing:
    print(-1)
else:
    for r in result:
        same = True
    #     for line in r:
    #         if line not in turing:
    #             same = False
    #             break
    #     if not same:
    #         for line in r:
    #             print(line)
    #         break
    # if same:
    #     print(-1)
        if set(r) != turing:
            same = False
            for line in r:
                print(line)
            break
    if same:
        print(-1)

exit(0)
