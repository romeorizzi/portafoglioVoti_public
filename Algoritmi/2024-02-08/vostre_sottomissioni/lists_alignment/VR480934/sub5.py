import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)

trace = [0][0]
def find_sublists_and_payoff(U,D):
    n = len(U) 
    m = len(D)
    trace = [[(0, 0) for _ in range(m+1)] for __ in range(n+1)]
    gain = [[0 for _ in range(m+1)] for __ in range(n+1)]
    for i in range(1, n+1):
        for j in range(1, m+1):
            if gain[i-1][j] > gain[i][j-1]:
                gain[i][j] = gain[i-1][j]
                trace[i][j] = (i-1, j)
            else:
                gain[i][j] = gain[i][j-1]
                trace[i][j] = (i, j-1)

            current_payoff = gain[i-1][j-1] + min(U[i-1], D[j-1])
            if current_payoff > gain[i][j]:
                gain[i][j] = current_payoff
                trace[i][j] = (i-1, j-1)
            
    U_first, D_first = [], []
    i, j = n, m
    while i > 0 and j > 0:
        if trace[i][j] == (i-1, j-1):
            U_first.append(U[i-1])
            D_first.append(D[j-1])
        (i,j) = trace[i][j]
    U_first.reverse()
    D_first.reverse()

    return gain[n][m], U_first, D_first

T = int(input().strip())
for _ in range(T):
    input()
    U = list(map(int,input().strip().split()))
    D = list(map(int,input().strip().split()))

    valore, U_first, D_first = find_sublists_and_payoff(U, D)
    print(valore)
    for u in U_first:
        print(u, end=' ')
    print()
    for d in D_first:
        print(d, end=' ')
    print()
