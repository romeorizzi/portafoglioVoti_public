/**
* user:  VR450788
* fname: CRIVELLARO
* lname: LUCA
* task:  bin_heap_fill
* score: 0.0
* date:  2020-06-18 11:14:29.233811
*/
#include<iostream>
#include<vector>
#include<cassert>
#include<list>
using namespace std;

long long int N;

int main(){

    
    #ifdef EVAL
        assert(freopen("input.txt","r",stdin)>0);
        assert(freopen("output.txt","w",stdout)>0);
    #endif
    
    cin >> N;

    if(N % 10 == 0)
        cout << 0 << endl;
    else{
        cout << 1 << " " << N % 10 << endl; 
    }
}