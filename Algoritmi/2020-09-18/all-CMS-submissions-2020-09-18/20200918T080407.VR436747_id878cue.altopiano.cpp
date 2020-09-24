/**
* user:  VR436747_id878cue
* fname: VLADISLAV
* lname: BRAGOI
* task:  altopiano
* score: 25.0
* date:  2020-09-18 08:04:07.152300
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

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

void cerca_altopiano(int i1, int i2) {
    bool trovato = false;
    int val_massimo;

    for(int j = i1+1; j < i2; j++) {
        int a = n[j-1], b = n[j], c = n[j+1];
        if(a == b && b == c) {
            if(!trovato) {
                val_massimo = a;
            } else {
                val_massimo = val_massimo > a ? val_massimo : a;
            }
            trovato = true;
        }
    }
    if(!trovato) {
        std::cout << "NESSUN_ALTOPIANO" << std::endl;
    } else {
        std::cout << val_massimo << std::endl;
    }
}

void modifica_altezze(int i, int variazione) {
    n[i] += variazione;
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
            modifica_altezze(x, y);
        }
    }

    return 0;
}

