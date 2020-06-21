/**
* user:  VR439205
* fname: LUMPP
* lname: FRANCESCO
* task:  online_budget
* score: 6.0
* date:  2019-07-30 10:10:03.100545
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

int n, B0, x[MAX_N], arr[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int calc(int j, int k, int ** val){
    int ** updPtr = val+(j*100+k);
    int value = **updPtr;
    if (value != 0) {
      return value;
    }
    if (j == n-1) {
      return k+1;
    }    
    for (int i = 0; i<=k;i++){
        if (**val == 0){
          int newval = val[j][i-1];
          int ** ptr2 = val+(j*100+i);
          **ptr2 = (newval+calc(j+1, i+x[j], val))%1000000007;
          }        
    }
    return value;
}

int main() {
    ifstream fin("input3.txt");
    ofstream fout("output.txt");

    cin >> n >> B0;
    for(int i = 0; i < n; i++) {
      cin >> x[i];
    }
    int ** val;
    val = new int*[1000];
    for (int i = 0; i < 1000; i++) {
      val[i] = new int[100];
    }

    int res = calc(0, B0, val);

    cout << res << endl;
    return 0;
}

