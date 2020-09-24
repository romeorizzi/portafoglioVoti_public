/**
* user:  VR424616_id163zjd
* fname: ALESSANDRA
* lname: CASTIGLIONI
* task:  gioco_parentesi
* score: 5.0
* date:  2020-09-18 13:17:17.117902
*/
#include <cassert>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <limits>
#include <deque>
#include <vector>
using namespace std;

int N;
const int MAX_N = 1000000;

char f[MAX_N];
int giocate[MAX_N];

int main() {

    cin >> N;
    if (N < 2 || N > MAX_N || N % 2 != 0) {
        return 0;
    }
    
    // fill_n(giocate, MAX_N, 0);
    // print_array(giocate, 10);

    int ap = 0, chi = 0, num_giocate = 0;
    int j = 0;

    for (int i = 0; i < N; i++) {
        cin >> f[i];
        if (f[i] == '(') {
            ap++;
        } else {
            chi++;
        } 

        if (ap == chi) {
            ap = chi = 0;
            num_giocate++;
        }
    }

    if (num_giocate % 2 != 0) {
        cout << "1" << endl;
        cout << "0" << " " << N-1 << endl; 
    } else {
        cout << "0" << endl;
    }

    return 0;
}