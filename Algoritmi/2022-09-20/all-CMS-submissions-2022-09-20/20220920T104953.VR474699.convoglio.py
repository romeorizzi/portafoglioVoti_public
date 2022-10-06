"""
* user:  VR474699
* fname: ALESSANDRO
* lname: RODEGHERO
* task:  esame_convoglio
* score: 15.0
* date:  2022-09-20 10:49:53.370087
"""
import sys
sys.setrecursionlimit(10**9)

MAXN=100000
MAXM=200000
p = []
a = []

N, M = map(int,input().strip().split())
assert 0 <= N <= MAXN
assert 0 <= M <= MAXM
#print(f"{N=}, {M=}")
for i in range(M):
    u,v = map(int,input().strip().split())
    assert 0 <= u < N
    assert 0 <= v < N
    #print(f"message={u}, ship={v}")
    p.append(u)
    a.append(v)
n = N
m = M

def build(c,d):
    lista = []
    for i in range(len(c)):
        lista.append([c[i], d[i]])
    lista.sort()
    return lista

prima_sol = build(p[:n],a[:n])
res = -1

a.reverse()
p.reverse()

for i in range(m-n):
    pa = p[i]
    aa = a[i]
    sol_p = [pa]
    sol_a = [aa]
    for j in range(m):
        if p[j] not in sol_p and a[j] not in sol_a:
            sol_p.append(p[j])
            sol_a.append(a[j])
            if len(sol_a) == n: break

    if len(sol_a) == n:
        controllo = build(sol_p, sol_a)
        controllo.sort()
        if controllo != prima_sol:
            res = controllo
            break


if res == -1:
    print(res)
else:             
    for r in res:
        print(r[0],r[1])        

exit(0)