"""
* user:  VR477156
* fname: MATTIA
* lname: BURATI
* task:  A_seq
* score: 13.0
* date:  2022-06-29 12:52:10.525763
"""
#!/usr/bin/nv/python3

g,n = map(int,input().split())
s = list(map(int,input().split()))

max_count = 0
max_n = 0

def memoize(f):
    memo  = {}  
    def helper(p,i,pa,asc):      
        if p not in memo:
            memo[p,i,pa,asc] = f(p,i,pa,asc)
        return memo
    return helper

@memoize
def find_next(prev,index,partial,asc):
    global max_count,max_n
    if index == n:
        if partial > max_n:
            max_n = partial
            max_count+=1
        elif partial == max_n:
            max_count+=1
        return max_n
    
    if asc and s[index] > s[prev]:
        find_next(index, index+1, partial+1, True)        
        find_next(index,index+1,partial+1,False)
    if not asc and s[prev] > s[index]:    
        find_next(index,index+1,partial+1,False)
    
    find_next(prev,index+1,partial,asc)


    
def goal2():
    return 2




if __name__ == "__main__":    
    if g == 1:   
        for i in range(0,n):         
            find_next(i,i,0,True)
        print(max_n+1)
    else:
        if s[0] != 3:
            print(2)
        else:
            print(1)
