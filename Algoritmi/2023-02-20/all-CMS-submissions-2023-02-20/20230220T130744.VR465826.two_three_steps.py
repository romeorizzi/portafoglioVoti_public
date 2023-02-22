"""
* user:  VR465826
* fname: FRANCESCO
* lname: BAZZANI
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 13:07:44.355129
"""
n = int(input())
val = map(int,input().split())

memo = {}


def sol(sequence: tuple):

    global memo

    if sequence in memo.keys():
        return memo[sequence]

    #print(f"chiamo dalla sequenza {sequence}")

    if len(sequence) == 3: 
        #print(f"ritorno {sequence[0]} + {sequence[-1]}")
        return sequence[0] + sequence[-1]
    
    if len(sequence) == 2: 
        #print(f"ritorno {sequence[0]} + {sequence[-1]}")
        return sequence[0] + sequence[-1]
    
    if len(sequence) < 2 and len(sequence) > 0:
        #print(f"ritorno {sequence[0]}")
        return sequence[0]
    



    initial = sequence[0]

    a = 0
    b = 0


    if len(sequence) >= 4:

        #print(f"Initial of {sequence[0]}")

        a = sol(sequence[2:])
        b = sol(sequence[3:])

    memo[sequence] = initial + max(a,b)
        
    return initial + max(a,b)


print(sol(tuple(val)))