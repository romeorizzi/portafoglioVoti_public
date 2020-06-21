"""
* user:  VR424867
* fname: CONSOLARO
* lname: GIANPIETRO
* task:  bit_edit_to_zero
* score: 0.0
* date:  2019-02-26 09:30:20.381859
"""
def lsp(n):
    return n & (-n)

def potenza_2(n):
    return n == lsp(n)

def nmosse_p_2(n):
    assert potenza_2(n)
    return 2*n-1

def numero_uni(n):
    if n==0:
        return 0
    return 1+numero_uni(n-lsp(n))

def nmosse(n):
    if n==0:
        return 0
    if numero_uni(n)%2 ==1:
        if n%2 ==1:
            return 1 + nmosse(n-1)
        else:
            return 1+nmosse(n+1)
    if lsp(n-lsp(n))==2*lsp(n):
        return 1+nmosse(n-2*lsp(n))
    else:
        return 1+nmosse(n + 2*lsp(n))
    
def mossa(n):
    assert n>0
    if numero_uni(n) %2 ==1:
        return 1
    else:
        return 2