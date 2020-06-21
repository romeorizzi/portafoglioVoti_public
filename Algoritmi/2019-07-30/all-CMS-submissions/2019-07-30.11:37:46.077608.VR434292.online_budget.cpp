/**
* user:  VR434292
* fname: EMPORIO
* lname: MARCO
* task:  online_budget
* score: 67.0
* date:  2019-07-30 11:37:46.077608
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
int Yim=0;

/*template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
  }*/
void fun (int remN,int b,int posx){
  for(int i=0;i<=b;i++){

    if (b-i>=0){
      if(remN==1)
	Yim++;
      else
	fun(remN-1 , b-i+x[posx] , posx+1);
     }
  }
 }

int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    // print_array(x, n);
    fun(n,B0,0);

    cout << Yim%1000000007 << endl;
    return 0;
}

