"""
* user:  VR448249_id765wfu
* fname: ELIA
* lname: PIACENTINI
* task:  chordal_lexBFS
* score: 0.0
* date:  2020-09-18 12:01:32.996135
"""
'''
input:
    g, n = |V|, m = |E|
    m righe successive che codificano archi
se g = 1:
    1 se l'ordine dei nodi da 1 a n è lexBFS, altrimenti 0
    e su seconda riga tripla (j, i, j') lessicograficamente minima.
se g = 2:
    l'ordinamento è lexBFS e se l'ordinamento rovesciato è un perfect elimination scheme di G, ritorna l'ordinamento
    altrimenti ritorna i minore per cui il grafo continee un buco
se g = 3, 4, 5:
    l'ordinamento è un perfect elimination scheme.
    Se g = 3 ritorna w(G) = X(G)
    Se g = 4 ritorna anche i nodi della clique Q -> |Q| = w(G) in ordine crescente
    Se g = 5 ritorna il X(G) coloring
'''


def populateGraph(num_v, num_e, graph):
    graph_matrix = [[0 for x in range(0, num_v)] for y in range(0, num_v)]
    splitted_graph = graph.split('\n')
    for entry in splitted_graph:
        if entry != '':
            # splitto l'arco
            list_entry = entry.split()
            # casto a int
            x = int(list_entry[0])
            y = int(list_entry[1])
            graph_matrix[x - 1][y - 1] = 1
            graph_matrix[y - 1][x - 1] = 1
    return graph_matrix

def lexBFS(graph_matrix, num_v):
    sequence = []
    # NB: ricordati di aumentare di 1 alla fine
    for row in graph_matrix:
        for el in row:
            if el == 1:
                sequence.append(el)
    order = False
    for i in range(0, len(sequence)):
        if i == len(sequence):
            order = True
            break
        if sequence[i + 1] - sequence[i] != 1:
            break
    if order:
        return 1
    else:
        return 0

with open('input.txt', 'r') as input_file:
    line = input_file.readline()
    splitted = line.split()
    n = int(splitted[1])
    m = int(splitted[2])
    graph = input_file.read()
    graph_matrix = populateGraph(n, m, graph)

    with open('output.txt', 'w') as output_file:
        if line[0] == '1':
            output_file.write(str(lexBFS(graph_matrix, n)))
        if line[0] == '2':
            print('no')
    '''
    output_file = open('output.txt', 'w')
    for el in [n]:
        output_file.write(el)
        output_file.write('\n')
    # print(memoizzazione[n])
    '''