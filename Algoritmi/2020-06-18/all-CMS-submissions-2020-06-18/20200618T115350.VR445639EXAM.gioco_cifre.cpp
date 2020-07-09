/**
* user:  VR445639EXAM
* fname: RUSSO
* lname: ROSA
* task:  gioco_cifre
* score: 0.0
* date:  2020-06-18 11:53:50.234356
*/
#include <iostream>
#include <cstdio>
#include <cassert>
#include <cmath>
using namespace std;

int N;

void play(int N){
    
    int k; // cifra da sottrarre a N
    int init = N;

    while (N > 0)
    {
        k = N % 10;
        assert(k >= 0);
        assert (k < 10);

        N /= 10;

        if((init - k) % 10 == 0){
            cout << k;
            return;
        }

int main(){
    cin >> N;
    assert(N > 0);
    assert(N <= 10000000);

    int mod = N % 10;

    if(mod == 0){
        return 0;
    }
    else{
        cout << 1 << " ";
        play(N);
    }

    return 0;
}
