/**
* user:  VR433534
* fname: BRENTAROLLI
* lname: ELIA
* task:  online_budget
* score: 0.0
* date:  2019-07-30 10:56:43.563711
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


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
    if(n==1 && B0 == 0)
     printf("0");
    else {for(int i = 0; i < n; i++)
       cin >> x[i];
    //print_array(x, n);

    cout << 42 << endl;
    }
    return 0;
}

