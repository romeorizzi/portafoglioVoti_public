"""
* user:  VR450797
* fname: SEREZ
* lname: DARIO
* task:  bin_heap_fill
* score: 24.0
* date:  2020-06-18 11:26:58.057757
"""
#!/usr/bin/env/python

# Verifica che E sia buono, ossia che A[i] >= A[(i-1)/2] per ogni i in E
def verify_E():

    # Passo E alla ricerca degli indici da verificare:
    for i in range(N):
        if E[i] == 1:
            # Se il vincolo è violato, ritorno 0
            if A[i] < A[ (int) ((i-1)/2) ]:
                return 0

    return 1


def find_F():

    # Guardiamo i due casi "particolari", dove F = 0 oppure F = 1 per ogni i.
    # Se posso muovere tutto, sicuramente ritorno 1. Basta riordinare A. 
    # Se ho tutto fisso, allora lancio verify_E e se mi va bene ritorno 1, altrimenti 0

    check_1 = True
    check_0 = True
    for i in F:
        if i == 1:
            check_0 = False

        if i == 0:
            check_1 = False
    if check_0:
        return 1    

    if check_1:
        return verify_E()

    # Se ho solo alcuni F fissi. Una strategia può essere quella di riordinare A sugli F mobili.
    A_mobile = []

    for i in range(N): 
        if F[i] == 0:
            A_mobile.append(A[i])

    A_mobile.sort()

    for i in range(N):
        if F[i] == 0:
            A[i] = A_mobile.pop(0)

    # Qui mi dovrei ritrovare con A ordinato a meno dei fissi.
    

    # a questo punto passo A e faccio il check per ogni elemento in E
    # Se l'elemento non soddisfa la condizione posso provare a sostituirlo
    # Se non c'è verso di sostituirlo, ritorna 0

    for i in range(N):

        # questo numero in A deve soddisfare la condizione
        if E[i] == 1:
            
            # Se non ha figli, la condizione è soddisfatta sicuramente.
            if (i+1)*2 >= N: # controllo che il figlio dx esista
                continue 

            # Se ha figli, guardo se soddisfa la condizione
            if (A[i] < A[ (int) (((i+1)*2)-1) ] and  A[i] < A[ (int) ((i+1)*2) ]):
                continue

            # Se arrivo qui la condizione non è soddisfatta.

            # Perchè no ? I casi sono tre. 
            # O A[i] è fisso ed è > di almeno uno dei suoi figli.
            # O il figlio "cattivo" (o i figli) è fisso.
            # Oppure ovviamente sono entrambi fissi.

            # Per prima cosa devo capire chi è il cattivo (cioè chi è fisso)
            bad_dad = False
            bad_sx = False
            bad_dx = False

            if F[i] == 1:
                bad_dad = True

            if F[(int) (((i+1)*2)-1) ] == 1:
                bad_sx = True

            if F[(int) ((i+1)*2) ] == 1:
                bad_dx = True

            # Se sono entrambi fissi allora posso fare poco. ritorno 0
            if bad_dad and (bad_sx or bad_dx):
                return 0

            if bad_dad: # padre cattivo, figli mobili 

                sx_i = A[(int) (((i+1)*2)-1)] #figlio sx di A[i]
                dx_i = A[(int) ((i+1)*2)] #figlio dx di A[i]

                # il figlio sx è mobile e mi da un problema
                if (not bad_sx) and sx_i < A[i]:

                    # in modo simmetrico al caso "Padre cattivo", prendo il figlio e lo tento di scambiare con i figli più a destra
                    sx_index =  ((i+1)*2)-1 # se è il penutlimo nodo, ho perso
                    if sx_index == N - 2:
                        return 0

                    # fisso j come indice del figlio_sx  + 2
                    j = sx_index + 2

                    while (j < N):

                        # guardo se A[j] è mobile e se scambiando risolvo il problema
                        if F[j] == 0:

                            dad_j = A[(int) ((j-1)/2)] # padre di j

                            # il padre di sx_i è minore di A[j]? e il padre di A[j] è minore di sx_i ? 
                            if A[j] >= A[i] and sx_i >= dad_j:
                                tmp = sx_i
                                sx_i = A[j]
                                A[j] = tmp
                                break

                            #altrimenti se sx_i < di dad_j ho perso
                            if sx_i < dad_j:
                                return 0
                        j+= 1

                if (not bad_dx) and dx_i < A[i]: #il problema è col figlio destro:

                    # in modo simmetrico al caso "Padre cattivo", prendo il figlio e lo tento di scambiare con i figli più a destra
                    dx_index =  (i+1)*2 # se è il penutlimo nodo, ho perso
                    if dx_index == N - 1:
                        return 0

                    # fisso j come indice del figlio_sx  + 2
                    j = dx_index + 1

                    while (j < N):

                        # guardo se A[j] è mobile e se scambiando risolvo il problema
                        if F[j] == 0:

                            dad_j = A[(int) ((j-1)/2)] # padre di j

                            # il padre di sx_i è minore di A[j]? e il padre di A[j] è minore di sx_i ? 
                            if A[j] >= A[i] and dx_i >= dad_j:
                                tmp = dx_i
                                dx_i = A[j]
                                A[j] = tmp
                                break

                            #altrimenti se sx_i < di dad_j ho perso
                            if dx_i < dad_j:
                                return 0
                        j+= 1

            else: # padre mobile figli no
                # se il padre è mobile ed è > di almeno un figlio.
                # se il padre è la radice, ho perso
                # altrimenti lo scalo a sx al primo mobile (se rispetta la condizione), altrimenti ho perso.
                if i == 0:
                    return 0

                # fisso j come indice del padre - 1
                j = i - 1 
                sx_i = A[(int) (((i+1)*2)-1)] #figlio sx di A[i]
                dx_i = A[(int) ((i+1)*2)] #figlio dx di A[i]

                while (j > 0):

                    # guardo se A[j] è mobile e se scambiando risolvo il problema
                    if F[j] == 0:

                        sx_j = A[(int) (((j+1)*2)-1)] #figlio sx di A[j]
                        dx_j = A[(int) ((j+1)*2)] #figlio dx di A[j]

                        # i figli di A[i] sono maggiori di A[j] ? e il contrario ? 
                        if A[j] <= sx_i and A[j] <= dx_i and A[i] <= sx_j and A[i] <= dx_j:
                            tmp = A[i]
                            A[i] = A[j]
                            A[j] = tmp
                            break

                        #altrimenti se i figli di A[j] sono < di A[i] non posso andare ancora indietro.
                        if A[i] > sx_j and A[i] > dx_j:
                            return 0
                    j -= 1
    
                            
                        

                


    return 1

if __name__ == "__main__":
    
    # LETTURA da stdin.
    N, mode = input().split()

    assert N.isdigit() and mode.isdigit()

    N = (int)(N)
    mode = (int) (mode)

    assert N >= 0 and (mode == 1 or mode == 2)

    if N == 0:
        print(0)

    else:

        A = input().split()
        E = input().split()
        F = input().split()

        assert len(A) == N and len(E) == N and len(F) == N

        for i in range(N):
            assert A[i].isdigit() and E[i].isdigit() and F[i].isdigit()

            A[i] = (int) (A[i])
            E[i] = (int) (E[i])
            F[i] = (int) (F[i])

            assert A[i] >= 0
            assert E[i] == 0 or E[i] == 1
            assert F[i] == 0 or F[i] == 1

        # Ho letto tutto

        if mode == 1:
            print(verify_E())

        else:           
            print(find_F())
           # print(A)
