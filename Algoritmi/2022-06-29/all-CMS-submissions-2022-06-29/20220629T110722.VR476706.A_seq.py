"""
* user:  VR476706
* fname: LUCA
* lname: GUGOLE
* task:  A_seq
* score: 0.0
* date:  2022-06-29 11:07:22.412719
"""
def findAseq1(lista):
    current_max = 0
    for i in range(0, len(lista)):
        current = 0
        if i == 0:
            current = 1 - findAseqRec(lista[1::], lista[i]+1, 1)
        elif i == len(lista) - 1:
            current = findAseqRec(lista[0:len(lista)-1], lista[i]-1, 0)
        elif lista[i] > lista[i-1] and lista[i] > lista[i+1]:
            current = findAseqRec(lista[0:i], lista[i]-1, 0) + findAseqRec(lista[i+1::], lista[i]+1, 1)
        print(current)
        if current + 1 > current_max:
            current_max = current + 1
    return current_max


def findAseqRec(lista, piv, mode):
    if mode == 0:
        if len(lista) > 0 and lista[len(lista)-1] < piv:
            return 1 + findAseqRec(lista[0:len(lista)-1], lista[len(lista)-1], mode)
        else:
            return 0
    elif mode == 1:
        if len(lista) > 0 and lista[0] < piv:
            return 1 + findAseqRec(lista[1::], lista[0], mode)
        else:
            return 0


def findAseq2(lista):
    pass
    #for i in range(0, len(lista)):


def main():
    g_n = input().split(" ")
    g = int(g_n[0])
    n = int(g_n[1])
    lista_i = input().split(" ")
    lista = []
    for l in lista_i:
        lista.append(int(l))

    #lista1 = [0, 9, 8, 5, 1, 8, 4, 7]
    #lista2 = [3, 3, 3, 3, 3, 3]

    if g == 1:
        l = findAseq1(lista)
        print(l)
    elif g == 2:
        l = findAseq2()


if __name__ == "__main__":
    main()