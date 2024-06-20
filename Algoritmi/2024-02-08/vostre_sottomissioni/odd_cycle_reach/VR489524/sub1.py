def checkOddCycle(lista_nodi):

    counter = 0
    j = -1
    odd_list = []

    for i in range(len(lista_nodi)):
        if len(lista_nodi[i]) > 0:

            if(counter == 0):
                odd_list.append(i)

            counter = counter + 1

            odd_list.append(lista_nodi[i][0])
        else:
            counter = 0
    
    if counter % 2 != 0:

        return odd_list
    else:
        return []

            


def check_tri(lista_nodi):

    tri = []

    for i in range(len(lista_nodi)):

        if len(lista_nodi[i]) == 2:
            if lista_nodi[i][0] in lista_nodi[lista_nodi[i][1]]:
                tri.append(i) #2
                tri.append(lista_nodi[i][1]) #3
                tri.append(lista_nodi[i][0]) #4
                
                 
    for i in range(len(lista_nodi)):
        for j in range(len(lista_nodi[i])):
            if lista_nodi[i][j] in tri:
                tri.append(i)

    return tri

T = int(input())

n,m = map(int,input().split(" "))

lista_nodi = []

for i in range(n):

    lista_nodi.append([])

#print(lista_nodi)

for i in range(m-1):

    u,v = map(int,input().split(" "))

    lista_nodi[u].append(v)

tri = check_tri(lista_nodi)

print(tri)

others = []
others = checkOddCycle(lista_nodi)

for i in range(len(others)):
    tri.append[i]

triset = set(tri)

print(triset)



