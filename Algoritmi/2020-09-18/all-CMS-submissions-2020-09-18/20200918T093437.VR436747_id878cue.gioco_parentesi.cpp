/**
* user:  VR436747_id878cue
* fname: VLADISLAV
* lname: BRAGOI
* task:  gioco_parentesi
* score: 0.0
* date:  2020-09-18 09:34:37.870880
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
string giocate[MAX_N];

// template <class T>
// void print_array(T *v, int len) {
//   for(int i = 0; i < len; i++)
//     cout <<  v[i] << " ";
//   cout << endl;
// }

int main() {
    cin >> N;
    if (N < 2 || N > MAX_N || N % 2 != 0) {
        return 0;
    }
    
    // fill_n(giocate, MAX_N, 0);
    // print_array(giocate, 10);

    int aperte = 0, chiuse = 0, num_giocate = 0;
    int pos_aperte = 0, pos_chiuse = 0;

    for (int i = 0; i < N; i++) {
        cin >> f[i];
        if (f[i] == '(') {
            if (pos_aperte == 0) {
                pos_aperte = i;
            }
            aperte++;
        } else {
            if (pos_chiuse < i) {
                pos_chiuse = i;
            }
            chiuse++;
        } 

        if (aperte == chiuse) {
            aperte = chiuse = 0;
            giocate[num_giocate++] = to_string(pos_aperte) + " " + to_string(pos_chiuse);
            pos_aperte = pos_chiuse = 0;
        }
    }

    // print_array(giocate, 10);

    if (num_giocate % 2 != 0) {
        cout << "1" << endl;
        cout << giocate[0] << endl; 
    } else {
        cout << "0" << endl;
    }

    return 0;
}