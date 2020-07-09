/**
* user:  VR445479
* fname: BOSCHI
* lname: FEDERICO
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 11:14:50.413262
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, op, i;
    cin >> n >> op;
    vector<int> A(n);
    for(i=0; i<n; i++){
        cin >> A[i];
    }
    vector<bool> E(n);
    for(i=0; i<n; i++){
        int x;
        cin >> x;
        E[i] = x;
    }
    vector<bool> F(n);
    for(i=0; i<n; i++){
        int x;
        cin >> x;
        F[i] = x;
    }

    if(op == 1){
        // verifica E-buono
        int result = 1;
        for(i=0; i<n; i++){
            if(E[i] and A[i]<A[(i-1)/2]){
                result = 0;
                break;
            }
        }
        cout << result;
    }
    else{
        // verifica F-stabile
        int result = 1;
        bool cycle = true;
        while(cycle) {
            cycle = false;
            for (i = 0; i < n; i++) {
                if (E[i] and A[i] < A[(i - 1) / 2]) {
                    // se sono fissi sia il nodo i e sia il padre, non è ricollocabile
                    if (F[i] and F[(i - 1) / 2]) {
                        result = 0;
                        break;
                    }
                        // se è fisso solo il padre di i, cerco un nodo (non fisso) scambiabile con i
                    else if (!F[i] and F[(i - 1) / 2]) {
                        bool find = false;
                        int x;
                        for (x = 0; x < n; x++) {
                            if (x != i and !F[x]) {
                                bool check = true;
                                if (i != 0) {
                                    if (A[x] < A[(i - 1) / 2]) {
                                        check = false;
                                    }
                                }
                                if (2 * i + 1 < n) {
                                    if (A[x] >= A[2 * i + 1]) {
                                        check = false;
                                    }
                                }
                                if (2 * (i + 1) < n) {
                                    if (A[x] >= A[2 * (i + 1)]) {
                                        check = false;
                                    }
                                }
                                if (x != 0) {
                                    if (A[i] < A[(x - 1) / 2]) {
                                        check = false;
                                    }
                                }
                                if (2 * x + 1 < n) {
                                    if (A[i] >= A[2 * x + 1]) {
                                        check = false;
                                    }
                                }
                                if (2 * (x + 1) < n) {
                                    if (A[i] >= A[2 * (x + 1)]) {
                                        check = false;
                                    }
                                }
                                if (check) {
                                    find = true;
                                    cycle = true;
                                    //scambio i nodi
                                    int temp = A[i];
                                    A[i] = A[x];
                                    A[x] = temp;
                                    break;
                                }
                            }
                        }
                        if (!find) {
                            result = 0;
                            break;
                        }
                        if(cycle){
                            break;
                        }
                    }
                        // se è fisso solo il nodo i, cerco un nodo scambiabile con il padre di i
                    else if (F[i] and !F[(i - 1) / 2]) {
                        bool find = false;
                        int p = (i - 1) / 2;
                        int x;
                        for (x = 0; x < n; x++) {
                            if (x != p and !F[x]) {
                                bool check = true;
                                if (p != 0) {
                                    if (A[x] < A[(p - 1) / 2]) {
                                        check = false;
                                    }
                                }
                                if (2 * p + 1 < n) {
                                    if (A[x] >= A[2 * p + 1]) {
                                        check = false;
                                    }
                                }
                                if (2 * (p + 1) < n) {
                                    if (A[x] >= A[2 * (p + 1)]) {
                                        check = false;
                                    }
                                }
                                if (x != 0) {
                                    if (A[p] < A[(x - 1) / 2]) {
                                        check = false;
                                    }
                                }
                                if (2 * x + 1 < n) {
                                    if (A[p] >= A[2 * x + 1]) {
                                        check = false;
                                    }
                                }
                                if (2 * (x + 1) < n) {
                                    if (A[p] >= A[2 * (x + 1)]) {
                                        check = false;
                                    }
                                }
                                if (check) {
                                    find = true;
                                    cycle = true;
                                    //scambio i nodi
                                    int temp = A[i];
                                    A[p] = A[x];
                                    A[x] = temp;
                                    break;
                                }
                            }
                        }
                        if (!find) {
                            result = 0;
                            break;
                        }
                        if(cycle){
                            break;
                        }
                    }

                }
            }
        }
        cout << result;
    }

    return 0;
}
