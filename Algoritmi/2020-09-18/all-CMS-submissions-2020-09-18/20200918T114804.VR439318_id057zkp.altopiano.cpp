/**
* user:  VR439318_id057zkp
* fname: GIANLUCA
* lname: PAVAN
* task:  altopiano
* score: 1.0
* date:  2020-09-18 11:48:04.422816
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


void f1(int inzio, int fine) {
    bool b = false;
    int max;

    for(int i = inzio+1; i < fine; i++) {
        int a = n[i-1], b = n[i], c = n[i+1];
        if(a == b && b == c) {
            if(!b) {
                max = a;
            } else {
                if(max<=a){
                    max = a;
                }
            }
            b = true;
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
        if (op == 2) {
            int inizio, fine;
            cin >> inizio >> fine;
            f1(inizio, fine);
        } else {
            int x, y;
            cin >> x >> y;
            n[x] = n[x] + y;
        }
    }

    return 0;
}