"""
* user:  VR437058
* fname: BONETTI
* lname: LORENZO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 10:55:15.986604
"""
def cambio(nani, pos_nani, p1, p2):
    #temp = nani[p1-1]
    pos_nani[nani[p1-1]] = p1
    pos_nani[nani[p2-1]] = p2
    return pos_nani


def altezza(nani, pos_nani,h1, h2):
    hmin = min(h1,h2)
    hmax = max(h1,h2)
    i_min = min(pos_nani.index(hmin-1), pos_nani.index(hmax-1))
    i_max = max(pos_nani.index(hmin-1), pos_nani.index(hmax-1))
    for i in range(i_min, i_max + 1):
        if (nani[i] < hmin or nani[i] > hmax):
                return False
    return True
                

with open("input.txt") as file:
        data = file.readlines()

in_file = []
for line in data:
    righe = line.split()
    in_file.append(righe)

for i in range(len(in_file)):
    in_file[i] = list(map(int, in_file[i]))

n_nani = in_file[0][0]
m_richieste = in_file[0][1]
nani = in_file[1]
pos_nani = nani.copy()
for i in range(len(nani)):
    pos_nani[nani[i] - 1] = i 
    
richieste = []
for i in range(2, m_richieste + 2):
    richieste.append(in_file[i])

for i in range(m_richieste):
    if richieste[i][0] == 1:
        pos_nani = cambio(nani, pos_nani, richieste[i][1], richieste[i][2])
    else:
        out = altezza(nani, pos_nani, richieste[i][1], richieste[i][2])
        if out:
            print('YES')
        else:
            print('NO')


    




    
