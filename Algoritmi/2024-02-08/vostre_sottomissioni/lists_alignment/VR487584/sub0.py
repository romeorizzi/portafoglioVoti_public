import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)


tests=input()

global numbs,AD,AU


    
global fin_au, fin_ad
def main(l1,l2,a1,a2):
    memo=[[None]*(501)for _ in range(501)]

    def liste(a1,a2,u=0,d=0):
        if u==l1 or d==l2:
            return 0
        if memo[u][d] is not None:
            return memo[u][d]

        res1 = min(a1[u],a2[d]) + liste(a1,a2,u+1,d+1)
        res2 = liste(a1,a2,u,d+1)
        res3 = liste(a1,a2,u+1,d)
        memo[u][d]= max(res1,res2,res3)
        return memo[u][d]

    return liste(a1,a2)

numbs=''
AU=''
AD=''
for i in range(int(tests)):
    numbs=input()
    AU, AD=map(int,numbs.split())

    au=input()
    arr_AU= list(map(int, au.split()))
    ad=input()
    arr_AD=list(map(int, ad.split()))

    print(main(AU,AD, arr_AU,arr_AD))
    print("")
    print("")
""" print(main(7,8,[101,102,103,104,105,106,107],[21,52,33,74,15,46,67,88])) """