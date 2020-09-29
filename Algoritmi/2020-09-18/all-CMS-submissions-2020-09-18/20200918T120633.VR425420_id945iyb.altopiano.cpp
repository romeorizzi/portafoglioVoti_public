/**
* user:  VR425420_id945iyb
* fname: MATTEO
* lname: FIORINI
* task:  altopiano
* score: 0.0
* date:  2020-09-18 12:06:33.662643
*/
#include <iostream>
#include <cassert>

#define MAXN 100000
#define MAXM 100000

using namespace std;

// Array delle altezze
int A[MAXN];

// n altezze, m operazioni
int N, M;

// Array delle operazioni
struct {
    int op;
    int x;
    int y;
} ops[MAXM];





int main() {
    // leggo dim input
    cin >> N;
    cin >> M;
    
    // leggo A iniziale
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // leggo le operazioni
    for (int i = 0; i < M; i++) {
        cin >> op;
        cin >> x;
        cin >> y;
    }
    
    // eseguo le operazioni
    bool found = false;
    int max_a;
    for (int i = 0; i < M; i++) {
        // modifica un'altezza
        if (ops[i].op == 1) {
            A[ops[i].x] += ops[i].y;
        }
        // cerca altopiano
        else if (ops[i].op == 2) {
            found = false;
            
            // lo trovo se a indice j ho j-1 e j+1 uguali
            for (int j = ops[i].x + 1; j < ops[i].y; j++) {
                if (A[j] == A[j-1] && A[j] == A[j+1]) {
                    if (!found) {
                        found = true;
                        max_a = A[j];
                    }
                    else {
                        if (A[j] > max_a) {
                            max_a = A[j];
                        }
                    }
                }
            }
            
            if (!found) cout << "NESSUN_ALTOPIANO" << endl;
            else cout << max_a << endl;
        }
    }
    
    
    return 0;
}
