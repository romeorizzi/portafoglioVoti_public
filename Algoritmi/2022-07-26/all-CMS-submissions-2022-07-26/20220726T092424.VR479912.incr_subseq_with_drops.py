"""
* user:  VR479912
* fname: SIMONE
* lname: FERRARI
* task:  esameincr_subseq_with_drops
* score: 10.0
* date:  2022-07-26 09:24:24.714150
"""
#! /usr/bin/env python3

def getInput():
    g,n,k = map(int, input().split())
    S = list(map(int, input().split()))
    #print(f"{g}, {n}, {k}")
    #print(f"{S}")
    assert 1 <= g <= 2
    assert 0 <= n <= 100
    assert k >= 0
    assert len(S) == n
    return g, n, k, S

def canIkeep(k, prec, act):
    if prec == None:
        #print("NONE")
        return True, False

    if prec < act:
        #print("prec < act")
        return True, False
    else:
        #print("prec >= act")
        if k > 0:
            #print("\tk > 0")
            return True, True
        else:
            #print("\tk <= 0")
            return False, False

def incr_subseq_with_drops(n, k, S, prec, nSol):
    sx = 0
    dx = 0
    Scp = S[:]

    # Caso base (len == 0)
    if n == 0 or len(S) == 0:
        #print(f"CASO BASE, {n}=={len(S)}==0")
        return 0
    
    # Ricorsione: 2 casi: tengo o skippo
    act = Scp.pop(0)
    #print(f"\n\nact={act}, prec={prec}")

    # Posso tenere?
    result, kChanged = canIkeep(k=k, prec=prec, act=act)
    #print(f"result={result}, kChanged={kChanged}")
    if result == True:
        # Se si, sx = 1 + ricorsione
        if kChanged == True:
            sx = 1 + incr_subseq_with_drops(n=n-1, k=k-1, S=Scp, prec=act, nSol=nSol)
        else:
            sx = 1 + incr_subseq_with_drops(n=n-1, k=k, S=Scp, prec=act, nSol=nSol)

    # Skippo
    # dx = ricorsione senza tenere
    dx = 0 + incr_subseq_with_drops(n=n-1, k=k, S=Scp, prec=prec, nSol=nSol)

    #print(f"sx={sx}, dx={dx}")
    
    sol = max(sx, dx)

    if sol > nSol[1]:
        nSol[1] = sol
        nSol[0] = 1
    elif sol == nSol[1]:
        nSol[0] += 1

    return max(sx, dx)
        
nSol = [0, 0]
g, n, k, S = getInput()
finalRes = incr_subseq_with_drops(n=n, k=k, S=S, prec=None, nSol=nSol)

if g == 1:
    print(finalRes)
else:
    print(nSol[0])

#print(f"{finalRes, nSol}")