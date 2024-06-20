def lists_alignment(U, D): #Prendo U e D 
    n = len(U)
    m = len(D)

    DP = [[0 for _ in range(m+1)] for _ in range(n+1)] #Inizializzo a 0

    #Calcolo dei valori matrice DP

    for i in range(1, n+1):
        for j in range(1, m+1):

            DP[i][j] = max(DP[i][j], DP[i-1][j-1] + min (U[i-1], D[j-1]), DP[i-1][j], DP[i][j-1])

    #Ricostruisco sottosequenze ottimali 

    i, j = n, m 
    U_prime, D_prime = [],[]

    while i > 0 and j > 0:
        if DP[i][j] == DP[i-1][j-1] + min(U[i-1], D[j-1]):
            U_prime.append(U[i-1])
            D_prime.append(D[j-1])
            i -= 1
            j -= 1
        elif DP[i][j] == DP[i-1][j]:
            i -= 1
        else:
            j -= 1
    U_prime.reverse()
    D_prime.reverse()

    return DP[n][m], U_prime, D_prime

T = int(input().strip())

for _ in range(T):
    input()

    U = list(map(int, input().strip().split()))
    D = list(map(int, input().strip().split()))

    val, U_prime, D_prime = lists_alignment(U,D)

    print(val)

    for u in U_prime:
        print(u, end=' ')
    
    print()

    for d in D_prime:
        print(d, end=' ')
    print()