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
    N,C,R, U = map(int, input().split())
    soluz = []
    ord(N, '')

    if C == 1:
        print(len(soluz))
    if R > 0:
        soluz_rank = ''
        for r in range(R):
            mat = input().replace('\n','')
            for i in range(len(soluz)):
                if soluz[i] == mat:
                    print(i)
                    break
    if U>0:
        for u in range(U):
            print(soluz[int(input())])