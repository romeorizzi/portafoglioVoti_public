"""
* user:  VR448249_id765wfu
* fname: ELIA
* lname: PIACENTINI
* task:  altopiano
* score: 25.0
* date:  2020-09-18 10:58:04.471041
"""
n_m = input('')
n_m_splitted = n_m.split()
n = int(n_m_splitted[0])
m = int(n_m_splitted[1])

str_height = input('')
list_hight = str_height.split()

list_int_height = [int(i) for i in list_hight]
commands = []
for i in range(0, m):
    commands.append(input(''))



range_max = {}
modified_something = False
count_modify = 0


for comm in commands:
    splitted_comm = [int(i) for i in comm.split()]
    if splitted_comm[0] == 2:
        if count_modify == 0:
            count_modify += 1
        else:
            modified_something = False
        # to do: se non ho modificato altezze, stampa risultato vecchio
        max_height = None
        key = (splitted_comm[1], splitted_comm[2])
        if not modified_something:
            for k in range_max.keys():
                if key[1] >= k[1] and key[2] <= k[2]:
                    print(range_max[k])
                    break
        for i in range(splitted_comm[1], splitted_comm[2]):
            if splitted_comm[2] - i >= 2:
                if max_height is None or list_int_height[i] > max_height: #altrimenti non guardo neanche
                    if list_int_height[i] == list_int_height[i + 1] == list_int_height[i + 2]:
                        max_height = list_int_height[i]
                    # salto avanti
                    i += 2
        if max_height is None:
            print('NESSUN_ALTOPIANO')
        else:
            print(str(max_height))
    else:
        list_int_height[splitted_comm[1]] += splitted_comm[2]
        if not modified_something:
            modified_something = True
        #print(str(list_int_height))
