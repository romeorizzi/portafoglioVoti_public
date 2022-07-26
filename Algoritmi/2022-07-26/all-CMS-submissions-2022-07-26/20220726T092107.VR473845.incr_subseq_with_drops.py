"""
* user:  VR473845
* fname: ALBERTO
* lname: CARLI
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 09:21:07.197094
"""
#!/usr/bin/env python3
import sys

g, n, k = list(map(int, input().split()))
input_sequence = list(map(int, input().split()))
'''
input_sequence = [6, 4, 1, 2, 2, 3, 4, 4, 5, 9]
g = 1
n = 10
k = 0
'''


def trova_lunghezza_massima(input_sequence, allowed_jumps):

    max_len_sol = 0
    num_max_sol = 0
     
    # Stato terminale. Ho una sola scelta possibile, la faccio.
    if len(input_sequence) == 1:
        return 1, 0

    # Considero tutte le opzioni, una per volta
    for index, item in enumerate(input_sequence):

        # Estraggo le altre scelte possibili rimanenti
        temp = input_sequence[index:]
        print(temp)

        # Quando non ho salti disponibili riduco la dimensione
        if allowed_jumps == 0:
            temp = list([i for i in temp if i > item])


        # Calcolo il massimo della lunghezza con le scelte rimanenti
        sol_len, num_max_sol_sub = trova_lunghezza_massima(temp, allowed_jumps)
        sol_len += 1

        if sol_len > max_len_sol:
            max_len_sol = sol_len
            num_max_sol = num_max_sol_sub
        if sol_len == max_len_sol:
            num_max_sol += 1

        # Verifica degli elementi rimanenti
        print(f"{item}: {temp}")
        print(f"{sol_len}/{max_len_sol}")

        print("-----------------")
    return (max_len_sol, num_max_sol)

print(trova_lunghezza_massima(input_sequence, 0)[g-1])
exit(0)