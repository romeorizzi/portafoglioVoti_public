"""
* user:  VR459645
* fname: FRANCESCA
* lname: ANNIBALETTI
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 11:20:06.343329
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

def is_equal(mat1,mat2,n):
    is_eq=True
    for i in range (n):
        if (mat1[0]!=mat2[0] or mat1[1]!=mat2[1]):
            return False
    return True


def attacco(mat_input, mat_ris, mat_turing, N, M, i, Ni):
    if N==0:
        j=0
        while(mat_ris[j][0]!=None):
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
        return max(attacco(mat_input, mat_ris, mat_turing, N-1, M, i+1, Ni), attacco(mat_input, mat_nonprendo, mat_turing, N, M, i+1, Ni))
    else:
        return attacco(mat_input, mat_nonprendo, mat_turing, N, M, i+1, Ni)
    
    
nm=list(map(int, input().split()))
n=nm[0]
m=nm[1]
mat_input=[[-1, -1]]*(m+1)
mat_input2=[[-1, -1]]*(m+1)
mat_ris=[[None for _ in range(2)]for _ in range (n+1)]
mat_turing=[[None for _ in range(2)]for _ in range (n+1)]


for i in range (m):
    mat_input[i]=list(map(int, input().split()))
for i in range (n):
    mat_turing[i]=mat_input[i]

for i in range (n, m):
    mat_input2[i-n]=mat_input[i]
for i in range (n):
    mat_input2[i+n]=mat_input[i]
#costruisco un altro input che mi faccia avere come prima soluzione preferibilmente non turing

#S=list(map(int, input().split()))

if (m-n<n):
    print(-1)
else:
    a=attacco(mat_input2, mat_ris, mat_turing, n, m, 0, n)
    if (a==-1):
        print(-1)