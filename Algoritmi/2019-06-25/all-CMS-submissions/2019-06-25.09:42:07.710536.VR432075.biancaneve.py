"""
* user:  VR432075
* fname: BUSATTO
* lname: ALESSANDRO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 09:42:07.710536
"""
def scambia(nani,p1,p2):
    x=nani[p1-1]
    nani[p1-1]=nani[p2-1]
    nani[p2-1]=x

def check(nani, h1, h2):
    num_nani=h2-h1+1
    total=0
    y=len(nani)+1
    prefix_sum=[0]*y
    inv_prefix_sum=[0]*y
    for i in range(0,y-1):
        prefix_sum[i+1]=prefix_sum[i]+int(nani[i])

    for i in range(h1,h2+1):
        total += i
    i=len(prefix_sum)-1
    print(num_nani, prefix_sum, len(prefix_sum))
    while i-num_nani >= 0:
        print(prefix_sum[i],"-",prefix_sum[i-num_nani])
        if(prefix_sum[i]-prefix_sum[i-num_nani]==total):
            return 1
        i=i-1
    return 0


def main():
    r1=input("Inserisci n e m separati da uno spazio bianco: ")
    split=r1.split(" ")
    n=int(split[0])
    m=int(split[1])
    disp_nani=input("Inserisci disposizione nani (interi separati da spazio): ")
    nani=disp_nani.split(" ")
    for i in range(0,m):
        r=input("Inserisci richiesta (tipo p1 p2): ")
        r_split=r.split(" ")
        t=int(r_split[0])
        p1=int(r_split[1])
        p2=int(r_split[2])
        if t==1:
            scambia(nani,p1,p2)
        else:
            res=check(nani,p1,p2)
            if res==1:
                print("YES")
            else:
                print("NO")

if __name__ == '__main__':
    main()