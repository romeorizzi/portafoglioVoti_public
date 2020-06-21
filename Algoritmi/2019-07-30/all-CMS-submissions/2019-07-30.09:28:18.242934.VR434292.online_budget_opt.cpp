/**
* user:  VR434292
* fname: EMPORIO
* lname: MARCO
* task:  online_budget_opt
* score: 0.0
* date:  2019-07-30 09:28:18.242934
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

int n, B0, output_type, x[MAX_N], q[MAX_N], is_index_of_last_opportunity[MAX_N],maxbg;
long int y[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}
void funtype1(int b, int z){
  int bg2=b*q[z];
  bool cambio=true;
  if(bg2>maxbg){
    maxbg=bg2;
    cambio=false;
      }

      if(cambio)
	b=0;
      if(z+1<n)
	funtype1(b+x[z+1],z++);


}

int main() {
  int a=0;
    cin >> n >> B0 >> output_type;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    for(int i = 0; i < n; i++)
       cin >> q[i];
    //print_array(x, n);
    //print_array(q, n);

    y[0] = B0;
    for(int i = 1; i < n; i++)
      y[i] = x[i-1];

    if(output_type == 1)
      //type 1
      funtype1(B,0);
      cout << maxbg << endl;
    else
      //type 2
      print_array(y, n);

    return 0;
}

