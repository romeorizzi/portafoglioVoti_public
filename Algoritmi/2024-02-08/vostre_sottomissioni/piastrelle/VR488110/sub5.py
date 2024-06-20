import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)

def ord(N, sol):
    if N-1 >=0:
        ord(N-1, f'{sol}[]')
    if N-2 >=0:
        ord(N-2, f'{sol}[--]')
    if N == 0:
        soluz.append(sol)

T = int(input())
for t in range(T):
    N,C,R,U = map(int, input().split())
    soluz = []
    ord(N, '')

    if C == 1:
        a = 0
        b = 1
        c = 0
        for i in range(N):
            c = a+b
            a = b
            b = c
        print(c)
    
    soluz = []
    if R>0 or U>0:
        ord(N,'')

    if R > 0:
        soluz_rank = [0]*R
        dic = {}
        for r in range(R):
            dic[input().replace('\n', '')] = r
        for i in range(len(soluz)):
            if soluz[i] in dic:
                soluz_rank[dic[soluz[i]]] = i
        for i in soluz_rank:
            print(i)
    if U>0:
        for u in range(U):
            print(soluz[int(input())])