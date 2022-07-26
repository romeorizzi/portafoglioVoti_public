"""
* user:  VR473845
* fname: ALBERTO
* lname: CARLI
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 11:40:41.203559
"""
#!/usr/bin/env python3
import sys

g, n, k = list(map(int, input().split()))
input_seq = list(map(int, input().split()))


mem = [None for _ in range(n)]
global_indexes = range(n)

def trova_lunghezza_massima(input_sequence, prev_item, allowed_jumps, local_indexes):

    max_len_sol = 0
    num_max_sol = 0
    
    # Stato terminale. Ho una sola scelta possibile, la faccio.
    if len(input_sequence) == 0:
        return 1, 1

    # Considero tutte le opzioni, una per volta
    for index, item in enumerate(input_sequence):

        jumps_left = allowed_jumps
        if item <= prev_item:
            jumps_left -= 1
        

        # Estraggo le altre scelte possibili rimanenti
        temp = input_sequence[index+1:]
        temp_ind = local_indexes[index+1:]

        # Quando non ho salti disponibili posso ridurre la dimensione
        if jumps_left == 0:
            temp_ind = list([i for j, i in enumerate(temp_ind) if temp[j] > item])
            temp = list([i for i in temp if i > item])


        if len(temp) >= max_len_sol:
            # Calcolo il massimo della lunghezza con le scelte rimanenti

            if mem[local_indexes[index]] != None:
                sol_len, num_max_sol_sub =  mem[local_indexes[0]]
            else:
                sol_len, num_max_sol_sub = trova_lunghezza_massima(temp, item, jumps_left, temp_ind)
            
            if sol_len > max_len_sol:
                max_len_sol = sol_len
                num_max_sol = num_max_sol_sub
            elif sol_len == max_len_sol:
                num_max_sol += num_max_sol_sub

            # Verifica degli elementi rimanenti

            mem[index] = (max_len_sol, num_max_sol)

    return (1+max_len_sol, num_max_sol)


print(trova_lunghezza_massima(input_seq, 0, k, range(n))[g-1])
exit(0)