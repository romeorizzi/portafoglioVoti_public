/**
* user:  VR434292
* fname: EMPORIO
* lname: MARCO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 08:38:23.168541
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
using namespace std;

const int MAX_N = 500;
const int MAX_VAL = 10;

int n, B0, x[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}
int fun (int b,int z){
  int res;
  /*if (b==0)
    return 1+x[z+1];*/
  for(int i=0;i<=b;i++){
    res++;
    if(z+1<n) 
      res += fun(b-i+x[z],z+1);
      }
  return res;
    
  }
int main() {
  int a=0;
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    // print_array(x, n);
      a= fun(B0,0);
      // if(B0==0 &&n==1 )
      //	a=1;


    cout << a << endl;
    return 0;
}

