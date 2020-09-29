/**
* user:  VR439318_id057zkp
* fname: GIANLUCA
* lname: PAVAN
* task:  altopiano
* score: 1.0
* date:  2020-09-18 11:56:08.089844
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

int N, M;
const int MAX_N = 100000;
const int MAX_M = 100000;

int n[MAX_N];
int m[MAX_M];


void f1(int inizio, int fine) {
    bool b = false;
    bool b2 = false;
    int max = 0; 
    int tmp = 0;

    for(int i = inizio; i < fine; i++) {
        if (!b2 && !b) {
            if (n[i] == n[i+1]) {
                b2 = true;
                tmp = n[i];
            }
        } else if (!b2) {
            if (n[i] == n[i+1] && n[i] > max) {
                b2 = true;
                tmp = n[i];
            }
        }  else if (tmp == n[i] && n[i] == n[i+1] && i != fine) {
            if (n[i] > max) {
                max = n[i];
                b = true;
            }
        } else {
            b2 = false;
        }
    }

    if(!b) {
        cout << "NESSUN_ALTOPIANO" << endl;
    } else {
        cout << max << endl;
    }
}


int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++)
       cin >> n[i];
    

    for(int i = 0; i < M; i++) {
        int op = 0;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            n[x] = n[x] + y;
            
        } else {
            int inizio, fine;
            cin >> inizio >> fine;
            f1(inizio, fine);
        }
    }

    return 0;
}