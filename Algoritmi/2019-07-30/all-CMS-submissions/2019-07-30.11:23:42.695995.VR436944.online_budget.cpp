/**
* user:  VR436944
* fname: GHIGNONI
* lname: EROS
* task:  online_budget
* score: 57.0
* date:  2019-07-30 11:23:42.695995
*/
#include <iostream>
#include <vector>

using namespace std;

const int S = 1000000007;
int N, BUDGET;
int *x;

int **memo;  //[N][11] -> memorizzo i valori del giorno n e budget

int calcola(int budget, int index){

    if (index == N)
        return 1;

    if (memo[index][budget] == -1){
        if (budget == 0 && index == N-1)
            return 1;

        int conta = 0;
        for (int i=0; i<=budget; i++){
            conta += calcola(budget + x[index] - i, index+1);
        }
        memo[index][budget] = conta % S;
    }
    
    return memo[index][budget]; 
}   

int main(){

    cin >> N;
    cin >> BUDGET;
    int i;
    x = new int[N];
    memo = new int*[N];

    for (i=0; i<N; i++){
        cin >> x[i];
        memo[i] = new int[11];
        for (int j=0; j<11; j++)
            memo[i][j] = -1;
    }
    
    cout << calcola(BUDGET, 0);
    return 0;
}