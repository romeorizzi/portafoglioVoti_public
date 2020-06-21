/**
* user:  VR439240
* fname: FATTORELLI
* lname: MARCO
* task:  online_budget
* score: 67.0
* date:  2019-07-30 09:52:05.896078
*/
#include <stdlib.h>
#include <fstream>
#include <cassert>
#include <iostream>

const int MAX_N = 701;
const int MAX_VAL = 51;
int par[MAX_VAL][MAX_N];
int n, B0, x[MAX_N];

using namespace std;

int ric(int pos,int bi){
    if(par[pos][bi] != 0){
        return par[pos][bi];
    }
    if(pos == n-1)
        return bi+1;
    for(int i =0; i <=bi; i++){
        if(par[pos][i] != 0)
            continue;
        par[pos][i] = (par[pos][i-1] + (ric(pos+1, i+x[pos]))%1000000007);
    }

    return par[pos][bi];
}

int main(void){
    cin >> n >> B0;
    for(int i = 0; i<n; i++){
    cin >> x[i];
    }
    int res = ric(0,B0);

    cout << res <<endl;
    return 0;
}
