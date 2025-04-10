/**
* user:  VR439205
* fname: LUMPP
* lname: FRANCESCO
* task:  online_budget
* score: 67.0
* date:  2019-07-30 10:56:23.166865
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
#include <fstream>
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

int ric(int j, int k, int ** val){
    if (val[j][k] != 0){ 
        return val[j][k];
    }
    if (j == n-1) {
        return k+1;
    }
    for (int i = 0; i<=k;i++){
        if (val[j][i] == 0) {
          val[j][i] = val[j][i-1];
          int ricRes = ric(j+1, i+x[j], val)%1000000007;
          val[j][i] += ricRes;
        }
    }
    return val[j][k];

}

int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++) {
      cin >> x[i];
    }

    int ** val = new int*[701];
    for (int i = 0; i < 701; i++) {
      val[i] = new int[51];
    }
    
    int res = ric(0, B0, val);

    cout << res << endl;
    return 0;
}

