/**
* user:  AndreaCracco2020
* fname: Andrea
* lname: Cracco
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 10:02:23.709359
*/
#include<iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    cout << (N % 10 ? "1 " + to_string(N % 10) : "0") << endl;
    return 0;
}
