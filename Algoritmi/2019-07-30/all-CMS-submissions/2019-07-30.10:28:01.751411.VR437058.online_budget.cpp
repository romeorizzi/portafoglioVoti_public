/**
* user:  VR437058
* fname: BONETTI
* lname: LORENZO
* task:  online_budget
* score: 1.0
* date:  2019-07-30 10:28:01.751411
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

int n, B0, x[MAX_N], y[MAX_N], S, j, b_i, count;
int pos_val[1000][1000];
int B[MAX_N][MAX_N];
bool t;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
      cin >> x[i];
    
    B[0][0] = B0;
    S = 0;
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
          pos_val[i][j] = 0;
          B[i][j] = 0;
        }
    }


    for(int i = 1; i <= n; i++){
      t = true;
      count = 0;
      j = 0;

      while (t == true){
        if(B[i-1][j] - j >= 0){
          pos_val[i-1][j] = j;
          count++;
          B[i][j] = B[i-1][j] - j + x[i];
          j++;
        }else{
          t = false;
        }
      }
    }
    

    //print_array(x, n);
    cout << count << endl;
    return 0;
}

