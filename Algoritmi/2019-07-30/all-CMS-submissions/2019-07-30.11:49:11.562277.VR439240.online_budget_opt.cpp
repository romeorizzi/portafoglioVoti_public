/**
* user:  VR439240
* fname: FATTORELLI
* lname: MARCO
* task:  online_budget_opt
* score: 50.0
* date:  2019-07-30 11:49:11.562277
*/
#include <stdlib.h>
#include <fstream>
#include <cassert>
#include <iostream>

using namespace std;

long int n, B0, t;
long int x[100000],q[100000];
long int v[100000];
long int b[100000];


int main(void){
    int i;
    cin >> n >> B0 >> t;

    for(i=0; i < n; i++){
        cin >> x[i];
    }

    for(i=0; i < n; i++){
        cin >> q[i];
    }

    v[n-1] = n-1;
    for(int i = n-2; i>= 0; i--){
        if(q[i] < q[i+1]){
            q[i] = q[i+1];
            v[i] = v[i+1];
        }
    }

long int reward = 0;
long int bud = B0;

    for(int i = 0; i<n; i++){
        reward += bud*q[i];
        b[v[i]] += bud;
        bud = x[i];
    }

    if(t==1){
        cout << reward;
    } else{
        for(i = 0; i<n;i++){
            cout << b[i] << " ";
        }
    }
}
