"""
* user:  VR450864_id939fgd
* fname: ANDREA
* lname: RANCAN
* task:  turniPFG-2DAGs
* score: 30.0
* date:  2021-02-12 11:41:59.800840
"""
#!/usr/bin/env python3
import fileinput

fin = fileinput.input()


tipo = int(fin[0])
giorni = int(fin[1])
persone = int(fin[2])

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
if tipo == 0:
    print(giorni - pagamento)
else:
    print(regali)
