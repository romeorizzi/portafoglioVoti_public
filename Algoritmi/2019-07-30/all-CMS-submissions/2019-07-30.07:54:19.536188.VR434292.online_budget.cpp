/**
* user:  VR434292
* fname: EMPORIO
* lname: MARCO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 07:54:19.536188
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

int n,a, B0, x[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}
int fun (int b,int z){
  int b1;
  for(int i=b;i<=b;i++){
    b1=b-i+x[z];
    return 1+ fun(b1,z+1);
      }
    
}
int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    //print_array(x, n);
    a= fun(B0,0);
    
    

    cout << a << endl;
    return 0;
}

