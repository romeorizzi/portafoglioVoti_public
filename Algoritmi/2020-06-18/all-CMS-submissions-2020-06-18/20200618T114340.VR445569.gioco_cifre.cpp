/**
* user:  VR445569
* fname: PADOVANI
* lname: ALAN MICHAEL
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 11:43:40.874534
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

int main() {
    int n;
    cin >> n;
    int resto = n % 10;
    if(resto == 0){
        cout << 0 << endl;
    }else{
        cout << 1 << " " << resto << endl;
    }
    return 0;
}