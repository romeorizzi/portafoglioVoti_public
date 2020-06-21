/**
* user:  VR434292
* fname: EMPORIO
* lname: MARCO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 10:15:47.832307
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

int n, B0, output_type, x[MAX_N], q[MAX_N], is_index_of_last_opportunity[MAX_N],maxbg,zmax;
long int y[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}
void trovamax(int b, int z){
  int bg2=b*q[z];

  if(bg2>maxbg){
    maxbg=bg2;
    zmax=z;
      }

      if(z+1<n)
	trovamax(b+x[z+1],z++);
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
    trovamax(B0,0);
    if(output_type == 1){
      //type 1
      a=maxbg;
      maxbg=0;
      while(zmax+1<n){
	trovamax(0,zmax);
	  a+=maxbg;
	}
      cout << a << endl;
    }
    else{
      //type 2
      print_array(y, n);
    }
    return 0;
}

