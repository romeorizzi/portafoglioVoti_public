/**
* user:  VR433357
* fname: MOSCHIN
* lname: FEDERICO
* task:  online_budget
* score: 67.0
* date:  2019-07-30 07:50:14.546847
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

int n, B0, periodi[MAX_N];
int moditotali = 0;

void spese(int budget_rimasto,int p){
  //cout << "c" <<endl;
  if(budget_rimasto < 0){ //Soldi finiti
    return;
  }

   if(p == n){//finito i periodi con budget rimasto >=0
    moditotali++;
    return;
  }

  for(int i = 0; i<= budget_rimasto;i++){
    //cout << "Rimasto = "<< i<<endl;
    spese(budget_rimasto-i + periodi[p],p+1); 
  }

 

}

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int main() {
    cin >> n >> B0;
    //cout << n << " " << B0 << endl;
    for(int i = 0; i < n; i++)
       cin >> periodi[i];
    //print_array(periodi, n);

    spese(B0,0);

    cout << moditotali % 100000007 << endl;
    return 0;
}

