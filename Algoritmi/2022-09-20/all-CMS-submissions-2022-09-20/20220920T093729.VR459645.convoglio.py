"""
* user:  VR459645
* fname: FRANCESCA
* lname: ANNIBALETTI
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 09:37:29.867502
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


def attacco(mat_input, mat_ris, N, M, i):
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
        return max(attacco(mat_input, mat_ris, N-1, M, i+1),attacco(mat_input, mat_nonprendo, N, M, i+1))
    else:
        return attacco(mat_input, mat_ris, N, M, i+1)
    #non prendo
    #mat_ris[mat_input[i][0]][0]==-1
    #mat_ris[mat_input[i][0]][1]==-1
    
    
nm=list(map(int, input().split()))
n=nm[0]
m=nm[1]
mat_input=[[-1, -1]]*(m-n+1)
mat_ris=[[None for _ in range(2)]for _ in range (n+1)]


for i in range (n): #tolgo i primi n, che hanno già una corrispondenza
    a=list(map(int, input().split()))
for i in range (m-n):
    mat_input[i]=list(map(int, input().split()))

#S=list(map(int, input().split()))

if (m-n<n):
    print(-1)
else:
    a=attacco(mat_input, mat_ris, n, m-n, 0)
    if (a==-1):
        print(-1)