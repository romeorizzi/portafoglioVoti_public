"""
* user:  VR473845
* fname: ALBERTO
* lname: CARLI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 11:24:19.249236
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
            #print(f"new max: {len(maxsub)} <- {len(subs)}\t{subs}")
            maxsub = subs
    return maxsub

def max_A_seqs(seq, maxseq):
    rev_seq = [seq[i] for i in range(len(seq)-1, -1, -1)]
    #print(rev_seq)
    res = [maxseq]

    for i in range(1, len(maxseq)):
        newseq = maxseq[-i:]
        #print(seq)
        #print(newseq)
        rev_seq = [seq[i] for i in range(len(seq)-1, -1, -1)]
        for i in reversed(newseq):
            rev_seq.remove(i)

        seq2 = [rev_seq[i] for i in range(len(rev_seq)-1, -1, -1)]
        tempseq = max_A(seq2)
        if len(tempseq) == len(maxseq) and tempseq not in res:
            for i in max_A_seqs(seq2, tempseq):
                if i not in res:
                    res.append(i)


    return res

if g == 1:
    print(len(max_A(input)))
else:
    print(len(max_A_seqs(input, max_A(input))))