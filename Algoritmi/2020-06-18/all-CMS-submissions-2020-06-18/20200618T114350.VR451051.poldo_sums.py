"""
* user:  VR451051
* fname: BODINI
* lname: ALESSIA
* task:  poldo_sums
* score: 13.0
* date:  2020-06-18 11:43:50.938582
"""
def gym_sum(a, b):
    return sum([gym[x] for x in range(a, b)])

def gym_mul(a, b):
    return gym * (b - a)

def max_panini():
    # Semplifico i casi in cui i valori in gym sono tutti uguali
    equal = True
    for i in range(N-1):
        if gym[i] != gym[i+1]:
            equal = False

    # Scelgo il punto di partenza i
    for i in range(N):
        seq_i = [[i]]
        # Per ogni suoi successore in panino
        for j in range(i+1,N):
            # Controllo ogni sequenza di indici ammissibili già creata e vedo se si può allungare
            for k in range(len(seq_i)):
                # Se è allungabile allora creo una nuova sequenza e la metto in lista insieme alle altre
                if equal: 
                    gym_tot = gym_mul(seq_i[k][-1], j)
                else:
                    gym_tot = gym_sum(seq_i[k][-1], j)
                if panino[j] >= panino[seq_i[k][-1]] + gym_tot:
                    s = seq_i[k].copy()
                    s.append(j)
                    seq_i.append(s)
        # Ogni nuova sequenza ammissibile creata a partire da i viene aggiunta al totale
        for s in seq_i:
            seq.append(s)
                
    return max(seq, key=len)

with open('input.txt', 'r') as input:
    N = int(next(input).split()[0])
    panino = []
    gym = []
    for line in input:
        panino.append(int(line.split()[0]))
        gym.append(int(line.split()[1]))

assert N == len(panino)
assert N == len(gym)

seq = [[]]
max_seq = max_panini()
#print(seq)
#print(max_seq)


with open('output.txt', 'w') as output:
    output.write(str(len(max_seq)) + ' \n')
    for i in max_seq:
        output.write(str(i) + ' ')
