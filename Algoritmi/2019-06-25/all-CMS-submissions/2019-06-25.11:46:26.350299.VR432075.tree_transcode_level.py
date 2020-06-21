"""
* user:  VR432075
* fname: BUSATTO
* lname: ALESSANDRO
* task:  tree_transcode_level
* score: 0.0
* date:  2019-06-25 11:46:26.350299
"""
from __future__ import print_function
import sys
if sys.version_info<(3,0):
    input=raw_input

def rec_var1(array,res,prof,i):
    j=((array[i]-1)*2)+1
    res[i-1]=prof
    res[j]=prof
    if i != len(array):
        rec_var1(array, res, prof, i+1)
    

def var1(array):
    print("var1")
    res=[0]*(array[1]*2)
    rec_var1(array,res,0,1)
    return res

    pass

def var2(array):
    for x in array:
        
    print("var2")
    pass

def main():
  fin=open("input0.txt","r")
  fout=open("output.txt","w")
  r=fin.readlines()
  array = map(int, input().split())
  print(array)
  if(array[0]==1):
      res=var1(array)

  else:
      var2(array)
  fout.writelines(["%s " %i for i in res])

if __name__ == '__main__':
    main()