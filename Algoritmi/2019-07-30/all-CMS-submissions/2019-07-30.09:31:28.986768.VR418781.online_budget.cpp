/**
* user:  VR418781
* fname: BRENTEGANI
* lname: MATTEO
* task:  online_budget
* score: 5.0
* date:  2019-07-30 09:31:28.986768
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
int store[MAX_N];
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
    //spendo un numero di monete pari a n+1 se ho 5 monete ho 6 combinazioni
    if (i == n || B==0){ }
    else {
        
        if (store[B] == -1) {
            for (int k = B; k >= 0; k--) {
                n_spese++;
                spendo_monete(guadagno_monete(k, i), i+1);
                store[B]= n_spese; 
            }
        } 
        else {n_spese = n_spese + store[B];}  
    }

}

int main() {
    
    for(int i = 0; i < 200; i++)
        store[i] = -1;

    cin >> n >> B;

    for(int i = 0; i < n; i++)
       cin >> x[i];
    //print_array(x, n);

    spendo_monete(B, 0);

    cout << n_spese % 1000000007 << endl;
    return 0;
}


/*                                                                                                                                                                                                                                                                                                                                                               
                                    0           1               2
                            0   1   2       0       1       0   1   2
                        0       01 012      0       01      0   01  012

                        000
                        001
                        010
                        011
                        100
                        110
                        111
                        200
                        020
                        002                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

                        3*2 6
                        2*2 4
                        2*1 2
                        2*0 0 
  */                      
