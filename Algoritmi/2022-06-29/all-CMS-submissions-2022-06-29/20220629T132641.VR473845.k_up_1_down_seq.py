"""
* user:  VR473845
* fname: ALBERTO
* lname: CARLI
* task:  k_up_1_down_seq
* score: 0.0
* date:  2022-06-29 13:26:41.974244
"""
def sequence(v, i, n, k):

    if i == 0:
        return [[0] + (i) for i in sequence(0, i+1, n, k)]

    if i == n-1:
        return [[0]]

    if v >= n-i:
        tmp = [[(v-1)] + (i) for i in sequence(v-1, i+1, n, k)]
        return tmp

    if v == 0:
        tmp = [[0] + (i) for i in sequence(0, i+1, n, k)] +\
         [[k] + (j) for j in sequence(k, i+1, n, k) if v+k < n-i]
        return tmp

    if v != 0:
        tmp = [[v-1] + (i) for i in sequence(v-1, i+1, n, k)] +\
        [[v+k] + (j) for j in sequence(v+k, i+1, n, k) if v+k < n-i] +\
        [[v] + (i) for i in sequence(v, i+1, n, k)]
        return tmp
    


    
command = input().strip().split(" ")

g = int(command[0])
n = int(command[1])
k = int(command[2])

if g == 1:  
    print(len(sequence(0, 0, n, k)))
if g == 2:
    print(sequence(0, 0, n, k)[k+1])
if g == 3:
    newsequence = input().strip().split()
    int_seq = [int(i) for i in newsequence]

    print(sequence(0, 0, n, k).index(int_seq))

if g == 4:
    seq = sequence(0, 0, n, k)
    for i in seq:
        for j in i:
            print(str(j), end=" ")
        print()

