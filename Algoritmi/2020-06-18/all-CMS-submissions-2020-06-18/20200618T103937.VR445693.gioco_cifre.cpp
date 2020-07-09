/**
* user:  VR445693
* fname: SPERANZA
* lname: GIOVANNI
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 10:39:37.628661
*/
#include<iostream>
#include<cassert>

using namespace std;

long long int N;

int main(){

    cin >> N;

    if(N < 10){
        cout << 1 << " " << N << endl;
    }
    else if((N % 10) != 0)
    {
        cout << 1 << " " << N%10 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    
    
    

    return 0;
}

