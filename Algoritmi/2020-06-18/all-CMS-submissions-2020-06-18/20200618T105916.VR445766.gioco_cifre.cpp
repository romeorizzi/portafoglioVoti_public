/**
* user:  VR445766
* fname: CILLUFFO
* lname: MARCELLO
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 10:59:16.208343
*/
#include <iostream>

using namespace std;

void mossa(int N){
    int orig=N;
    while (N > 0)
    {
        int digit = N%10;
        N /= 10;

        if((orig-digit)%10==0){
            cout<<digit;
            return;
        }
    }   
}

int main(){
    int N;
    cin>>N;

    if(N%10==0){
        cout<<0;
    }
    else{
        cout<<1<<" ";
        mossa(N);
    }
}