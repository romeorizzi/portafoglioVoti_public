/**
* user:  VR425328
* fname: MOUHAMED
* lname: FALL
* task:  online_budget
* score: 6.0
* date:  2019-07-30 11:17:19.052345
*/
#include <cassert>
#include <iostream>
using namespace std;

const int MAX_N = 500;


int n, B0, x[MAX_N];
int Ytot = 0;


void oBudg (int remN, int newBO, int posX){
  int newNewBO;
  for(int i=0; i<=newBO;i++){
    newNewBO= (-i +newBO);
    if(newNewBO>=0){
      if(remN==1)
      Ytot++;
      else
      oBudg(remN--, newNewBO+x[posX], posX++);
    }
  }
}

int main() {
    cin >> n >> B0;
    int allZero =1;



    for(int i = 0; i < n; i++)
       cin >> x[i];
    
    oBudg(n,B0,0);
    cout << Ytot%1000000007 << endl;
    return 0;
}

