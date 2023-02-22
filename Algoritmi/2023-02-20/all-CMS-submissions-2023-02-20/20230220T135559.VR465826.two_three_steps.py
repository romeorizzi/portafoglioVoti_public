"""
* user:  VR465826
* fname: FRANCESCO
* lname: BAZZANI
* task:  esame_two_three_steps
* score: 25.0
* date:  2023-02-20 13:55:59.663809
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-


def read_text():
    
    with open('input.txt', 'r') as file:
        lines = file.readlines()

        for index, line in enumerate(lines):
            if index == 0:
                n = list(map(int, line.strip().split()))

            else:
                val = tuple(map(int, line.strip().split()))

    return n, val

def write_text(output):

    with open('output.txt', 'w') as f:
        f.write(str(output))



#n = int(input())
#val = map(int,input().split())

def sol3(sequence, memo={}):

    if sequence in memo.keys():
        return memo[sequence]

    if len(sequence) == 0:

        memo[sequence] = [0]
        return [0]

    elif len(sequence) == 1:
        memo[sequence] = [sequence[0]]

        return [sequence[0]]

    elif len(sequence) == 2:
        tmp = []
        a = sol3(sequence[2:])
        for i in a:
            tmp.append(sequence[0]+i)
        
        memo[sequence] = tmp
        return tmp
    else:
        tmp = []
        a = sol3(sequence[2:])
        for i in a:
            tmp.append(sequence[0]+i)
        b = sol3(sequence[3:])
        for i in b:
            tmp.append(sequence[0]+i)

        memo[sequence] = tmp
        
        return tmp


def sol(sequence: tuple):

    #if sequence in memo.keys(): return memo[sequence]

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

    #memo[sequence] = initial + max(a,b)
        
    return initial + max(a,b)


def sol2(sequence):

    dp = [0]*len(sequence)

    for i in range(len(sequence)):
        if i + 2 < len(sequence):
            dp[i+2] = max(dp[i+2], dp[i]+sequence[i+2])

        if i + 3 < len(sequence):
            dp[i+3] = max(dp[i+3], dp[i]+sequence[i+3])
    
    return max(dp)


def main():

    n, val = read_text()
    out = sol3(val)
    write_text(max(out))



if __name__ == '__main__':

    main()

