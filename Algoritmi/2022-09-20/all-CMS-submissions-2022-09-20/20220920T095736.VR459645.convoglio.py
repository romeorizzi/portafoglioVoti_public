"""
* user:  VR459645
* fname: FRANCESCA
* lname: ANNIBALETTI
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 09:57:36.910919
"""
#!/usr/bin/env python3

#input=open("input.txt","r")
#for line in input.readlines():
#    fields=line.split(" ")
#    input_array=fields
#input.close()

#f=open("output.txt", "w")
#f.write(str(15))
#f.close()


def attacco(mat_input, mat_ris, mat_turing, N, M, i, N_o):
    #controllo che quello che ho ottenuto non sia turing

    if N==0:
        is_eq=True
        j=0
        while(j<N_o):
            if(mat_ris[j][0]!=mat_turing[j][0] or mat_ris[j][1]!=mat_turing[j][1]):
                is_eq=False    
        if(is_eq==True):
            return -1

        j=0
        while(j<N_o):
            nave_attaccante=j
            nave_attaccata=mat_ris[j][1]
            print(str(nave_attaccante)+" "+str(nave_attaccata))
            j=j+1
        return 0
    if i>M-1:
        return -1
    
    mat_nonprendo=mat_ris
    #prendo, se posso prendere 
    nave_attaccante=mat_input[i][0]
    nave_attaccata=mat_input[i][1]

    if(mat_ris[nave_attaccante][0]==None):
        mat_ris[nave_attaccante][0]=nave_attaccante
        mat_ris[nave_attaccante][1]=nave_attaccata
        return max(attacco(mat_input, mat_ris, N-1, M, i+1),attacco(mat_input, mat_nonprendo, N, M, i+1))
    else:
        return attacco(mat_input, mat_nonprendo, N, M, i+1)
    
    
nm=list(map(int, input().split()))
n=nm[0]
m=nm[1]
mat_input=[[-1, -1]]*(m)
mat_turing=[[-1, -1]]*(n)
mat_ris=[[None for _ in range(2)]for _ in range (n)]

for i in range (m):
    mat_input[i]=list(map(int, input().split()))
for i in range (n): #memorizzo la prima corrispondenza
    mat_turing[i]=mat_input[i]

#S=list(map(int, input().split()))

if (m-n<n):
    print(-1)
else:
    a=attacco(mat_input, mat_ris, mat_turing, n, m-n, 0, n)
    if (a<0):
        print(-1)