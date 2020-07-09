/**
* user:  VR445639EXAM
* fname: RUSSO
* lname: ROSA
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 12:00:23.387640
*/
#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

void play(int N){
    
    int k; // cifra da sottrarre a N
    int init = N;

    while (N > 0){
        k = N % 10;
        assert(k >= 0);
        assert (k < 10);

        N /= 10;

        if((init - k) % 10 == 0){
            cout << k;
            return;
        }
    }
}

int main(){
    int N;
    cin >> N;
    assert(N > 0);
    assert(N <= 10000000);

    int mod = N % 10;

    if(mod == 0){
        cout << 0;
    }
    else{
        cout << 1 << " ";
        play(N);
    }

}
