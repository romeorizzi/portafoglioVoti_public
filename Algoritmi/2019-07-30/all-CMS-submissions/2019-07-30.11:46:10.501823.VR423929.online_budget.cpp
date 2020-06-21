/**
* user:  VR423929
* fname: BRAGAGLIO
* lname: MORENO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 11:46:10.501823
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


void boh(int remN, int newB0, int posX){
  for(int i = 0; i <= newB0; i++){ 
    //if(-i+newB0>=0){
      (remN==1) ? YiTot++ : boh(remN-1, -i+newB0+x[posX], posX+1);
    //}   
  }
}

int main() {
    cin >> n >> B0;
   

    for(int j = 0; j < n; j++)
       cin >> x[j];
     boh(n, B0, 0); // il terzo valore è la posizione in x[]
  
 
    cout << YiTot%1000000007 << endl;


    return 0;
}

