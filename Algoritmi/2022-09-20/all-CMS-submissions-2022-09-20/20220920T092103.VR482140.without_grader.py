"""
* user:  VR482140
* fname: ELISA
* lname: ZANELLA
* task:  esame_without_grader
* score: 0.0
* date:  2022-09-20 09:21:03.259429
"""
#!/usr/bin/env python3
def max_sum_h(h, va, vb, vc, h_ini):
    print("Dentro sum")
    for i in range(len(va)):
        if (vb[i] <= va[i] + vc[i]) == False:
            h[vb[i]] = h[vb[i]] - (h[vb[i]] - (h[va[i]] + vc[i]))
        #print(h)
        #print(sum(h))
    #print(h)
    #print(h_ini)
    return sum(h)



N, M = map(int, input().split())
h = list(map(int, input().split()))
h_ini = h.copy()
va = []
vb = []
vc = []
#print(N, M, h)
for i in range(M):
    a, b, c = map(int, input().split())
 #   print(a, b, c)
    va.append(a)
    vb.append(b)
    vc.append(c)
    if (h[b] <= h[a] + c) == False:
        h[b] = h[b] - (h[b] - (h[a] + c))
  #  print(f'{h}')
    
print(max_sum_h(h, va, vb, vc, h_ini))
