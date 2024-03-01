def recursive_find_cycle(e, supp, percorso):
    for j in e:
        if j in percorso: pass
        else: 
            percorso.append(j)
            recursive_find_cycle(supp[j], supp, percorso)
    return percorso
        

testcase = int(input())

for t in range(0, testcase):
    n, m = map(int, input().strip().split())

    supp = []
    for i in range(0, n): supp.append([])

    for e in range(0, m):
        n1, n2 = map(int, input().strip().split())
        if len(supp[n1]) > 0: supp[n1].append(n2)
        else: supp[n1] = [n2]
        # senza questa parte, ho metà degli archi da computare
        if len(supp[n2]) > 0: supp[n2].append(n1)
        else: supp[n2] = [n1]

    skip = []
    solution = []
    count = 0
    for e in supp:
        if count in solution: pass
        else:
            percorso = []
            skip = recursive_find_cycle(e, supp, percorso)
            if len(skip) % 2 == 1:
                if len(solution) == 0: solution = skip
                else: 
                    for y in skip:
                        solution.append(y)
        count += 1

    sol = list(set(solution))
    print(len(sol))
    for solu in sol:
        print(solu, end=' ')
    print()


        