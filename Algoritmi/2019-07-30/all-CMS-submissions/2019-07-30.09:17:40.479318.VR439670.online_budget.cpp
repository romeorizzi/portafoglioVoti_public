/**
* user:  VR439670
* fname: LUCCHESE
* lname: MARCO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 09:17:40.479318
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
int B[MAX_N];
template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++){
    cout <<  v[i] << " ";
    for(int u=i+1; u<len;){
      B[u]=B[i]+v[i];
    }
  }
  for(int i=0;i<len;i++){
    cout<<B[i];
  }
}

int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    print_array(x, n);

    //cout << 42 << endl;
    return 0;
}

