/**
* user:  VR432075
* fname: BUSATTO
* lname: ALESSANDRO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 09:47:42.743954
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

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    //print_array(x, n);
    int B[n];
    B[0]=B0;
    for(int i = 1; i < n; i++)
      B[i]=0;
    //print_array(B,n);
    //int count=0;
    int res=0;
    for(int i = 0; i < n; i++){
      print_array(B,n);
      cout << "B "<< B[i] << endl;
      cout <<"i " << i<< endl;
      res=res+(B[i]+1)*(i+1);
      if(x[i]==0)
        B[i+1]=B[i]-1;
      else
        B[i+1]=B[i]+x[i];
      cout << "res: "<<res << endl;
    
    }
    cout << res << endl;
    return 0;
}

