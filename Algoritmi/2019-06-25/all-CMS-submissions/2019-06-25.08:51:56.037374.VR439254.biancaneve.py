"""
* user:  VR439254
* fname: TOAIARI
* lname: ANDREA
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 08:51:56.037374
"""
def operazione2(nani):
    print(nani)
    min = nani[0]
    max = nani[len(nani)-1]
    if min > max:
        c = min
        min = max
        max = c
    for i in range(len(nani)):
        if nani[i] < min or nani[i] > max:
            return False
    return True

def biancaneve():
    nnani = int(input("Inserire numero di nani: "))
    ncomandi = int(input("Inserire il numero di comandi: "))
    nani = []
    for i in range(nnani):
        nani.append(int(input("Inserire nano: ")))

    comandi = []
    for i in range(ncomandi):
        print("Comando " + str(i))
        a = int(input("Inserire il comando: "))
        b = int(input("Inserire il primo nano: "))
        c = int(input("Inserire il secondo nano: "))
        comando = [a, b, c]
        comandi.append(comando)

    ### esecuzione
    for comando in comandi:
        if comando[0] == 1:
            # scambio
            t = nani[comando[1]-1]
            nani[comando[1]-1] = nani[comando[2]-1]
            nani[comando[2]-1] = t
            print(nani)
        elif comando[0] == 2:
            # controllo
            print(nani)
            if nani.index(comando[1]) < nani.index(comando[2]):
                if operazione2(nani[nani.index(comando[1]):nani.index(comando[2])+1]):
                    print("YES")
                else:
                    print("NO")
            else:
                if operazione2(nani[nani.index(comando[2]):nani.index(comando[1])+1]):
                    print("YES")
                else:
                    print("NO")
        else:
            #errore
            print("Comando non riconosciuto")
