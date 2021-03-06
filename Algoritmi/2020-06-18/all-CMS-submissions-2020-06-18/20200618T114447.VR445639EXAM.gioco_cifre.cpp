/**
* user:  VR445639EXAM
* fname: RUSSO
* lname: ROSA
* task:  gioco_cifre
* score: 20.0
* date:  2020-06-18 11:44:47.918022
*/
#include <iostream>
#include <cstdio>
#include <cassert>
#include <cmath>
using namespace std;

int N;

int play(int N){
    
    int k; // cifra da sottrarre a N
    int init = N;

    while (N > 0)
    {
        double exp = (int)log10(N);
        k = N / pow(10,exp);
        assert(k >= 0);
        assert (k < 10);
        N %= (int)pow(10,exp);

        if((init - k) % 10 == 0){
            return k;
        }
    }
    return k;
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
        cout << 1 << " " << play(N);
    }

    return 0;
}
