/**
* user:  VR435956
* fname: XU
* lname: SUNYI
* task:  online_budget_opt
* score: 0.0
* date:  2019-07-30 09:32:57.652078
*/
#include <stdio.h>
#include <fstream>
#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int recursive_calc(int *x, int *b, int *q, int i, int n, int k, int max){

    if(i > n){
        printf("somma totale delle gemme = %d\n", k);
        if(k > max){
            return k;
        }
        return max;
    }
    printf("valore i = %d, k = %d\n", i, k);

    b[i] = b[i - 1];
    //printf("valore b[i] = %d\n", b[i]);
    int valore = b[i];
    for(int j = valore; j >= 0; j--){
        //printf("j = %d\n", j);
        int k1 =  k + j * q[i];
        b[i] = valore - j + x[i];
        //printf("valore dopo b[i] = %d\n", b[i]);
        max = recursive_calc(x, b, q, i+1, n, k1, max);
        //printf("val k = %d\n", k);
    }
    return max;
}

int main(){
    int budget, n, t;
    ifstream fin("att/input3.txt");
    ofstream fout("output.txt");

    assert(fin);
    fin >> n >> budget >> t;
    printf("budget = %d, periodi = %d, t = %d\nx = ", budget, n, t);
    int x[n+1];
    int b[n+1];
    int q[n+1];
    b[0] = budget;

    for(int i = 1; i <= n; i++){
        fin >> x[i];
        printf("%d ", x[i]);
    }
    printf("\nq = ");
    for(int i = 1; i <= n; i++){
        fin >> q[i];
        printf("%d ", q[i]);
    }
    printf("\n");

    fin.close();

    cout << "val " << recursive_calc(x, b, q, 1, n, 0, 0) % 1000000007;
    //fout << recursive_calc(x, b, 1, n, 0) % 1000000007;
    //fout.close();
}



