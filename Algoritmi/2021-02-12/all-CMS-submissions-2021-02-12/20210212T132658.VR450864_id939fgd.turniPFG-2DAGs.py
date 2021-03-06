"""
* user:  VR450864_id939fgd
* fname: ANDREA
* lname: RANCAN
* task:  turniPFG-2DAGs
* score: 10.0
* date:  2021-02-12 13:26:58.665579
"""
#!/usr/bin/env python3
import fileinput

fin = fileinput.input()


tipo = int(fin[0])
giorni = int(fin[1])
persone = int(fin[2])


if tipo == 0:
    days = list(range(giorni))
    list= [[] for v in range(persone) ]

    for i in range(persone):
        inizio,fine = map(int,fin[3+i].split())
        list[i].append(inizio)
        list[i].append(fine)
    for i in range(persone):
        for j in range(list[i][0], list[i][1] + 1):
            if j in days:
                days.remove(j)
    if not days:
        print(0)
    else:
        print(len(days))
else:
    days = list(range(giorni))
    list= [[] for v in range(persone) ]
    regali = 0
    for i in range(persone):
        inizio,fine = map(int,fin[3+i].split())
        for j in range(inizio, fine+1):
            list[i].append(j)
    print(list)
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
