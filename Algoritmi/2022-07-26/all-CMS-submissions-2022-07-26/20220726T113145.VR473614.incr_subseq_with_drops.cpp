/**
* user:  VR473614
* fname: LEONARDO
* lname: ZUANAZZI
* task:  esameincr_subseq_with_drops
* score: 10.0
* date:  2022-07-26 11:31:45.645046
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define DIM 10000
//#define BASE 10000
#define K 1000

using namespace std;
int sequenza[DIM] = {};
int sequenza2[DIM] = {};
int soluzione[DIM] = {};
int test[DIM][DIM] = {};

void readSeq(int n);
void printSeq(int n);
int solver1(int n);
int solver2(int n, int k);
int precedenti(int k);
int sottoseq(int n);

int main(){

    int g, n, k;
    cin>>g;
    cin>>n;
    cin>>k;

    readSeq(n);
    //printSeq(n);
    if(k==0)
        cout<<solver1(n);
    if(k!=0){
        cout<<solver2(n,k);
    }

    return 0;
}

void readSeq(int n){
    for(int i = 0; i < n; i++){
        cin>>sequenza[i];
        sequenza2[i] = sequenza[i];
        soluzione[i] = 1;
    }
}

void printSeq(int n){
    for(int i = 0; i < n; i++){
        cout<<sequenza[i]<<" ";
    }
    cout<<"\n";
}

//risolve per k==0
int solver1(int n){
    for(int i = 1; i < n; i++){
        soluzione[i] = precedenti(i) + 1;
    }
    int max=0;
    for(int i = 1; i < n; i++){
        max = soluzione[i]>max ? soluzione[i] : max;
    }

    return max;
}

int precedenti(int k){
    int max=0;
    for(int i=0; i<k; i++)
        if(sequenza[k]>sequenza[i] && soluzione[i]>max)
            max = soluzione[i];
    return max;
}

//tentativo 2
int solver2(int n, int k){
    sort(sequenza, sequenza + n);
    //printSeq(n);
    return sottoseq(n) - k;
}

int sottoseq(int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i==0 || j==0)
                test[i][j]=0;
            else if(sequenza[i]==sequenza2[j])
                test[i][j] = test[i-1][j-1] + 1;
            else 
                test[i][j] = max(test[i-1][j], test[i][j-1]);
        }
    }
    return test[n][n];
}