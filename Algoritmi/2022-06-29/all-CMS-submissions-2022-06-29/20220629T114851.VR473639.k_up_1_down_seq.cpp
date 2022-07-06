/**
* user:  VR473639
* fname: ANDREA
* lname: CINELLI
* task:  k_up_1_down_seq
* score: 0.0
* date:  2022-06-29 11:48:51.605321
*/
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int G, N, K;
int* s;

int allPossibilities(int n, bool k){
    if(n==1 || n==2)
        return 1;
    
    return allPossibilities(n-1,k)*2;
}


int main() {
    cin>>G;
    cin>>N;
    cin>>K;

    if(G == 1){
        int t = allPossibilities(N,K);
        if(N>4)
            t+=N-4;
        cout<<t;
    }else if(G==3){
        s = new int[N];
        for(int i=0; i<N; i++){
            cin>>s[i];
        }
    }
    
    return 0;
}