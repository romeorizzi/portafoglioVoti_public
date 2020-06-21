/**
* user:  VR439240
* fname: FATTORELLI
* lname: MARCO
* task:  online_budget
* score: 100.0
* date:  2019-07-30 11:53:39.140870
*/
//ES1 Fattorelli Marco
#include <stdlib.h>
#include <fstream>
#include <cassert>
#include <iostream>


const int MAX_N = 1001;
const int MAX_VAL = 101;
int parz[MAX_VAL][MAX_N];
int n, B0, x[MAX_N];

using namespace std;


int rec(int pos,int bi){
    if(parz[pos][bi] != 0){
        return parz[pos][bi];
    }
    if(pos == n-1)
        return bi+1;
    for(int i = 0; i <=bi; i++){
        if(parz[pos][i] != 0)
            continue;
        parz[pos][i] = (parz[pos][i-1] + rec(pos+1, i+x[pos]))%1000000007;
    }
    return parz[pos][bi];
}

int main(void){
    cin >> n >> B0;
    for(int i = 0; i<n; i++){
        cin >> x[i];
    }
    int result = rec(0,B0);
    cout << result <<endl;

    return 0;
}
