"""
* user:  VR481889
* fname: LORENZO
* lname: MIOSO
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 13:42:39.821810
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

f_in = open("input.txt", "r")
f_out = open("output.txt", "w")
#f_in = open("input1.txt", "r")
#f_out = open("output1.txt", "w")


N = int(f_in.readline())
quadri = list(map(int,f_in.readline().split()))
#print(quadri)

# sol esp
#def sol(index, count) :
#    if index >= N :
#        return count
#    else :
#        return max(
#                    sol(index + 2, quadri[index] + count),
#                    sol(index + 3, quadri[index] + count),
#                )

# sol lin 
count = [0] * N
count[2] = quadri[2]
count[3] = quadri[3]
count[4] = quadri[4] + count[2]
for i in range(5,N) :
    count[i] = quadri[i] + max(
                                count[i - 2],
                                count[i - 3],
                                )
    #print(count)


#print(sol(0,0))
#f_out.write(str(sol(0,0)))

#print(str(max(count)))

f_out.write(str(max(count)))


