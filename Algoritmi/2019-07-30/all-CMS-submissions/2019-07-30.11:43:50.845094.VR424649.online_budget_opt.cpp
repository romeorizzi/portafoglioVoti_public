/**
* user:  VR424649
* fname: ERBISTI
* lname: ANDREA
* task:  online_budget_opt
* score: 10.0
* date:  2019-07-30 11:43:50.845094
*/
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
int N, B0, T;
vector <int> X, B, Q, Max;

int calculate(int n){

    if(n == 0)
    //printf("Ritorno per  %d n = %d", Q[0]*B[0], n);
        return Q[0]*B[0];
    int parz1;
    int parz2 = 0;
    if(n>=1){
        parz1 = Q[n]*B[n];
        parz2 = Max[n-1] + Q[n]*X[n];
        if(parz1>=parz2)
            //printf("Ritorno per  %d n = %d", parz1, n);
            return parz1;
    }
    //printf("Ritorno per  %d n = %d", parz2, n);
    return parz2;
}

int main(){
#ifdef EVAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d", &N);
    B.resize(N);
    Q.resize(N);
    scanf("%d", &B[0]);
    X.resize(N+1);
    Max.resize(N);
    scanf("%d", &T);
    for(int i=1; i<=N; i++){
        scanf("%d", &X[i]);
        //printf("%d ", X[i]);
    
    }
    for(int i=0; i<N; i++){
        scanf("%d", &Q[i]);
        //printf("%d ", Q[i]);
    }

    for(int i=1; i<=N; i++){
        B[i] = B[i-1]+X[i-1];
        //printf("%d ", B[i]);
    }
    int result;
    for(int i=0; i<N; i++){
        result = calculate(i);
        Max[i] = result;
    }
    printf("%d", Max[N-1]);
    return 0;
}
