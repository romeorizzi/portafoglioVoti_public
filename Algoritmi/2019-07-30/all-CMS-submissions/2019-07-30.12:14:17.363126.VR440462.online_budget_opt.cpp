/**
* user:  VR440462
* fname: GOBBI
* lname: FRANCESCO
* task:  online_budget_opt
* score: 0.0
* date:  2019-07-30 12:14:17.363126
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <limits.h>
#include <stdlib.h>
#include <cassert>
#include <fstream>

using namespace std;


int n,B0, t;
long int x[5000000];
long int q[5000000];
long int vet[5000000];
long int vet2[5000000];


int main () {
  cin >>n>>B0>>t; //prendo in input

  for(int i = 0; i < n; i++) cin >> x[i]; //leggo il vettore dei guadagni
  for(int i = 0; i < n; i++) cin >> q[i]; //leggo le gemme

  vet[n-1] = n-1;
  for(int a = n-2; a>=0; a--) {
    if(q[a]<q[a+1]) {
        q[a]=q[a+1];
        vet[a]= vet[a+1];
    }
  }
  long int guadagno=0;
  long int soldi = B0; //parto da B0

  for(int a=0; a<n; a++) {
    guadagno = guadagno +q[a];//ovvero il possibile ricavo delle gemme
    vet2[vet[a]]= vet2[vet[a]]+soldi;
    soldi = soldi + x[a]; // perchè poi ho un accomulo all'interazione successiva
  }

  if(t==1) cout<<guadagno;
  if(t==2) {
    for(int a=0; a<n;a++) {
      cout << vet[a] << " ";
    }
  }
}