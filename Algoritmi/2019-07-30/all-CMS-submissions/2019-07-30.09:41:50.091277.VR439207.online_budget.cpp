/**
* user:  VR439207
* fname: TROTTI
* lname: FRANCESCO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 09:41:50.091277
*/
#include <stdlib.h>
#include <fstream>
#include <cassert>
#include <iostream>


const int MAX_N = 500;
const int MAX_VAL = 10;
int par[MAX_VAL][MAX_N];
int n, B0, x[MAX_N];

using namespace std;
/*
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}
*/

int ric(int pos, int bi){
    if (par[pos][bi] != 0){
        return partial[pos][bi];
    }
    if (pos == n-1)
        return bi+1;
    for(int i=0; i<=bi; i++){
        if(par[pos][i] != 0)
            continue;
        par[pos][i] = (par[pos][i-1]+ric(pos+1, i+x[pos]))%1000000007;
    }
    return partial[pos][bi];
}

int main(void){

    cin >> n >> B0;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    int res = ric(0, B0);
    //print_array(x, n);

    cout << res << endl;
    return 0;

}