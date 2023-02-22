"""
* user:  VR481889
* fname: LORENZO
* lname: MIOSO
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 13:38:23.868163
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

f_in = open("input.txt", "r")
f_out = open("output.txt", "w")
#f_in = open("input0.txt", "r")
#f_out = open("output0.txt", "w")


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
for i in range(N) :
    if i == 2 :
        count[i] = quadri[i]
    if i == 3 :
        count[i] = quadri[i]
    if i == 4 :
        count[i] = quadri[i] + count[i - 2]
    if i > 4 :
        count[i] = max(
                        quadri[i] + count[i - 2],
                        quadri[i] + count[i - 3]
                       )
    #print(count)


#print(sol(0,0))
#f_out.write(str(sol(0,0)))

#print(str(max(count)))

f_out.write(str(max(count)))


