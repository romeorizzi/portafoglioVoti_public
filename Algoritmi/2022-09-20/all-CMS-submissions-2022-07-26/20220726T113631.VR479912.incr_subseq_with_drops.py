"""
* user:  VR479912
* fname: SIMONE
* lname: FERRARI
* task:  esameincr_subseq_with_drops
* score: 20.0
* date:  2022-07-26 11:36:31.417058
"""
#! /usr/bin/env python3

MEMO = [None] * (100+1)

def getInput():
    g,n,k = map(int, input().split())
    S = list(map(int, input().split()))
    assert 1 <= g <= 2
    assert 0 <= n <= 100
    assert k >= 0
    assert len(S) == n
    return g, n, k, S

nSol = [0, 0]
g, n, k, S = getInput()

def canIkeep(k, prec, act):
    if prec == None:
        return True, False

    if prec < act:
        return True, False
    else:
        if k > 0:
            return True, True
        else:
            return False, False

def incr_subseq_with_drops(n, k, S, prec, nSol, count):
    sx = 0
    dx = 0
    Scp = S[:]

    #if MEMO[n] != None:
    #    print(MEMO[:10])
    #    return MEMO[n]

    # Caso base (len == 0)
    if n == 0 or len(S) == 0:
        if count == nSol[1]:
            nSol[0] += 1
        elif count >= nSol[1]:
            nSol[1] = count
            nSol[0] = 1

        return 0
    
    # Ricorsione: 2 casi: tengo o skippo
    act = Scp.pop(0)

    # Posso tenere?
    result, kChanged = canIkeep(k=k, prec=prec, act=act)

    if result == True:
        # Se si, sx = 1 + ricorsione
        if kChanged == True:
            sx = 1 + incr_subseq_with_drops(n=n-1, k=k-1, S=Scp, prec=act, nSol=nSol, count=count+1)
        else:
            sx = 1 + incr_subseq_with_drops(n=n-1, k=k, S=Scp, prec=act, nSol=nSol, count=count+1)
    
    # Skippo
    # dx = ricorsione senza tenere
    dx = 0 + incr_subseq_with_drops(n=n-1, k=k, S=Scp, prec=prec, nSol=nSol, count=count)    

    #MEMO[n] = max(sx, dx)

    return max(sx, dx)
        
finalRes = incr_subseq_with_drops(n=n, k=k, S=S, prec=None, nSol=nSol, count=0)

if g == 1:
    print(finalRes)
else:
    print(nSol[0]%10000007)