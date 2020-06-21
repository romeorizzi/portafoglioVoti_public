/**
* user:  VR425328
* fname: MOUHAMED
* lname: FALL
* task:  online_budget
* score: 67.0
* date:  2019-07-30 11:14:00.054190
*/
#include <cassert>
#include <iostream>
using namespace std;

const int MAX_N = 500;


int n, B0, x[MAX_N];
int YiTot = 0;

/*template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}*/

void oBudg (int remN, int newBO, int posX){
  int newNewBO;
  for(int i=0; i<=newBO;i++){
    newNewBO= (-i +newBO);
    if(newNewBO>=0){
      if(remN==1)
      YiTot++;
      else
      oBudg(remN-1, newNewBO+x[posX], posX+1);
    }
  }
}

int main() {
    cin >> n >> B0;
    int allZero =1;



    for(int i = 0; i < n; i++)
       cin >> x[i];
    
    oBudg(n,B0,0);
    cout << YiTot%1000000007 << endl;
    return 0;
}

