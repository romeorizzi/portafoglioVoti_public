"""
* user:  VR437058
* fname: BONETTI
* lname: LORENZO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 08:47:24.391942
"""
def cambio(nani, p1, p2):
    temp = nani[p1-1]
    nani[p1-1] = nani[p2-1]
    nani[p2-1] = temp
    return nani


def altezza(nani, h1, h2):
    hmin = min(h1,h2)
    hmax = max(h1,h2)
    i_min = min(nani.index(hmin), nani.index(hmax))
    i_max = max(nani.index(hmin), nani.index(hmax))
    for i in range(i_min, i_max + 1):
        if (nani[i] < hmin or nani[i] > hmax):
                return False
    return True
                

##with open("input0.txt") as file:
##        data = file.readlines()
##
##in_file = []
##for line in data:
##    righe = line.split()
##    in_file.append(righe)
##
##for i in range(len(in_file)):
##    in_file[i] = list(map(int, in_file[i]))
##
##n_nani = in_file[0][0]
##m_richieste = in_file[0][1]
##nani = in_file[1]
##richieste = []
##for i in range(2, m_richieste + 2):
##    richieste.append(in_file[i])
##
##for i in range(m_richieste):
##    if richieste[i][0] == 1:
##        nani = cambio(nani, richieste[i][1], richieste[i][2])
##    else:
##        out = altezza(nani, richieste[i][1], richieste[i][2])
##        if out:
##            print('YES')
##        else:
##            print('NO')


    




    
