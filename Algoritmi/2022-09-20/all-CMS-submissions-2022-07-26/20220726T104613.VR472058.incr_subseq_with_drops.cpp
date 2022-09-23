/**
* user:  VR472058
* fname: ALESSANDRO
* lname: FURIA
* task:  esameincr_subseq_with_drops
* score: 10.0
* date:  2022-07-26 10:46:13.027697
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#define N 100
using namespace std;

int sequenza[N];
int appo[N];

int g,n,k;

int maxMagg(int start){
    int massimo = 0;
    for(int i=start; i<n; i++){
        if(sequenza[i] > sequenza[start]){
            if(appo[i] > massimo){
                massimo = appo[i];
            }
        }
    }

    return massimo;
}

int main(void){
    cin >> g;
    cin >> n;
    cin >> k;

    for(int i=0; i<n; i++){
        cin >> sequenza[i];
    }

    appo[n-1] = 1;

    for(int i = n-2; i >= 0; i--){
        appo[i] = 1 + maxMagg(i);
    }

    int maxseq = 1;
    for(int i = 0; i < n; i++){
        if(appo[i] > maxseq)
            maxseq = appo[i];
    }

    cout << maxseq;
    
    return 0;
}