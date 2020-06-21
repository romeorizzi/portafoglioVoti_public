/**
* user:  VR439699
* fname: PIEROPAN
* lname: EDOARDO
* task:  online_budget_opt
* score: 0.0
* date:  2019-07-30 12:06:04.012162
*/
/**
 *  Template per soluzione in c++ per il problema online_budget_opt
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
using namespace std;

const int MAX_N = 1000000;
const int MAX_VAL = 10;
int max[MAX_N]={};

int n, B0, output_type, x[MAX_N], q[MAX_N], is_index_of_last_opportunity[MAX_N];
long int y[MAX_N];
int val;
int counter=0;
int aumenti[MAX_N];
int tot=0,pq=0;
template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

void rec(int B1, int v){
  if(v>n){
    if(v==q[pq]){
      tot+=q[pq];
      pq++;
    }
    for(int y=0; y<=B1;y++){
      int B=B1-y;
      rec(B+aumenti[v],v+1);
      }
    }
  }


int main() {
    cin >> n >> B0 >> output_type;
    for(int i = 0; i < n; i++)
       cin >> aumenti[i];
    for(int i = 0; i < n; i++)
       cin >> q[i];
    //print_array(x, n);
    //print_array(q, n);

    y[0] = B0;
    for(int i = 1; i < n; i++)
      y[i] = x[i-1];

    if(output_type == 1){
     rec(B0,0);
     cout << tot << endl;
    }
    else
      cout<< val;

    return 0;
}

