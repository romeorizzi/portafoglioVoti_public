/**
* user:  VR445479
* fname: BOSCHI
* lname: FEDERICO
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 11:30:04.151916
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    // calcolo se Martina può vincere
    if(N%10 == 0){
        cout << 0;
    }
    else{
        cout << 1 << ' ' << N%10;
    }
    return 0;
}
