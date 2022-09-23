"""
* user:  VR479912
* fname: SIMONE
* lname: FERRARI
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 12:18:13.810020
"""
#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**9)

MAXN=100000
MAXM=200000
N, M = map(int,input().strip().split())
assert 0 <= N <= MAXN
assert 0 <= M <= MAXM
#print(f"{N=}, {M=}")

attacchi = []
for arco in range(M):
    u,v = map(int,input().strip().split())
    assert 0 <= u < N
    assert 0 <= v < N
    attacchi.append((u,v,True if arco < N else False))

    #print(f"message={u}, ship={v}")
    
ris = []

def convoiglio(attacchi, fuocoTedeschi, fuocoAmericani, possibileAttacco):
    attacchi=attacchi[:]
    fuocoTedeschi=fuocoTedeschi[:]
    fuocoAmericani=fuocoAmericani[:]
    possibileAttacco=possibileAttacco[:]

    global ris

    if len(attacchi) == 0:
        return False

    if len(possibileAttacco) == N:
        #check
        for att in possibileAttacco:
            if att[2] == False:
                ris = possibileAttacco
                return True

    attacco = attacchi.pop(0)
    #skippo senza tenere
    skipped = convoiglio(attacchi,fuocoTedeschi, fuocoAmericani, possibileAttacco)

    # posso usare l'attacco?
    if fuocoTedeschi[attacco[0]] == False and fuocoAmericani[attacco[1]] == False:
        #si, posso
        fuocoTedeschi[attacco[0]] = True
        fuocoAmericani[attacco[1]] = True
        possibileAttacco.append(attacco)
        keeped = convoiglio(attacchi,fuocoTedeschi, fuocoAmericani, possibileAttacco)
    else:
        keeped = False
    

    return skipped or keeped


fuocoTedeschi = [False] * N
fuocoAmericani = [False] * N

if convoiglio(attacchi, fuocoTedeschi, fuocoAmericani, []):
    result = {}
    for elem in ris:
        result[elem[0]] = elem[1]
    
    keys = sorted(list(result.keys()))
    for key in keys:
        print(f"{key} {result[key]}")
else:
    print(-1)

exit(0)