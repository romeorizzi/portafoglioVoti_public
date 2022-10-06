"""
* user:  VR474699
* fname: ALESSANDRO
* lname: RODEGHERO
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 09:20:36.475744
"""
import sys
ino = input()
ino = ino.split('\n')

n = int(ino[0].split(' ')[0])
m = int(ino[0].split(' ')[1])
p = []
a = []

for i in ino[1:]:
    if len(i) > 0:
        tmp = i.split(' ')
        p.append(int(tmp[0]))
        a.append(int(tmp[1]))


def build(c,d):
    lista = []
    for i in range(len(c)):
        lista.append([c[i], d[i]])
    lista.sort()
    return lista

prima_sol = build(p[:n],a[:n])
res = -1

for i in range(m):
    pa = p[i]
    aa = a[i]
    sol_p = [pa]
    sol_a = [aa]
    for j in range(m):
        if p[j] not in sol_p and a[j] not in sol_a:
            sol_p.append(p[j])
            sol_a.append(a[j])

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