"""
* user:  VR434310
* fname: DI MATTEO
* lname: ROSARIO
* task:  gioco_cifre
* score: 0.0
* date:  2020-06-18 11:42:53.391449
"""
#!/usr/bin/python3
import math
paran,t= map(int, input().split())
n=list(map(int, input().split()))
e=list(map(int, input().split()))
f=list(map(int, input().split()))

if(t==1):
	print(e_controllo(n,e))
else:
	print(f_controllo(n,f,e))



def e_controllo(n,e):
	for i in range(len(n)):
		if (i!=0):
			if(e[i]==1):
				if(n[i]<n[math.trunc((i-1)/2)]):
					return 0
	return 1

def f_controllo(n,f,e):
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
	return e_controllo(n,e)

		
		
		
		
def check(padre,figlio):
	if(padre>figlio):
		return true
	else :
		return false