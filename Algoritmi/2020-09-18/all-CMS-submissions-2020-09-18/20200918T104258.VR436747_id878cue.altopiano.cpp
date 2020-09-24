/**
* user:  VR436747_id878cue
* fname: VLADISLAV
* lname: BRAGOI
* task:  altopiano
* score: 60.0
* date:  2020-09-18 10:42:58.443233
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
#include<bits/stdc++.h> 
using namespace std;

int N, M;
const int MAX_N = 100000;
const int MAX_M = 100000;

int n[MAX_N];
int m[MAX_M];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

void cerca_altopiano(int i1, int i2) {
    bool trovato = false;
    bool continui = false;
    int val_massimo = INT_MIN, prec;

    for(int i = i1; i < i2; i++) {
        if (!continui) {
            if (!trovato) {
                if (n[i] == n[i+1]) {
                    continui = true;
                    prec = n[i];
                }
            } else {
                if (n[i] == n[i+1] && n[i] > val_massimo) {
                    continui = true;
                    prec = n[i];
                }
            }
        }  else {
            if (prec == n[i] && n[i] == n[i+1] && i != i2) {
                if (n[i] > val_massimo) {
                    val_massimo = n[i];
                    trovato = true;
                }
            } else {
                continui = false;
            }
        }  
    }

    if(!trovato) {
        cout << "NESSUN_ALTOPIANO" << endl;
    } else {
        cout << val_massimo << endl;
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++)
       cin >> n[i];
    
    // print_array(n, N);

    for(int i = 0; i < M; i++) {
        int type = 0;
        cin >> type;
        if (type == 2) {
            int i1, i2;
            cin >> i1 >> i2;
            // printf("type = %i, i1=%i, i2=%i\n", type, i1, i2);
            // cerca altopiano tra i1 e i2 (= 3 altezze consecutive uguali)
            cerca_altopiano(i1, i2);
        } else {
            int x, y;
            cin >> x >> y;
            // printf("type = %i, x=%i, y=%i\n", type, x, y);
            // modifica le altezze in n
            n[x] += y;
        }
    }

    return 0;
}

