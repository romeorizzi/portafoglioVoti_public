"""
* user:  VR450797
* fname: SEREZ
* lname: DARIO
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 11:51:09.892190
"""
#!/usr/bin/env/python

if __name__ == "__main__":
    
    #LETTURA.
    N = input()
    assert N.isdigit()

    N = (int) (N)
    assert N > 0

    #ESECUZIONE.
    # la prima cosa che si nota è che chi ha 1 ... 9 vince
    # avendo solo una cifra basta sottrarre quella
    # chi ha 10 perde, perchè può sottrarre solo una
    # chi ha 11 -- 19 sottrae 1 -- 9 e vince

    # Quindi: Se il mio numero finisce co 0 ho perso
    # altrimenti sottraggo l'ultima cifra. Funziona fino a che punto ?
    if (N % 10) == 0:
        print (0)

    else: 
        print(1,N%10)
