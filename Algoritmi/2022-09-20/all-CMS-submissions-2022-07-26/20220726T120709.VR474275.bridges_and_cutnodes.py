"""
* user:  VR474275
* fname: MICHELE
* lname: QUARESMINI
* task:  esamebridges_and_cutnodes
* score: 0.0
* date:  2022-07-26 12:07:09.985617
"""
from functools import lru_cache


g, n, k = map(int, input().split())
arr = list(map(int, input().split()))

@lru_cache(maxsize = None)
def max_sequence(index, prev, k):
   global arr

   if index >= n:
      return 1
    
   noDrop = 0
   drop = 0
   leave = 0

   if arr[index] > prev:
      noDrop = 1 + max_sequence(index + 1, arr[index], k)


   leave = max_sequence(index + 1, prev, k)


   if k > 0 and arr[index] <= prev:
      drop = 1 + max_sequence(index + 1, arr[index], k - 1)


   return max(noDrop, leave, drop)

@lru_cache(maxsize = None)
def n_best_sol(index, prev, k, equals):
   if index >= n:
      return 1, 1
    
   noDrop = (0, 0)
   drop = (0, 0)
   leave = (0, 0)

   if arr[index] > prev:
      noDrop = n_best_sol(index + 1, arr[index], k, equals)


   leave = n_best_sol(index + 1, prev, k, equals)


   if k > 0 and arr[index] <= prev:
      drop = n_best_sol(index + 1, arr[index], k - 1, equals)


   max_val = max(1 + noDrop[0], leave[0], 1 + drop[0])
   temp = 0
   if max_val == (noDrop[0] + 1):
      temp += noDrop[1]
   if max_val == leave[0]:
      temp += leave[1]
   if max_val == (drop[0] + 1):
      temp += drop[1]
   return max_val, equals + temp
    



if g == 1:
   n_max = 0
   for i in range(1,n):
      if n_max > n-i:
         break
      n_max = max(n_max, max_sequence(i, arr[i-1], k))

   print(n_max)
    
if g == 2:
   n_seq_max = 0
   n_max = 0
   for i in range(1,n):

      fun = n_best_sol(i, arr[i-1], k, 0)
       
      if fun[0] == n_max:
         n_seq_max = (fun[1] + n_seq_max) % 1000000007
       
      if fun[0] > n_max:
         n_seq_max = fun[1] % 1000000007
         n_max = fun[0]

   print(n_seq_max)