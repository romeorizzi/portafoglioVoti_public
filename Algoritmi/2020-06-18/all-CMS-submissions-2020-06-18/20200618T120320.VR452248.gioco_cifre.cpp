/**
* user:  VR452248
* fname: GUGOLE
* lname: DAVIDE
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 12:03:20.815387
*/
#include <iostream>

using namespace std;

long long int N;

int main () {
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> N;

    if (N % 10 == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << " " << N%10 << endl;
    }

    return 0;
}