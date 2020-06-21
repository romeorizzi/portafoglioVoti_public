"""
* user:  VR439670
* fname: LUCCHESE
* lname: MARCO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 08:43:55.846776
"""
prima_riga=input("n e m ")
prima_riga=prima_riga.split(" ")
n=int(prima_riga[0])#numero nani
m=int(prima_riga[1])#numero richieste bianca
disposizione_nani=input("disposizione ")
disposizione_nani=disposizione_nani.split(" ")


i=0
while i < m:
    comando=input("comando ")
    comando=comando.split(" ")
    if int(comando[0])==1: #controllo che biancaneve voglia scambiare i nan
        #scambio i nani
        first=int(comando[1])-1
        second=int(comando[2])-1
        temp=disposizione_nani[first]
        disposizione_nani[first]=disposizione_nani[second]
        disposizione_nani[second]=temp
    else:
        first=int(comando[1])
        second=int(comando[2])
        h=0
        while h < len(disposizione_nani):
            if int(disposizione_nani[h])==first:
                pos_first=h
            if int(disposizione_nani[h])==second:
                pos_second=h
            h+=1
        it=pos_first
        flag=0
        while it != pos_second:
            if(disposizione_nani[it]>disposizione_nani[pos_second] or disposizione_nani[it]<disposizione_nani[pos_first]):
                flag=1
            it+=1
        if flag==0:
            print("YES")
        else:
            print("NO")
    i+=1




