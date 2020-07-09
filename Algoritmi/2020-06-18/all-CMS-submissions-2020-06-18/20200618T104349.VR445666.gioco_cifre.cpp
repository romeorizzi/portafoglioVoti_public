/**
* user:  VR445666
* fname: GAIARDELLI
* lname: SEBASTIANO
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 10:43:49.748472
*/
#include <bits/stdc++.h>

using namespace std;


int main(){

    ifstream input;
    ofstream output;
    input.open("input.txt");
    output.open("output.txt");

    int N;
    input >> N;
    
    if(N % 10 == 0){
        output << 0 << "\n";
    }else{
        output << 1 << " " << (N%10) << "\n";
    }

    return 0;
}