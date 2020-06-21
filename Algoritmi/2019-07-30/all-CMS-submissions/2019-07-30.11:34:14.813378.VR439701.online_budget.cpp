/**
* user:  VR439701
* fname: PUGGIA
* lname: MATTIA
* task:  online_budget
* score: 0.0
* date:  2019-07-30 11:34:14.813378
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

const int L=10000;
const int MAX_N = 500;
const int MAX_VAL = 10;

int n, B0, x[MAX_N], risp;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

struct budget{
  int cont;
  int scelte[MAX_N];
  int old_budget[MAX_N];
  int new_budget[MAX_N];
} ;

budget budg[MAX_N];

budget scelte(int b, int x);

int main() {
  assert(freopen("input.txt","w",stdin));
  assert(freopen("output.txt","r",stdout));
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    //print_array(x, n);
    risp = 0;
    budg[0] = scelte(B0,x[0]);
    for(int i = 1; i < n; i++ ){
      for(int j = 0; j <= budg[i-1].cont; j++){
	budg[j+1] = scelte(budg[j].new_budget[j], x[i]);
      }            
     }

    cout << risp << endl;
    return 0;
}

budget scelte(int b, int x){
  budget i;
  i.cont = 0;
  //trova le spese possibili
  for(int j = 0; j <= b; j++){
    i.cont++;
    i.scelte[j] = j;
  }
  for(int k = 0; k <= i.cont; k++){
    //sottrae spese al budget
    if(b-i.scelte[k] >= 0)
      i.old_budget[k] = b - i.scelte[k];
    //calcola nuovo budget
    i.new_budget[k] = i.old_budget[k] + x;
  }
  risp =+ i.cont;
  return i;
}
