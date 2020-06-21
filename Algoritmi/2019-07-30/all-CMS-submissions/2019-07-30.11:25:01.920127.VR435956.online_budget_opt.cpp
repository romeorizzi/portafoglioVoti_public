/**
* user:  VR435956
* fname: XU
* lname: SUNYI
* task:  online_budget_opt
* score: 10.0
* date:  2019-07-30 11:25:01.920127
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

    int s[n+1], temp[n + 1];

    //fout.close();
    temp[0] = 0;

    for(int i = 1; i <= n; i++){
        temp[i] = q[i];
        b[i] = 0;
    }

    b[1] = budget;

    sort(temp, temp + n + 1);

    int j = n, max = 0;
    for(int i = 1; i <= n; i++){
        //printf("i = %d, j = %d, ", i, j);
        //printf("q[i] = %d, temp[j] = %d, b[i] = %d, x[i] = %d\n", q[i], temp[j], b[i], x[i]);
        if(q[i] == temp[j] && b[i] != 0){
            //cout << "compro\n";
            max += b[i] * temp[j];
            s[i] = b[i];
            b[i+1] = x[i];
            j--;
        }else{
            if(q[i] == temp[j]){
                j--;
            }
            //printf("non compro\n");
            b[i + 1] = b[i] + x[i];
            s[i] = 0;
        }
        //printf("b[i] = %d\n", b[i]);
    }
    //printf("max = %d\n", max);

    if(t == 1){
        fout << max;
    }else{
        fout << s[1];
        for(int i = 2; i <= n; i++){
            fout << " " << s[i];
        }
    }

    /*printf("\n");
    for(int i = 1; i <= n; i++){
        printf("%d ", s[i]);
    }*/
}



