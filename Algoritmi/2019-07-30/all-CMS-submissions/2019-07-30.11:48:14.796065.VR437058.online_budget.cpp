/**
* user:  VR437058
* fname: BONETTI
* lname: LORENZO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 11:48:14.796065
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

int n, B0, x[MAX_N], y[MAX_N], S, j, b_i, count, k;
int pos_val[1000][1000];
int B[MAX_N];
bool t;



int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
      cin >> x[i];
    
    
    S = 0;
    B[n-1] = B0;
    for(int i = n - 2; i >=0; i--){
        B[i] = B[i + 1];
    }

    count = 0;
    for(int i = n - 1; i >= 0; i--){
      for(int j = 0; j < B[i]; j++){
        count += (j + 2);
      }
    }

    //print_array(x, n);
    cout << count % 1000000007 << endl;
    return 0;
}

