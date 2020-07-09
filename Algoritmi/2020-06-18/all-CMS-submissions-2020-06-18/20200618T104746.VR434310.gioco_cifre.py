"""
* user:  VR434310
* fname: DI MATTEO
* lname: ROSARIO
* task:  gioco_cifre
* score: 0.0
* date:  2020-06-18 10:47:46.660342
"""
import math
paran= input()
t=input()
n=input()
e=input()
f=input()

if(t==1):
	print(e_controllo(n,e))
else:
	print(f_controllo(n,f))



def e_controllo(n,e):
	for i in range(len(n)):
		if (i!=0):
			if(e[i]==1):
				if(n[i]<n[math.trunc((i-1)/2)]):
					return 0
	return 1

def f_controllo(n,f):
	counter=0
	temp=0
	for i in range(len(n)):
		if(i!=0):
			if(check(n[math.trunc((i-1)/2)],n[i])):
				if(f[i]==0 and f[math.trunc((i-1)/2)] ==0):
					temp=n[i]
					n[i]=n[math.trunc((i-1)/2)]
					n[math.trunc((i-1)/2)]=temp
					i=0
				else:
					return 0
	return 1

		
		
		
		
def check(padre,figlio):
	if(padre>figlio):
		return true
	else :
		return false