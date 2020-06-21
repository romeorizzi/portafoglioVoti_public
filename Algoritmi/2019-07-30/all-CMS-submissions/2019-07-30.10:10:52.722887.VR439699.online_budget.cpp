/**
* user:  VR439699
* fname: PIEROPAN
* lname: EDOARDO
* task:  online_budget
* score: 1.0
* date:  2019-07-30 10:10:52.722887
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;

const int MAX_N = 500;
const int MAX_VAL = 10;
int n, B0, aumenti[MAX_N];
int counter=1;
int k=-1;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

void rec(int B1,int aumento){
  if(k<n){
  counter+=B1;
  for(int i=0; i<=B1; i++)
    rec(B1-i,aumenti[++k]);
  }
}

int main() {
  ifstream fin("input0.txt");
  fin >> n >> B0;
  for(int i = 0; i < n; i++)
      fin >> aumenti[i];
  //print_array(aumenti, n);
  rec(B0,0);

  cout << counter%1000000007 << endl;
  return 0;
}

