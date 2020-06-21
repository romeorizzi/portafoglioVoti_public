/**
* user:  VR436944
* fname: GHIGNONI
* lname: EROS
* task:  online_budget
* score: 67.0
* date:  2019-07-30 08:32:21.971863
*/
#include <iostream>
#include <vector>

using namespace std;

const int S = 1000000007;
int N, BUDGET;
int *x;

int calcola(int budget, int index){

    if (index == N)
        return 1;
    
    if (budget == 0 && index == N-1)
        return 1;

    int conta = 0;
    for (int i=0; i<=budget; i++){
        conta += calcola(budget + x[index] - i, index+1);
    }
    return conta ;
}   

int main(){

    cin >> N;
    cin >> BUDGET;
    int i;
    x = new int[N];

    for (i=0; i<N; i++){
        cin >> x[i];
    }
    
    cout << calcola(BUDGET, 0);
    return 0;
}