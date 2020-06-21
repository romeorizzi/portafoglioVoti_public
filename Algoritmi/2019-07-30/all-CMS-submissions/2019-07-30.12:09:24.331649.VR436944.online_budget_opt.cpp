/**
* user:  VR436944
* fname: GHIGNONI
* lname: EROS
* task:  online_budget_opt
* score: 12.0
* date:  2019-07-30 12:09:24.331649
*/
#include <iostream>
#include <vector>

using namespace std;

const int S = 1000000007;
int N, BUDGET;
int *x;
int *g;
int max_num = 0;
int *max_index;

int calcola(int budget, int index){

    if (index == N)
        return 0;
    
    if (budget == 0 && index == N-1)
        return 0;

    int conta = 0;
    int massimo = 0;
    for (int i=0; i<=budget; i++){

        int acquisto = g[index]*i;  //gemme che compro

        int s = calcola(budget - i + x[index], index+1) + acquisto;
        if (s > massimo)
            massimo = s;
    }
    
    return massimo;
}   
int path(int budget, int index){

    if (index == N)
        return 0;
    
    if (budget == 0 && index == N-1)
        return 0;

    int conta = 0;
    int massimo = 0;
    for (int i=0; i<=budget; i++){

        int acquisto = g[index]*i;  //gemme che compro

        int s = calcola(budget - i + x[index], index+1) + acquisto;
        if (s > massimo){
            massimo = s;
            max_index[index] = i;
        }
    }
    
    return massimo;
}   

int main(){

    cin >> N;
    cin >> BUDGET;
    int tipo;
    cin >> tipo;
    int i;
    x = new int[N];
    g = new int[N];
    max_index = new int[N];

    for (i=0; i<N; i++){
        cin >> x[i];
    }

    for (i=0; i<N; i++){
        cin >> g[i];
    }
    if (tipo == 1)
        cout << calcola(BUDGET, 0);
    else{
        path(BUDGET, 0);
        for (i=0;i<N;i++)
            cout << max_index[i] << " ";
    }
    return 0;
}