/**
* user:  VR437058
* fname: BONETTI
* lname: LORENZO
* task:  online_budget_opt
* score: 75.0
* date:  2019-07-30 11:23:11.654448
*/
/**
 *  Template per soluzione in c++ per il problema online_bg_opt
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
using namespace std;

long int n,b0,t;
long int x[1000000];
long int q[1000000];
long int j[1000000];
long int b[1000000];
long int g;
long int bg;

int main() {
    cin >> n >> b0 >> t;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    for(int i = 0; i < n; i++)
       cin >> q[i];
    int i;
    j[n-1]= n-1;
    for(int i = n-2; i >=0; i--){
      if(q[i] < q[i+1]){
        q[i]= q[i+1];
        j[i] = j[i+1];
      }else{
        j[i] = i;
      }
    }
    
    g=0;
    bg=b0;
    for(int i = 0; i < n; i++){
      g += bg*q[i];
      b[j[i]] += bg;
      bg = x[i];
    }
    if(t==1){
      cout << g;
    }else{
      for(int i=0; i < n; i++){
        cout << b[i] << " ";
      }
    }
}

