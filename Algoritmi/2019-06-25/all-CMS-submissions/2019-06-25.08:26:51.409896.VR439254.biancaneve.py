"""
* user:  VR439254
* fname: TOAIARI
* lname: ANDREA
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 08:26:51.409896
"""
def operazione2(nani):
    return True

def biancaneve():
    nnani = int(input("Inserire numero di nani:"))
    comandi = int(input("Inserire il numero di comandi"))
    nani = []
    for i in range(nnani):
        nani[i] = int(input("Inserire nano: "))

    comandi = []
    for i in range(comandi):
        print("Comando " + str(i))
        comando[0] = int(input("Inserire il comando: "))
        comando[1] = int(input("Inserire il primo nano: "))
        comando[2] = int(input("Inserire il secondo nano: "))
        comandi.append(comando)

    ### esecuzione
    for comando in comandi:
        if comando[0] == 1:
            # scambio
            t = nani[comando[1]-1]
            nani[comando[1]-1] = nani[comando[2]-1]
            nani[comando[2]-1] = t
        else if comando[0] == 2:
            # controllo
            if nani.index(comando[1]) < nani.index(comando[2]):
                if operazione2(nani[nani.index(comando[1]):nani.index(comando[2])]):
                    print("YES")
                else:
                    print("NO")
            else:
                if operazione2(nani[nani.index(comando[2]):nani.index(comando[1])]):
                    print("YES")
                else:
                    print("NO")
        else:
            #errore
            print("Comando non riconosciuto")
