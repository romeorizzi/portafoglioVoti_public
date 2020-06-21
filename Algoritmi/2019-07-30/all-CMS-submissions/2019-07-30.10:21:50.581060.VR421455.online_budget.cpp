/**
* user:  VR421455
* fname: DONATELLI
* lname: NICOLA
* task:  online_budget
* score: 6.0
* date:  2019-07-30 10:21:50.581060
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

const int MAX_N = 50;
const int MAX_VAL = 10;

int n, B0, x[MAX_N];
int s;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

/*int calcolo(T *x, int n){
  for(int i=0; i < n; i++)
    if(n == 1)
      return B0;
    else
      return x[i] + calcolo(n-1);
}*/

int main() {
    s = 0;
    cin >> n >> B0;
    assert (n <= MAX_N);
    assert (B0 >= 0 && B0 <= 200);

    for(int i = 0; i < n; i++){
       cin >> x[i];
       assert (x[i] >= 0 && x[i] <= 10);
    }
    //print_array(x, n);
    //soluzione

    //ciclo per il numero di n periodi
    for(int i=0; i < n; ++i){
      //if(i == 0){
        for(int j=B0; j >= 0; --j)
          //calcola(j);
          s++;
        
        //cout << "B0 (prima)= " << B0 << endl;

        //for(int h=0; h < x[i])
        B0 += x[i];
        //cout << "B0 = " << B0 << endl;
        //s++;
        /*
        for(int j=0; j < x[i]; ++j)
          if(B0 - j > 0)
            s++;
            */
      /*}
      else{

      }*/
    }

    
    cout << s % 1000000007 << endl;



    return 0;
}

