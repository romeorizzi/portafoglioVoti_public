"""
* user:  VR451051
* fname: BODINI
* lname: ALESSIA
* task:  gioco_cifre
* score: 40.0
* date:  2020-06-18 12:51:37.975082
"""
def estrai_cifre(N):
    cifre = []
    non_zeri = 0
    while int(N) != 0:
        cifre.append(int(N % 10))
        if N % 10 != 0:
            non_zeri += 1
        N = N/10
    return cifre, non_zeri


N = int(input())

cifre, non_zeri = estrai_cifre(N)
#print(cifre)

if non_zeri % 2 == 0 or (len(cifre) - non_zeri) % 2 == 0:
    print(1, cifre[0])
else:
    print(0)
