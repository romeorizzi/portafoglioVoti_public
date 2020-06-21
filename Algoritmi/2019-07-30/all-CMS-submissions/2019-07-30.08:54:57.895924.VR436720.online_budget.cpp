/**
* user:  VR436720
* fname: BERTI
* lname: MARCO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 08:54:57.895924
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
    for(int i = 0; i < n; i++)
      cin >> x[i];
    //print_array(x, n);

    // for(int i = 0; i < n; i++) {
    //   int y = 0;
    //   while(B0 >= 0) {
    //     B0 = B0-
    //   }
    // }

    cout << 42 << endl;
    return 0;
}

/*ciclo 1
b0=2
y1=0

b1=2
x1=0
y2=0

b2=2
x2=0
y3=0

b0=2
y1=1

b0=1
x1=0
y2=0



y1= 0
y2= 0,1,2
y3= 0,1,2

y1= 0,1
y2= 0,1,2,3
y3= 0,1,2,3 */
