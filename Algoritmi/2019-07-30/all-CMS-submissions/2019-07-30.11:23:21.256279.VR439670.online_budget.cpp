/**
* user:  VR439670
* fname: LUCCHESE
* lname: MARCO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 11:23:21.256279
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
int res=0;
int n, B0, x[MAX_N];

template <class T>
void print_array(T *v, int len) {

  /*for(int i = 0; i < len; i++){
    //cout <<  v[i] << " "; 
    if(n==2){
      for(int iv=0;iv<=B0;iv++){
        for(int ivv=0;ivv<=B0;ivv++){
          res+=2;
        }
      }
    }
    else{
      for(int u=0; u<=v[i]; u++){
        res++;
      }
    }
  }*/
  for(int i =0;i<B0;i++){
    for(int u=0;u<len;u++){
      for(int k=0; k<=v[i]; k++){
        res+=B0;
      }
  }
  }
}



int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    print_array(x, n);
    cout << res%1000000007 << endl;
    return 0;
}

