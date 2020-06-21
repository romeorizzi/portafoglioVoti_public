/**
* user:  VR435956
* fname: XU
* lname: SUNYI
* task:  online_budget_opt
* score: 36.0
* date:  2019-07-30 12:01:33.926496
*/
#include <stdio.h>
#include <fstream>
#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int budget, n, t;
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    assert(fin);
    fin >> n >> budget >> t;
    //printf("budget = %d, periodi = %d, t = %d\nx = ", budget, n, t);
    int x[n+1];
    int b[n+1];
    int q[n+1];
    b[0] = budget;

    for(int i = 1; i <= n; i++){
        fin >> x[i];
        //printf("%d ", x[i]);
    }
    //printf("\nq = ");
    for(int i = 1; i <= n; i++){
        fin >> q[i];
        //printf("%d ", q[i]);
    }
    //printf("\n");

    fin.close();

    int s[n+1], temp[n], g[n];

    //fout.close();

    b[1] = budget;
    int i = 1, j = 0, index = 0;
    int h = 0;

    while(i < n + 1){
        int max = 0;
        for(int k = i; k <= n; k++){
            if(q[k] >= max){
                max = q[k];
                index = k;
            }
        }
        g[j] = max;
        j++;
        i = index + 1;

    }

    j = 0;
    int max = 0;
    for(int i = 1; i <= n; i++){
        //printf("i = %d, j = %d, ", i, j);
        //printf("q[i] = %d, temp[j] = %d, b[i] = %d, x[i] = %d\n", q[i], temp[j], b[i], x[i]);
        if(q[i] == g[j] && b[i] != 0){
            //printf("compro q = %d, prezzo = %d\n", b[i], temp[j]);
            max += b[i] * g[j];
            s[i] = b[i];
            b[i+1] = x[i];
            j++;
        }else{
            //printf("non compro\n");
            b[i + 1] = b[i] + x[i];
            s[i] = 0;
        }
        //printf("b[i] = %d\n", b[i]);
    }

    if(t == 1){
        fout << max;
    }else{
        fout << s[1];
        for(int i = 2; i <= n; i++){
            fout << " " << s[i];
        }
    }

}



