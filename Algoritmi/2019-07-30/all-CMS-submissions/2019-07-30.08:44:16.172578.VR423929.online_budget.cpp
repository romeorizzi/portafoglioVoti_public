/**
* user:  VR423929
* fname: BRAGAGLIO
* lname: MORENO
* task:  online_budget
* score: 67.0
* date:  2019-07-30 08:44:16.172578
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
int YiTot = 0;

// template <class T>
// void print_array(T *v, int len) {
//   for(int i = 0; i < len; i++)
//     cout <<  v[i] << " ";
//   cout << endl;
// }

void boh(int remN, int newB0, int posX){
  int newNewB0;
  for(int i = 0; i <= newB0; i++){
    newNewB0=(-i+newB0);  
    if(newNewB0>=0){
      if(remN==1)
        YiTot+=1;
      else
        boh(remN-1, newNewB0+x[posX], posX+1);
    }   
  }
}

int main() {
    cin >> n >> B0;
    for(int j = 0; j < n; j++)
       cin >> x[j];
    //print_array(x, n);

    boh(n, B0, 0); // il terzo valore è la posizione in x[]
    cout << YiTot%1000000007 << endl;


    return 0;
}

