/**
* user:  VR436747_id878cue
* fname: VLADISLAV
* lname: BRAGOI
* task:  gioco_parentesi
* score: 4.0
* date:  2020-09-18 08:46:51.664803
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

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int main() {
    cin >> N;
    if (N < 2 || N > MAX_N || N % 2 != 0) {
        return 0;
    }

    int aperte = 0, chiuse = 0;

    for (int i = 0; i < N; i++) {
        cin >> f[i];
        if (f[i] == '(') {
            aperte++;
        } else {
            chiuse++;
        }
    }

    if (aperte == chiuse) {
        cout << "1" << endl;
        cout << "0" << " " << N-1 << endl; 
    } else {
        cout << "0" << endl;
    }

    return 0;
}