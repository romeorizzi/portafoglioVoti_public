"""
* user:  VR450797
* fname: SEREZ
* lname: DARIO
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 12:48:09.492224
"""
#!/usr/bin/env/python

# Per il calcolo, ho la sequenza s fino a qui (res)
# Ho l'indice che mi permette di guardare le sequenze originali (panini, palestra)

def calcola(res, indice):

    # Indice. considero la sequenza [3 8 2 9 4]
    # se sto considerando il panino  8, l'indice passato sarà 4 = len([8 2 9 4])
    # Quindi se devo calcolare il costodi scegliere il panino 2 (successivo della sequenza):
    #s_i = 2 che è l'indice del panino 2 e in questo caso: N - indice + 1 = 5 - 4 + 1
    s_i = N - indice + 1
    s_i_1 = res[len(res)-1] # cioè l'indice dell' ultimo panino che ho aggiunto

    # p = panino[s_1] (2 nel nostro esempio)
    p = panini[s_i_1]
    t_1 = s_i_1
    t_n = s_i - 1 # sarebbe s_i - 1 ma per il for lo aumento di uno in modo da comprendere i due estremi

    # guardo come sono in rapporto i due indici
    somma = 0

    if t_1 <= t_n:
        for i in range(t_1, t_n+1):
            somma += palestra[i]

    return p + somma 


def mangia_panini(res, costo, pan):

    # IDEA: Ad ogni passo prendo il primo panino della sequenza (la sequenza decresce).
    # Quindi, ad ogni passo calcolo già il costo (parte destra della disequazione), del panino successivo.
    # Il primissimo panino ha costo 0 (e all' inizio mando la funzione con parametro 0)

    # CASO BASE:
    # Diventa quello in cui ho l'ultimo panino. Non devo calcolare costo, ma solo vedere se posso prenderlo o meno
    if len(pan) == 1 :

        # Se posso mangiarlo, lo mangio sempre
        # Non ha senso non mangiarlo in quanto mi aumenta uno alla sequenza,
        # ed essendo l'ultimo non toglie nulla ai prossimi possibili panini
        if pan[0] >= costo: 
            return res + memory[(1,"yes")]

        # Se non posso mangiarlo, ritorno una sequenza vuota
        return res

    # Casi induttivi.

    # Se ho in memoria sia la sequenza con yes, che con no, ritorno quella
    # altrimenti svolgo i calcoli:

    if (len(pan) ,"no") not in memory.keys():

        # Per prima cosa calcolo il costo del prossimo panino se non lo posso mangiare
        # Nota: può essere che res sia vuoto. in tal caso il costo è 0
        if len(res) == 0:
            costo_no_mangio = 0
        else:
            costo_no_mangio = calcola(res, len(pan))

        # guardo se posso o meno mangiare questo panino       
        if pan[0] >= costo:

            # Qui devo dividere i due casi. O lo mangio effettivamente o lo passo

            costo_si_mangio = calcola(res + [N - len(pan)],len(pan))

            si_mangio = mangia_panini(res + [N - len(pan)], costo_si_mangio, pan[1:])
            memory[ (len(pan),"yes") ] = si_mangio
            

            no_mangio = mangia_panini(res, costo_no_mangio, pan[1:])
            memory[ (len(pan),"no") ] = no_mangio

            if len( memory[(len(pan),"yes")]) > len( memory[(len(pan),"no")]):
                return memory[(len(pan),"yes")]

            return memory[(len(pan),"no")]

        # Se invece non posso mangiarlo ritorno il prossimo passo
        memory[(len(pan),"yes")] = []
        no_mangio = mangia_panini(res, costo_no_mangio, pan[1:])
        memory[(len(pan),"no")] = no_mangio
        return memory[(len(pan),"no")]

    if len (memory[(len(pan), "yes")] ) == 0:
        return memory[(len(pan),"no")]

    return memory[(len(pan),"yes")]
    

if __name__ == "__main__":
    
    # LETTURA 
    with open("input.txt", "r") as f:
        N = f.readline()

        N = (int) (N)
        assert N > 0

        # Lettura delle sequenze
        panini = []
        palestra = []
        for i in range(N):
            p,g = f.readline().split()
            assert p.isdigit()

            p = (int)(p)
            g = (int)(g)

            panini.append(p)
            palestra.append(g)


    # ESECUZIONE.

    # Si tratta di trovare una massima sequenza crescente nella lista panini, con in più il vincolo della sommatoria su gym
    # Una prima soluzione potrebbe essere un approccio dinamico.
    # Per ogni panino, calcolo se posso tenerlo o meno, e se posso sdoppio le mie scelte (lo tengo / non lo tengo).
    # Il tutto salvando la memoria in modo da ridurre le chiamate ricorsive.

    # Memoria :
    # Dict con chiavi (len(seq) + yes/no) in base a se ho fatto la verifica con panino mangiato o meno  e dall'altra parte res per quella len(seq)
    # Il caso base (sequenza di lunghezza 1, avrà due tuple)
    # (1, yes) --> (N - 1)
    # (1, no) --> []
    # Cioè se arrivo che posso mangiarlo, ritorno N-1, altrimenti niente
    memory = { (1,"yes") : [(N-1)], (1, "no") : []}

    seq = mangia_panini([], 0, panini.copy()) 


    # SCRITTURA (intanto su stdout)
    with open("output.txt", "w") as f:

        f.write((str)(len(seq)))
        f.write("\n") 
    
        for i in seq:
            f.write( (str) (i))
            f.write(" ")