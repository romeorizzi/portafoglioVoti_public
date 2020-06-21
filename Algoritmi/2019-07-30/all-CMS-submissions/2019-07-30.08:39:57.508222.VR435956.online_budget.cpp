/**
* user:  VR435956
* fname: XU
* lname: SUNYI
* task:  online_budget
* score: 67.0
* date:  2019-07-30 08:39:57.508222
*/
#include <stdio.h>
#include <fstream>
#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int recursive_calc(int *x, int *b, int i, int n, int k){

    if(i > n){
        return k + 1;
    }
    //printf("valore i = %d\n", i);
    b[i] = b[i - 1];
    //printf("valore b[i] = %d\n", b[i]);
    int valore = b[i];
    for(int j = valore; j >= 0; j--){
        //printf("j = %d\n", j);
        b[i] = valore - j + x[i];
        //printf("valore dopo b[i] = %d\n", b[i]);
        k = recursive_calc(x, b, i+1, n, k);
        //printf("val k = %d\n", k);
    }
    return k;
}

int main(){
    int budget, n;
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    assert(fin);
    fin >> n >> budget;
    //printf("budget = %d, periodi = %d\nx = ", budget, n);
    int x[n+1];
    int b[n+1];
    b[0] = budget;

    for(int i = 1; i <= n; i++){
        fin >> x[i];
    }
    fin.close();

    //cout << "val " << recursive_calc(x, b, 1, n, 0) % 1000000007;
    fout << recursive_calc(x, b, 1, n, 0) % 1000000007;
    fout.close();
}



