/**
* user:  VR439699
* fname: PIEROPAN
* lname: EDOARDO
* task:  online_budget
* score: 67.0
* date:  2019-07-30 11:11:04.194822
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
int counter=0;
int n, B0, aumenti[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

void rec(int B1, int v){
  if(v<n){
    for(int y=0; y<=B1;y++){
      int B=B1-y;
      rec(B+aumenti[v],v+1);
      }
    }else
      counter++;
  }

int main() {
  //ifstream fin("input4.txt");
  cin >> n >> B0;
  for(int i = 0; i < n; i++)
      cin >> aumenti[i];
  //print_array(aumenti, n);
  rec(B0,0);
  cout << (counter)%1000000007 << endl;
  return 0;
}

