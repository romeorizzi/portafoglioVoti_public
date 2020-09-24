"""
* user:  VR421455_id953lyb
* fname: NICOLA
* lname: DONATELLI
* task:  altopiano
* score: 25.0
* date:  2020-09-18 09:25:24.639972
"""
#!/usr/bin/python3

def modify(a, b):
    n_list[a] += b

def visit(a, b):
    max = 0
    found = False
    for i in range(a + 1, b):
        if(n_list[i - 1] == n_list[i] == n_list[i + 1]):
            if(found == False):
                max = n_list[i]
                found = True
            else:
                if(max < n_list[i]):
                    max = n_list[i]
    
    if(found == False):
        print("NESSUN_ALTOPIANO")
    else:
        print(max)
            

#lettura input
N, M = input().split()

n_list = list(map(int, input().split()))

operations = []
a = []
b = []

for i in range(int(M)):
    x, y, z = input().split()
    operations.append(x)
    a.append(y)
    b.append(z)

for i in range(int(M)):
    if(operations[i] == "1"):
        modify(int(a[i]), int(b[i]))
    elif(operations[i] == "2"):
        visit(int(a[i]), int(b[i]))
    else:
        pass
