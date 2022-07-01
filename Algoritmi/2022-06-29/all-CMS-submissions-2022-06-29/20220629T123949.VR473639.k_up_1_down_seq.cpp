/**
* user:  VR473639
* fname: ANDREA
* lname: CINELLI
* task:  k_up_1_down_seq
* score: 0.0
* date:  2022-06-29 12:39:49.931544
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
    int i = allPossibilities(n-1,k);
    return pow(2,n-2)+allPossibilities(n-2, k);
}


int main() {
    cin>>G;
    cin>>N;
    cin>>K;

    if(G == 1){
        cout<<;
    }else if(G==3){
        s = new int[N];
        for(int i=0; i<N; i++){
            cin>>s[i];
        }
    }
    
    return 0;
}