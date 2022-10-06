"""
* user:  VR477605
* fname: LORENZO
* lname: TABARELLI
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 11:45:10.045784
"""
#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**9)

def biunivoca(m, ships, more_messages, start, victim, res, cicle):
    #print(f"Start: {start}, Victim: {victim}")
    if start == victim:
        return res
    elif len(more_messages) == 0:
        return -1
    for more in more_messages:
        if more[0]==m[0]:
            victim = int(ships[m[0]])
            res.append(more)
            tmp = more_messages.copy()
            tmp.remove(more)
            return biunivoca([victim, m[0]],ships,  tmp, start, victim, res, cicle)



MAXN=100000
MAXM=200000
N, M = map(int,input().strip().split())
assert 0 <= N <= MAXN
assert 0 <= M <= MAXM
#print(f"{N=}, {M=}")
message=[]
messages={}
ships={}
more_messages=[]


for i in range(M):
    u,v = map(int,input().strip().split())
    assert 0 <= u < N
    assert 0 <= v < N
    #print(f"message={u}, ship={v}")
    if i < N:
        message.append([u,v])
        messages[u]=v
        ships[v]=u
    else:
        more_messages.append([u,v])
    
for m in message:
    res = biunivoca(m, ships, more_messages, m[1], None, [], False)
    if res != -1:
        for r in res:
            messages[r[0]]=r[1]
        break

for key in messages:
    print(key, messages[key])
    
exit(0)