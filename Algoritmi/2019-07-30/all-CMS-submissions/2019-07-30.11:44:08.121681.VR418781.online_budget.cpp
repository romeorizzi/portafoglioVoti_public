/**
* user:  VR418781
* fname: BRENTEGANI
* lname: MATTEO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 11:44:08.121681
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;                             

const int MAX_N = 500;
const int MAX_VAL = 10;

int n, B, x[MAX_N], monete;
int valori[MAX_N];
int store[200][50];
int n_spese;


template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int guadagno_monete(int B, int i) {
    return B + x[i];
}
void spendo_monete(int B, int i) {   
    if (i == n ){
        n_spese = (n_spese % 1000000007)+1;
    } else {
            for (int k = B; k >= 0; k--) {
               spendo_monete(guadagno_monete(k, i), i+1);
            }
        } 
    }
}
  
int main() {
    
    for(int i = 0; i < 200; i++)
        for (int j = 0; j < 50; j++)
            store[i][j] = -1;

    cin >> n >> B;

    for(int i = 0; i < n; i++)
       cin >> x[i];

    spendo_monete(B, 0, 0);
    cout << n_spese % 1000000007 << endl;
    return 0;
}