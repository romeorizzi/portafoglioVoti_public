/**
* user:  VR450788
* fname: CRIVELLARO
* lname: LUCA
* task:  gioco_cifre
* score: 0.0
* date:  2020-06-18 11:04:31.758698
*/
#include<iostream>
#include<vector>
#include<cassert>
#include<list>
using namespace std;

int N;

int main(){

    
    #ifdef EVAL
        assert(freopen("input.txt","r",stdin)>0);
        assert(freopen("output.txt","w",stdout)>0);
    #endif
    
    cin >> N;

    if(N % 10 == 0)
        cout << 0 << endl;
    else{
        cout << 1 << endl << N % 10 << endl; 
    }
}