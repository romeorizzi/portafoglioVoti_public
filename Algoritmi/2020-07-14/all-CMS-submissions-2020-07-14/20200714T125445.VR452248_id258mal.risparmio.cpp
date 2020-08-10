/**
* user:  VR452248_id258mal
* fname: DAVIDE
* lname: GUGOLE
* task:  risparmio
* score: 25.0
* date:  2020-07-14 12:54:45.294853
*/
#include <iostream>

using namespace std;

const int MAXN = 100000;
const int MAXM = 200000;
int N;
int M;
int A[MAXN];
int T[4*MAXN];

void build (int a[], int v, int tl, int tr) {
    if (tl == tr) {
        T[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        T[v] = 0;
    }
}

void update (int v, int tl, int tr, int pos) {
    if (tl == tr) {
        T[v] = (T[v]+1) % 2;
        A[tl] = (A[tl]+1) % 2;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos);
        else
            update(v*2+1, tm+1, tr, pos);

        // aggiorna i valori degli intervalli per ogni nodo da aggiornare
        if (A[tm] == A[tm+1] && A[tm] != 0) {
            // due intervalli sono consecutivi
            T[v] = 1 + (T[v*2]-1) + (T[v*2+1]-1);
        } else {
            // gli intervalli sono tutti separati
            T[v] = T[v*2] + T[v*2+1];
        }
    }
}

int combine(int a, int b, int tm, int tm1) {
    if (a == 0 && b == 0) {
        return 0;
    }
    if (A[tm] == A[tm1] && a != 0 && b != 0) {
        // intervalli contigui e tali che siano contenuti nell'intervallo di ricerca
        return 1 + (a-1) + (b-1);
    }
    return a+b;
}

int check (int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return T[v];
    }
    int tm = (tl + tr) / 2;

    
    return combine( 
            check(v*2, tl, tm, l, min(r, tm)),
            check(v*2+1, tm+1, tr, max(l, tm+1), r),
            tm, tm+1 );
}

int main () {
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> N >> M;

    int op;

    build(A, 1, 0, N-1);

    for (int i = 0; i < M; i++) {
        cin >> op;

        if (op == 1) {
            int indice;
            cin >> indice;
            update(1, 0, N-1, indice);
        } else {
            int inizio;
            int fine;
            cin >> inizio >> fine;
            cout << check(1, 0, N-1, inizio, fine) << endl;
        }
    }

    /*for (int j = 0; j < 4*N; j++) {
        cout << T[j] << endl;
    }*/
    //cout << "-----------" << endl;

    return 0;
}