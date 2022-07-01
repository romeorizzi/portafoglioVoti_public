"""
* user:  VR472006
* fname: JACOPO
* lname: ZAGOLI
* task:  k_up_1_down_seq
* score: 47.0
* date:  2022-06-29 13:05:49.371663
"""
#!/usr/bin/env python3

G = 0
N = 0
K = 0
R = 0
findme = ""
all_lista = []

mem = {}

def num_seq(last,lev):
    if (last, lev) in mem:
        return mem[(last,lev)]
    if (lev == 0):
        if(last == 0):
            return 1
        else:
            return 0
    mem[(last,lev)] = (num_seq(last, lev-1)+ (num_seq(last-1, lev-1) if last > 0 else 0)+ num_seq(last + K, lev-1))% 1000000007
    return mem[(last,lev)]

def unranking():
    lista(0, N-1, "")
    return all_lista[R]

def ranking():
    lista(0, N-1, "")
    return all_lista.index(findme)


def lista(last, lev, stri):
    global all_lista
    if (lev != 0):
        if last > 0:
            lista(last-1, lev-1, stri + " " + str(last-1))
        lista(last, lev-1, stri + " " +  str(last))
        lista(last + K, lev-1, stri +  " " + str(last+K))
    else:
            if(last == 0):
                all_lista.append("0"+stri)


vec = input().split()
G = int(vec[0])
N = int(vec[1])
K = int(vec[2])
    

if G == 1:
    print(num_seq(0,N-1))
if G == 4:
    lista(0, N-1, "")
    for l in all_lista:
        print(l)
if G == 2:
    R = int(input())
    print(unranking())
if G == 3:
    findme = input()
    print(ranking())
