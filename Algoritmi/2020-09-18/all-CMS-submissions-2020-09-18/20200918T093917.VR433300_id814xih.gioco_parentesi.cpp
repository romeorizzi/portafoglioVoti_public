/**
* user:  VR433300_id814xih
* fname: MASSIMILIANO
* lname: INCUDINI
* task:  gioco_parentesi
* score: 0.0
* date:  2020-09-18 09:39:17.362156
*/
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;
#define MAX_N 1000000

char f[MAX_N];
int actual_n;

int main() {
    
    std::cin >> actual_n;
    
    for(int i = 0; i < actual_n; i++) {
        std::cin >> f[i];
    }


    int stack = 0;
    int moves = 0;
    int first = -1;
    for(int i = 0; i < actual_n; i++) {

        // update stack
        if(f[i]==')') stack++; else stack--;

        // update moves
        if(stack == 0) moves++;
        if(stack == 0 && first == -1) first = i;
    }

    if(moves & 2 == 0) {
        std::cout << "1" << endl;
        std::cout << "0" << " " << (actual_n - 1) << endl; 
    } else {
        std::cout << "0" << endl;
    }

    return 0;
}