"""
* user:  VR473845
* fname: ALBERTO
* lname: CARLI
* task:  esameincr_subseq_with_drops
* score: 10.0
* date:  2022-07-26 10:50:38.234885
"""
#!/usr/bin/env python3
import sys

g, n, k = list(map(int, input().split()))
input_sequence = list(map(int, input().split()))


def trova_lunghezza_massima(input_sequence, prev_item, allowed_jumps):

    max_len_sol = 0
    num_max_sol = 0
    
    # Stato terminale. Ho una sola scelta possibile, la faccio.
    if len(input_sequence) == 0:
        return 0, 0
    if len(input_sequence) == 1:
        return 1, 1


    # Considero tutte le opzioni, una per volta

    for index, item in enumerate(input_sequence):
        jumps_left = allowed_jumps
        if item <= prev_item:
            jumps_left -= 1
        

        # Estraggo le altre scelte possibili rimanenti
        temp = input_sequence[index+1:]

        # Quando non ho salti disponibili riduco la dimensione
        if jumps_left == 0:
            temp = list([i for i in temp if i > item])


        if len(temp) >= max_len_sol and jumps_left >= 0:
            # Calcolo il massimo della lunghezza con le scelte rimanenti
            sol_len, num_max_sol_sub = trova_lunghezza_massima(temp, item, jumps_left)
            
            if sol_len > max_len_sol:
                max_len_sol = sol_len
                num_max_sol = num_max_sol_sub
            elif sol_len == max_len_sol:
                num_max_sol += num_max_sol_sub

            # Verifica degli elementi rimanenti

    return (1+max_len_sol, num_max_sol)


print(trova_lunghezza_massima(input_sequence, 0, k)[g-1])
exit(0)