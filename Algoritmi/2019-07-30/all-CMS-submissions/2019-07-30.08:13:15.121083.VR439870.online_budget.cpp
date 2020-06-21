/**
* user:  VR439870
* fname: SACCHETTO
* lname: LINDA
* task:  online_budget
* score: 0.0
* date:  2019-07-30 08:13:15.121083
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
    int count=0;
    int budget;
    int y;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    print_array(x, n);
    for(int i=0; i<n; i++){
      B0+=x[i];
      budget=B0;
      y=0;
      while(budget>0){
        budget-=y;
        y++;
        count++;
      }
    }

    cout << count%1000000007 << endl;
    return 0;
}

