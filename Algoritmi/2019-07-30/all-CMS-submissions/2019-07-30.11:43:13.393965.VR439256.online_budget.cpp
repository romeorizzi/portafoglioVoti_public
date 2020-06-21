/**
* user:  VR439256
* fname: MORI
* lname: SAMUELE
* task:  online_budget
* score: 67.0
* date:  2019-07-30 11:43:13.393965
*/
/**
 *  Online budget
 *  Mori Samuele, VR439256, 2019-07-30
 */
#include <cassert>
#include <iostream>
using namespace std;

const int MAX_N = 500;
const int MAX_VAL = 10;

int n, B0, x[MAX_N];
int i, k, s = 0, c = 0;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int rec(int budget, int it){
  if(it < n) {
    int j;
    budget += x[it-1];
    it++;
    
    for(j=0; j<=budget; j++) {
      rec(budget-j, it);
    }
  } else {
    ++c;
    return 0;
  }
}

int main() {
    cin >> n >> B0;
    for(i = 0; i < n; i++)
       cin >> x[i];

    for(i = 0; i <= B0; i++){
      rec(B0-i, 1);
    }

    cout << c << endl;
    return 0;
}
