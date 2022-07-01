"""
* user:  VR473845
* fname: ALBERTO
* lname: CARLI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 09:58:47.418408
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


print(len(max_A(input)))