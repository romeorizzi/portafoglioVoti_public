"""
* user:  VR465317
* fname: NICOLO
* lname: SQUARZONI
* task:  esame_two_three_steps_stdio
* score: 0.0
* date:  2023-02-20 13:44:17.399504
"""
def next (da, e):
    nxts = []
    for i in e:
        if da in i[:1]:
            nxts.append([i[1], i[2]])
    return nxts

def cammini(da, a, e):
    nxts = next(da, e)
    if len(nxts) > 0:
        l = []
        c = []
        for i in nxts:
            if i[0] == a:
                l.append(1)
                c.append(i[1])
            else:
                lunghezze, costi = cammini(i[0], a, e)
                if lunghezze != -1:
                    for j in lunghezze:
                        l.append(j + 1)
                    for h in costi:
                        c.append(h + i[1])
        return l, c
    else:
        return -1

def sogni(corridoio):
    if len(corridoio)== 0:
        return [0]
    elif len(corridoio)== 1:
        return [corridoio[0]]
    elif len(corridoio) == 2:
        possibilita = []
        p2 = sogni(corridoio[2:])
        for i in p2:
            possibilita.append(corridoio[0]+i)
        return possibilita
    else: 
        possibilita = []
        p2 = sogni(corridoio[2:])
        for i in p2:
            possibilita.append(corridoio[0]+i)
        p3 = sogni(corridoio[3:])
        for i in p3:
            possibilita.append(corridoio[0]+i)
        return possibilita



n = map(int,input())
corridoio = list(map(int,input().split()))
print(n)
print(corridoio)

print(max(sogni(corridoio)))