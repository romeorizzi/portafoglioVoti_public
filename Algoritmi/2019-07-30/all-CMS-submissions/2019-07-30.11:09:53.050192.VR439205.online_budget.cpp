/**
* user:  VR439205
* fname: LUMPP
* lname: FRANCESCO
* task:  online_budget
* score: 67.0
* date:  2019-07-30 11:09:53.050192
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

const int MAXK = 701;
const int MAXJ = 51;
int n, B0, x[MAX_N];

int val[MAXJ][MAXK];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int ric(int j, int k){
    if (val[j][k] != 0){ 
        return val[j][k];
    }
    if (j == n-1) {
        return k+1;
    }
    for (int i = 0; i<=k;i++){
        if (val[j][i] == 0) {
          int ricRes = ric(j+1, i+x[j])%1000000007;
          val[j][i] = val[j][i-1]+ricRes;
        }
    }
    return val[j][k];

}

int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++) {
      cin >> x[i];
    
    }
    
    int res = ric(0, B0);

    cout << res << endl;
    return 0;
}

