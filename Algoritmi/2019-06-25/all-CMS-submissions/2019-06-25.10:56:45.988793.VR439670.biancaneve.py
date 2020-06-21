"""
* user:  VR439670
* fname: LUCCHESE
* lname: MARCO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 10:56:45.988793
"""
#prima_riga=input("n e m ")
#prima_riga=prima_riga.split(" ")
#n=int(prima_riga[0])#numero nani
#m=int(prima_riga[1])#numero richieste bianca
#disposizione_nani=input("disposizione ")
#disposizione_nani=disposizione_nani.split(" ")

count=0
for riga in open("input.txt","r"):
    if count==0:
        riga=riga.split(" ")
        n=int(riga[0])#numero nani
        m=int(riga[1])#numero richieste bianca
    if count==1:
        disposizione_nani=riga
        disposizione_nani=disposizione_nani.split(" ")
    if count>1:
        i=0
        comando=riga
        comando=comando.split(" ")
        if int(comando[0])==1: #controllo che biancaneve voglia scambiare i nan
            #scambio i nani
            first=int(comando[1])-1
            second=int(comando[2])-1
            temp=disposizione_nani[first]
            disposizione_nani[first]=disposizione_nani[second]
            disposizione_nani[second]=temp
        else:#biancaneve vuole controllare i nani
            first=int(comando[1])
            second=int(comando[2])
            h=0
            while h < len(disposizione_nani):#trovo la posizione dei nani
                if int(disposizione_nani[h])==first:
                    pos_first=h
                if int(disposizione_nani[h])==second:
                    pos_second=h
                h+=1
            if pos_first>pos_second:#prendo prima la posizione più bassa
                temp=pos_first
                pos_first=pos_second
                pos_second=temp
            it=pos_first+1
            flag=0
            if(disposizione_nani[pos_second]<disposizione_nani[pos_first]):
                val_mag=disposizione_nani[pos_first]
                val_min=disposizione_nani[pos_second]
            else:
                val_mag=disposizione_nani[pos_second]
                val_min=disposizione_nani[pos_first]
            while it != pos_second:#controllo che siano ad intervalli contigui
                if(disposizione_nani[it]>val_mag or disposizione_nani[it]<val_min):
                    flag=1
                it+=1
            if pos_second-pos_first==1: #controllo che non siano a distanza 0 cioè due numeri consecutivi
                flag=0
            f=open("output.txt","a+")
            if flag==0:
                f.write("YES\n")
            else:
                f.write("NO\n")
            f.close
    count+=1 


