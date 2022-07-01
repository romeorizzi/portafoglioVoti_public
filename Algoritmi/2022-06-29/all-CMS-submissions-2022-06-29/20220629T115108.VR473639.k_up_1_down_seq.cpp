/**
* user:  VR473639
* fname: ANDREA
* lname: CINELLI
* task:  k_up_1_down_seq
* score: 0.0
* date:  2022-06-29 11:51:08.214740
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
    int plus = 0;
    if(n>4)
        plus+=n-4;
    return plus+allPossibilities(n-1,k)*2;
}


int main() {
    cin>>G;
    cin>>N;
    cin>>K;

    if(G == 1){
        int t = allPossibilities(N,K);
        cout<<t;
    }else if(G==3){
        s = new int[N];
        for(int i=0; i<N; i++){
            cin>>s[i];
        }
    }
    
    return 0;
}