/**
* user:  VR439870
* fname: SACCHETTO
* lname: LINDA
* task:  online_budget
* score: 0.0
* date:  2019-07-30 11:02:36.014006
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

int n, budget, x[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int main() {
    cin >> n >> budget;
    //printf("\nn ha valore:%d",n);
    //printf("\nbudget ha valore:%d",budget);
    int B[n];
    int count;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    for(int i = 0; i < n; i++)
       B[i]=0;
    //print_array(x, n);
    B[0]=budget;
    //printf("\nB posiz 0 ha valore:%d", B[0]);
    if(n==1){
      for(int y=0; y<=budget; y++){
        count++;
        //printf("\ncount ha valore:%d",count);
      }
    }
    else{
        for(int i=0; i<n; i++){
          for(int y=0; y<B[i]; y++){
          count+=(B[i]-y+x[i]);
          //printf("\ncount ha valore:%d",count);
          }
          if(i<n){
            B[i+1]=B[i]+x[i];
          }
        }
    }
    //printf("\ncount ha valore:%d\n",count);
    cout << endl;
    cout << count << endl;
    return 0;
}

