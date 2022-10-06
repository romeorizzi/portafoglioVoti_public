"""
* user:  VR474692
* fname: MASSIMO
* lname: MARTINI
* task:  esame_linear_diff_constraints
* score: 0.0
* date:  2022-09-20 12:04:12.292001
"""
#!/usr/bin/env python3

import sys

N,M=map(int,input().split())
h0,h1,h2,h3=map(int,input().split())

HMAX=h0+h1+h2+h3

Vincoli=[0]*M
vincolo=False
A=[]
B=[]
C=[]



for i in range(M):
        A1,B1,C1= map(int,input().split())
        A.append(A1)
        B.append(B1)
        C.append(C1)


for H0 in range(1,h0+1):
 for H1 in range(1,h1+1):
  for H2 in range(1,h2+1):
   for H3 in range(1,h3+1):

    vincoli=True
    Vincoli=[0]*M
    HTOT=H0+H1+H2+H3

    for i in range(M):
        A1=A[i]
        B1=B[i]
        C1=C[i]

        if B1 ==0:
            B1=H0
        elif B1 ==1:
            B1=H1
        elif B1 ==2:
            B1=H2
        elif B1 ==3:
            B1=H3

        if A1==0:
            A1=H0
        elif A1 ==1:
            A1=H1
        elif A1 ==2:
            A1=H2
        elif A1 ==3:
            A1=H3

        if (B1 <= A1 + C1):
          Vincoli[i]=1


    for v in Vincoli:
        if v==0:
            vincoli=False


    if vincoli==True:
       HMAX=HTOT


print(HMAX)
