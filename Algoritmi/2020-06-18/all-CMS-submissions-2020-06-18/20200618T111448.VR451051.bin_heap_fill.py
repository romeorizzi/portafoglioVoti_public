"""
* user:  VR451051
* fname: BODINI
* lname: ALESSIA
* task:  bin_heap_fill
* score: 24.0
* date:  2020-06-18 11:14:48.315548
"""
def swap(x, y):
    s = x
    x = y
    y = s

    return x, y

def check_E_couple(i, j): 
    if x[i] < x[j] and e[i] == 1 and j != 0:
        return False
    return True

def check_E():
    idx = [i for i in range(n) if e[i] == 1]
    # Esamino ogni indice che deve risultare E-buono (secondo la relazione data)
    for i in idx:
        if x[i] < x[int((i-1)/2)]:
            return 0, i
    return 1, None

def check_F(last_couple):
    idx_f = [i for i in range(n) if f[i] == 0]
    idx_e = [i for i in range(n) if e[i] == 1]
    res, stop = check_E()

    # Se l'array è E-buono:
    if res == 1:
        return 1
    
    # Se non lo è invece:
    # Se il valore non E-buono non può essere ricollocato ritorno 0
    if stop not in idx_f:
        return 0
    # Altrimenti cerco uno scambio
    for i in range(n): 
        if ((i not in last_couple or stop not in last_couple) and i != stop and i in idx_f 
            and check_E_couple(stop, int((i-1)/2)) and check_E_couple(i, int((stop-1)/2))
            # Caso in cui si scambia il figlio con il padre (e vicerversa): 
            # devo controllare se la relazione è E_buona anche sui fratelli
            and (stop != int((i-1)/2) 
                or ((i % 2 == 0 and check_E_couple(i-1, stop) or (i % 2 != 0 and check_E_couple(i+1, stop)))))
            and (i != int((stop-1)/2) 
                or ((stop % 2 == 0 and check_E_couple(stop-1, i) or (stop % 2 != 0 and check_E_couple(stop+1, i)))))):
            x[stop], x[i] = swap(x[stop], x[i])
            #print(x[stop], x[i])
            return check_F([stop, i])
    return 0


line = input()
n = int(line.split()[0])
t = int(line.split()[1])
x, e, f = [], [], []
line = input()
for i in line.split():
    x.append(int(i))
line = input()
for i in line.split():
    e.append(int(i))
line = input()
for i in line.split():
    f.append(int(i))

assert n == len(x)
assert n == len(e)
assert n == len(f)

if t == 1:
    print(check_E()[0])
else:
    print(check_F([0, 0]))
