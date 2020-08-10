/**
* user:  VR452248_id258mal
* fname: DAVIDE
* lname: GUGOLE
* task:  risparmio
* score: 25.0
* date:  2020-07-14 10:04:07.617162
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
        //cout << "agg " << tl << ": " << T[v] << " -> ";
        T[v] = (T[v]+1) % 2;
        A[tl] = (A[tl]+1) % 2;
        //cout << "valore array originale: " << A[tl] << " di indice: " << tl << endl;
        //cout << T[v] << endl;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos);
        else
            update(v*2+1, tm+1, tr, pos);

        // aggiorna i valori degli intervalli per ogni nodo da aggiornare
        //cout << "primo intervallo: [" << tl << ", " << tm << "]" << endl;
        //cout << "secondo intervallo: [" << tm+1 << ", " << tr << "]" << endl;
        //cout << "check su: " << tm << ", " << tm+1 << " (" << A[tm] << ", " << A[tm+1] << ")" << endl;
        if (A[tm] == A[tm+1] && A[tm] != 0) {
            //cout << "uguali" << endl;
            // due intervalli sono consecutivi
            T[v] = 1 + (T[v*2]-1) + (T[v*2+1]-1);
            //cout << "new value: " << T[v] << endl;
        } else {
            //cout << "diversi" << endl;
            // gli intervalli sono tutti separati
            T[v] = T[v*2] + T[v*2+1];
            //cout << "new value: " << T[v] << endl;
        }
    }
}

int combine(int a, int b, int v, int tm, int tm1) {
    //cout << "controllo indici: " << tm << ", " << tm1 << endl; 
    if (a == 0 && b == 0) {
        return 0;
    }
    if (A[tm] == A[tm1] && A[tm] != 0) {
            return 1 + (a-1) + (b-1);
        } else {
            return a+b;
        }
}

int check (int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return T[v];
    }
    int tm = (tl + tr) / 2;

    int tmp1 = check(v*2, tl, tm, l, min(r, tm));
    int tmp2 = check(v*2+1, tm+1, tr, max(l, tm+1), r);
    //cout << "risultati da combinare: " << tmp1 << ", " << tmp2 << endl;
    int tmp3 = combine( 
            tmp1,
            tmp2,
            v, tm, tm+1 );
    //cout << "ris: " << tmp3 << endl;
    return tmp3;
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