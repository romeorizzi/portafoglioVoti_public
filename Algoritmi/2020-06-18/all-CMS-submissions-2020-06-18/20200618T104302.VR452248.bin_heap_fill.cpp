/**
* user:  VR452248
* fname: GUGOLE
* lname: DAVIDE
* task:  bin_heap_fill
* score: 23.0
* date:  2020-06-18 10:43:02.841148
*/
#include <iostream>

using namespace std;

const int MAXN = 1000001;
int N;
int task;
int A[MAXN];
int E[MAXN];
int F[MAXN];

int heap_property () {
    for (int i = 1; i < N; i++) {
        // per ogni figlio
        if (E[i]) {
            // se il figlio va controllato
            if (A[i] < A[(i-1)/2]) {
                // la proprietà non è soddisfatta
                // ovvero il figlio ha valore minore del padre
                return 0;
            }
        }
    }
    return 1;
}

int main () {
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> N >> task;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> E[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> F[i];
    }

    if (task == 1) {
        cout << heap_property() << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}