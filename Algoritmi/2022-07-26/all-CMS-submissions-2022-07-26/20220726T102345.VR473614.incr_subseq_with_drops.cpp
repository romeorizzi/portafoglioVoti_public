/**
* user:  VR473614
* fname: LEONARDO
* lname: ZUANAZZI
* task:  esameincr_subseq_with_drops
* score: 10.0
* date:  2022-07-26 10:23:45.620934
*/
#include <iostream>
#include <cstdio>

#define DIM 10000000

using namespace std;
int sequenza[DIM] = {};
int soluzione[DIM] = {};

void readSeq(int n);
void printSeq(int n);
int solver(int n);
int precedenti(int k);

int main(){

    int g, n, k;
    cin>>g;
    cin>>n;
    cin>>k;

    readSeq(n);
    //printSeq(n);
    cout<<solver(n);

    return 0;
}


void readSeq(int n){
    for(int i = 0; i < n; i++){
        cin>>sequenza[i];
        soluzione[i] = 1;
    }
}

void printSeq(int n){
    for(int i = 0; i < n; i++){
        cout<<sequenza[i]<<" ";
    }
    cout<<"\n";
}

int solver(int n){
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
