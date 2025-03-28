"""
* user:  VR439678_id330ann
* fname: MATTEO
* lname: BALLAROTTO
* task:  risparmio
* score: 23.0
* date:  2020-07-14 12:33:51.585255
"""
#!/usr/bin/env python3
author: "Matteo Ballarotto"

def max_gap(arr, left, right):
    current_max = 0
    
    if arr[left] == 1:
        current_max = 1
    for i in range(left, right) : 
        if (arr[i] == 0 and arr[i+1] == 1):
            current_max += 1

    return current_max



                                    #----------- MAIN -----------

oper = []


line = input().split(" ")
N = int(line[0])
M = int(line[1])
luci = [0 for i in range(N)]
due = False

for op in range (M):
    line = input().split(" ")
    if (not due):
        if (int(line[0]) == 1):
            if (luci[int(line[1])] == 0):
                luci[int(line[1])] = 1
            else:
                luci[int(line[1])] = 0
        else:
            print (max_gap(luci, int(line[1]), int(line[2])))

    



