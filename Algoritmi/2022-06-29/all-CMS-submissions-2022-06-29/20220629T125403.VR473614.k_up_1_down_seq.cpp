/**
* user:  VR473614
* fname: LEONARDO
* lname: ZUANAZZI
* task:  k_up_1_down_seq
* score: 0.0
* date:  2022-06-29 12:54:03.165465
*/
#include <iostream>
#include <cmath>
using namespace std;

int solver(int n, int k);

int main(void){
    int g,n,k;

    cin>>g;
    cin>>n;
    cin>>k;

    if(g==1)
        cout<<solver(n,k);

    return 0;
}

int solver(int n, int k){
    if(n<3)
        return 1;
    if(n==3)
        return 1;
    if(k==1){
        return  pow(2,n-2) + solver(n-2,k);
    }
        
}