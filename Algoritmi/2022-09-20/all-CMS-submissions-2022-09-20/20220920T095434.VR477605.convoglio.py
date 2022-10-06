"""
* user:  VR477605
* fname: LORENZO
* lname: TABARELLI
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 09:54:34.593047
"""
input_N_M = list(map(int, input().split()))
N = input_N_M[0]
M = input_N_M[1]
messages = []

for _ in range(M):
    messages.append(list(map(int, input().split())))

turing = messages[:N]
end_result = turing
more={}
for m in messages[N:]:
    more[str(m)]=1

pairs=[]
while len(turing)>1:
    if len(turing)>2:
        for i in range(len(turing)-1):
            pairs.append([turing[0],turing[i+1]])
        turing=turing[1:]

    else:
        pairs.append([turing[0],turing[1]])
        turing=turing[1:]

possibly_remove_pairs=[]
swapped_pairs=[]
result=[]

for p in pairs:
    if str([p[0][0], p[1][1]]) in more and str([p[1][0],p[0][1]]) in more:
        if more[str([p[0][0], p[1][1]])] == 1 and more[str([p[1][0],p[0][1]])]==1:
            more[str([p[0][0], p[1][1]])] = 0
            more[str([p[1][0],p[0][1]])] = 1
            end_result.remove([p[0][0], p[0][1]])
            end_result.remove([p[1][0], p[1][1]])
            possibly_remove_pairs.append([[p[0][0], p[0][1]],[p[1][0],p[1][1]]])
            result.append([p[0][0], p[1][1]])
            result.append([p[1][0], p[0][1]])
    
result.append(end_result[0])

if len(possibly_remove_pairs)==0:
    print (-1)
else:
    for p in result:
        print(int(p[0]), int(p[1]))

