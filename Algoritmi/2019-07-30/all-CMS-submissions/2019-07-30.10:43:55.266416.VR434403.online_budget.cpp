/**
* user:  VR434403
* fname: CROSARA
* lname: MARCO
* task:  online_budget
* score: 38.0
* date:  2019-07-30 10:43:55.266416
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

int fun(int val, int level){
  if(level == 0){
    return 1;
  }

  int result = 0;
  for(int i = 1; i <= val; i++){
    result += fun(i, level-1);
  }

  return result;
}

int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    //print_array(x, n);

    int value = fun(B0 + 1, n); // n = tempo

    cout << value << endl;
    return 0;
}

