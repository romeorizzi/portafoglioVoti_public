/**
* user:  VR437058
* fname: BONETTI
* lname: LORENZO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 11:16:56.148045
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
    for(int i = 0; i <= MAX_N; i++){
        B[i] = 0;
    }
    B[0] = B0;

    for(int i = 1; i <= n; i++){
      k = B[i - 1];
      for(int j = 0; j < k; j++){
        B[j] = k - j;
      }

      
    }
    count = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < B[i]; j++){
        count += (j);
      }
    }

    //print_array(x, n);
    cout << count << endl;
    return 0;
}

