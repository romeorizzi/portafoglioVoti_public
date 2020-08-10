/**
* user:  VR452248_id258mal
* fname: DAVIDE
* lname: GUGOLE
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 12:57:42.482226
*/
#include <iostream>
#include <limits>
using namespace std;

const int MAXM = 1000;
const int MAXN = 1000;
const int MAXP = 1000;
int M, N, P;
int cost[MAXP+1];
char A[MAXM];
char B[MAXN];

int INF = numeric_limits<int>::max();

int min_cost (int posa, int posb) {
    int ret = INF;    // devo trovare la soluzione migliore rispetto a dove riaffiora il carattere

    for(int ii = posa; ii <= M; ii++) {   // scorro tutto A
        if (A[ii] == B[posb]) {              // trovo una corrispondenza in ii del carattere di B
            ret = min(ret,
                cost[ii-posa] + min_cost(ii+1, posb+1));
        }
    }
    return ret;
}

int main () {
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> M >> N >> P;

    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < P+1; i++) {
        cin >> cost[i];
    }

    cout << min_cost(0, 0) << endl;

    /*cout << "A:" << endl;
    for (int i = 0; i < M; i++) {
        cout << A[i];
    }
    cout << endl << "B:" << endl;
    for (int i = 0; i < N; i++) {
        cout << B[i];
    }
    cout << endl << "cost:" << endl;
    for (int i = 0; i < P+1; i++) {
        cout << cost[i];
    }*/

    return 0;
}