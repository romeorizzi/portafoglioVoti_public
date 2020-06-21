/**
* user:  VR435956
* fname: XU
* lname: SUNYI
* task:  online_budget_opt
* score: 0.0
* date:  2019-07-30 10:07:43.718826
*/
#include <stdio.h>
#include <fstream>
#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
int best[100000];

int recursive_calc(int *x, int *b, int *q, int i, int n, int k, int max, int *s){

    if(i > n){
        //printf("somma totale delle gemme = %d\n", k);
        if(k > max){
            for(int j = 1; j <= n; j++){
                best[j] = s[j];
            }
            return k;
        }
        return max;
    }
    //printf("valore i = %d, k = %d\n", i, k);

    b[i] = b[i - 1];
    //printf("valore b[i] = %d\n", b[i]);
    int valore = b[i];
    for(int j = valore; j >= 0; j--){
        //printf("j = %d\n", j);
        int k1 =  k + j * q[i];
        s[i] = j;
        b[i] = valore - j + x[i];
        //printf("valore dopo b[i] = %d\n", b[i]);
        max = recursive_calc(x, b, q, i+1, n, k1, max, s);
        //printf("val k = %d\n", k);
    }
    return max;
}

int main(){
    int budget, n, t;
    ifstream fin("att/input4.txt");
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

    int s[n+1];
    int max = recursive_calc(x, b, q, 1, n, 0, 0, s);

    /*cout << "val " << recursive_calc(x, b, q, 1, n, 0, 0, s) % 1000000007 << "\n";
    for(int i = 1; i <= n; i++){
        cout << best[i] << " ";
    }*/

    
    //fout.close();

    if(t == 1){
        fout << max;
        //cout << max;
    }else{
        fout << best[1];
        for(int i = 2; i <= n; i++){
            fout << " " << best[i];
        }
    }
}



