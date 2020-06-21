/**
* user:  VR437058
* fname: BONETTI
* lname: LORENZO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 09:50:55.343618
*/
/**
 *  Template per soluzione in c++ per il problema tree_transcode_disc
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <limits.h>
#include <string>
using namespace std;



vector<int> fig[10000000];
int nfig[10000000];
int nNodes=0;

int Type_one(int node){
  int numfig;
  cin >> numfig;
  nfig[node] = numfig;
  numfig = numfig - 1;

  int smallTree = 0;
  while(smallTree < numfig){
    nNodes++;
    fig[node].push_back(nNodes);
    smallTree = smallTree + Type_one(nNodes);
  }
  return nfig[node];
}

void print2(int node){
  int i = 0;
  for(i = 0; i < fig[node].size();i++){
    int figo = fig[node][i];
    print2(figo);
  }
  cout << nfig[node] << " ";
}

int main(){

  int tipo;
  cin >> tipo;
  if(tipo == 1){
    Type_one(0);
    cout << "2 ";
    print2(0);
  }
  cout << endl;


}

