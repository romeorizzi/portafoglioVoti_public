/**
* user:  VR445639EXAM
* fname: RUSSO
* lname: ROSA
* task:  gioco_cifre
* score: 20.0
* date:  2020-06-18 11:30:42.351851
*/
#include <iostream>
#include <cstdio>
using namespace std;

int N;

int play(int N){
    
    int k; // cifra da sottrarre a N
    int init = N;

    while (N > 0)
    {
        k = N % 10;
        N /= 10;

        if((init - k) % 10 == 0){
            return k;
        }
    }
    return k;
}


int main(){
    cin >> N;
//    cout << play(N);

    int mod = N % 10;

    if(mod == 0){
        return 0;
    }
    else{
        cout << 1 << " " << play(N);
    }

    return 0;
}
