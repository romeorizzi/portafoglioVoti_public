"""
* user:  esame_VR123456
* fname: TEST
* lname: MY
* task:  esame_linear_diff_constraints
* score: 0.0
* date:  2022-09-20 03:02:20.464040
"""
from grader import get_inputs, print_answer_and_exit
N,M,H,A,B,C = get_inputs()

# begin solution
for _ in range(N):
    for x,y,w in zip(A,B,C):
        #print(f"y={y}, x={x}, w={w}, H[y]={H[y]},  H[x]={H[x]}")
        H[y] = min(H[y],H[x]+w)
    #print("H={H}, sum(H)={sum(H)}")
answer = sum(H)
# end solution

print_answer_and_exit(answer)
