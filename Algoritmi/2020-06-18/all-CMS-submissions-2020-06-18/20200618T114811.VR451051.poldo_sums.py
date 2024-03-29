"""
* user:  VR451051
* fname: BODINI
* lname: ALESSIA
* task:  poldo_sums
* score: 23.0
* date:  2020-06-18 11:48:11.318508
"""
def max_panini():
    # Scelgo il punto di partenza i
    for i in range(N):
        seq_i = [[i]]
        # Per ogni suoi successore in panino
        for j in range(i+1,N):
            # Controllo ogni sequenza di indici ammissibili già creata e vedo se si può allungare
            for k in range(len(seq_i)):
                # Se è allungabile allora creo una nuova sequenza e la metto in lista insieme alle altre
                if panino[j] >= panino[seq_i[k][-1]] + sum([gym[x] for x in range(seq_i[k][-1],j)]):
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
