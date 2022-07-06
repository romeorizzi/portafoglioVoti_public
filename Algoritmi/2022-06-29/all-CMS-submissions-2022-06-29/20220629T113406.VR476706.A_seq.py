"""
* user:  VR476706
* fname: LUCA
* lname: GUGOLE
* task:  A_seq
* score: 0.0
* date:  2022-06-29 11:34:06.246432
"""
def findAseq1(lista):
    current_max = 0
    count_max = 0
    for i in range(0, len(lista)):
        current = 0
        if i == 0:
            current = findAseqRec(lista[1::], lista[i]+1, 1)
        elif i == len(lista) - 1:
            current = findAseqRec(lista[0:len(lista)-1], lista[i]-1, 0)
        #elif lista[i] > lista[i-1] and lista[i] > lista[i+1]:
        else:
            current = findAseqRec(lista[0:i], lista[i]-1, 0) + findAseqRec(lista[i+1::], lista[i]+1, 1)
        if current > current_max:
            current_max = current
            count_max = 1
        elif (current == current_max):
            count_max += 1
    return current_max, count_max + 1


def findAseqRec(lista, piv, mode):
    if mode == 0:
        if len(lista) <= 0:
            return 0
        if lista[len(lista)-1] < piv:
            return 1 + findAseqRec(lista[0:len(lista)-1], lista[len(lista)-1], mode)
        else:
            return 0 + findAseqRec(lista[0:len(lista)-1], lista[len(lista)-1], mode)
    elif mode == 1:
        if len(lista) <= 0:
            return 0
        if lista[0] < piv:
            return 1 + findAseqRec(lista[1::], lista[0], mode)
        else:
            return 0 + findAseqRec(lista[1::], lista[0], mode)


def findAseq2(lista):
    max, count = findAseq1(lista)
    return count % 1000000007



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
        l = findAseq1(lista[0:n])
        print(l[0])
    elif g == 2:
        l = findAseq2(lista[0:n])
        print(l)


if __name__ == "__main__":
    main()