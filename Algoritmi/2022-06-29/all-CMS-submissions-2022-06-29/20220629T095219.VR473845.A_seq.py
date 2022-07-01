"""
* user:  VR473845
* fname: ALBERTO
* lname: CARLI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 09:52:19.543106
"""
input1 = input().strip().split(" ")
g = int(input1[0])
n = int(input1[1])
#print(f"g = {g}\nn = {n}")

input2 = input().strip().split(" ")
input = [int(i) for i in input2]
#print(input)

def max_A(seq):
    maxsub = []
    for i in range(len(seq)):
        subs = [seq[i]]
        #print("ascending:")
        for j in seq[i+1:]:
            #print(f"{j}")
            if j > subs[len(subs)-1]:
                subs.append(j)
        #print("descending:")
        for j in seq[i+len(subs):]:
            #print(f"{j}")
            if j < subs[len(subs)-1]:
                subs.append(j)
        if len(subs) > len(maxsub):
            print(f"new max: {len(maxsub)} <- {len(subs)}\t{subs}")
            maxsub = subs
    return maxsub


'''
input = [0, 9, 8, 5, 1, 8, 4, 7]

input = [1, 4, 3, 5, 1, 2, 3, 4, 7]
'''
print(len(max_A(input)))
'''
def max_A_seqs(seq, maxlen):

    maxval = max(seq)
    print(maxval)

    #print(seq[:seq.index(maxval)+1])
    print(max_asc(seq[:seq.index(maxval)]))
    print(max_desc(seq[:seq.index(maxval)]))

    

    return maxval

def max_asc(seq):
    print(f"seq = {seq}")

    if len(seq) == 0:
        return 0
    if len(seq) == 1:
        print(f"Returning {seq}")
        return 1

    
    maxval = max(seq)
    return max(1 + max_asc(seq[:seq.index(maxval)]), 
                    max_asc(seq[seq.index(maxval)+1:]))
    

def max_desc(seq):
    print(f"seq = {seq}")

    if len(seq) == 0:
        return 0
    if len(seq) == 1:
        print(f"Returning {seq}")
        return 1

    
    minval = min(seq)
    return max(1 + max_desc(seq[:seq.index(minval)]), 
                    max_desc(seq[seq.index(minval)+1:]))
 

    
max_A_seqs(input, 5)
'''