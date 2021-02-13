"""
* user:  VR450864_id939fgd
* fname: ANDREA
* lname: RANCAN
* task:  turniPFG-2DAGs
* score: 20.0
* date:  2021-02-12 13:04:15.495480
"""
#!/usr/bin/env python3
import fileinput

fin = fileinput.input()


tipo = int(fin[0])
giorni = int(fin[1])
persone = int(fin[2])


if tipo == 0:
    lista= [[] for v in range(giorni) ]

    for i in range(persone):
        inizio,fine = map(int,fin[3+i].split())
        lista[inizio].append(fine)

    lista2 =  [[] for v in range(giorni) ]
    for u in range(giorni):
        for v in lista[u]:
            lista2[v].append(u)

    regali = 0
    pagamento = 0
    resto = giorni - 1
    for i in reversed(range(giorni)):
        if lista2[i]:
            min = 100000000
            for j in range(len(lista2[i])):
                if(lista2[i][j] < min):
                    min = lista2[i][j]
            if i <= resto:
                pagamento += i - min + 1
                resto = min - 1
                regali += 1
            elif min <= resto:
                pagamento += resto - min + 1
                resto = min - 1
                regali += 1
    print(giorni - pagamento)
else:
    days = list(range(giorni))
    list= [[] for v in range(persone) ]
    regali = 0
    for i in range(persone):
        inizio,fine = map(int,fin[3+i].split())
        for j in range(inizio, fine+1):
            list[i].append(j)
    stop = 0
    index = 0
    massimo = 0
    while(stop == 0):
        massimo = 0
        for i in range(persone):
            length = 0
            for j in range(len(list[i])):
                if list[i][j] in days:
                    length += 1
            if(length > massimo):
                massimo = length
                index = i
        if( massimo > 0):
            for element in list[index]:
                if element in days:
                    days.remove(element)
            regali += 1
        else:
            stop = 1
    print(regali)
