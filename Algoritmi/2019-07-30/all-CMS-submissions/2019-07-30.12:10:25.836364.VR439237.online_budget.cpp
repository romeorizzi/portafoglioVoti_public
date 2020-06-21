/**
* user:  VR439237
* fname: DEPALO
* lname: CHRISTIAN
* task:  online_budget
* score: 6.0
* date:  2019-07-30 12:10:25.836364
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

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int main() {
    cin >> n >> B0;
    int total;

    if(n > 1) {
      total = 1;
    }
    
    else {
      total=0;
    }

    for(int i = 0; i < n; i++)
       cin >> x[i];
    //print_array(x, n);
    for(int i = 0; i < n; i++) { 
      for(int y = 0; y <= B0; y++) {
	if(B0 - y >= 0) {
	  total++;
	}
      }
      B0 += x[i];
    }
 
    cout << total << endl;
    return 0;
}

