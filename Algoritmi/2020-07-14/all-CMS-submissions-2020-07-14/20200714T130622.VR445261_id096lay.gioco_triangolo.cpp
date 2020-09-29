/**
* user:  VR445261_id096lay
* fname: NICOLA
* lname: SCARABELLO
* task:  gioco_triangolo
* score: 0.0
* date:  2020-07-14 13:06:22.759145
*/
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <map>

using namespace std;

int move(vector<int>& N, vector<int>& T, char c, int k, int i, int j, int op) {
    if(c=='N') {
        N[k] -= i-j+1;
    }
    else {
        if(i == 0 || j == T[k]-1) {
            T[k] -= i-j+1;
        }
        else {
            int tmp = T[k];
            T.erase(T.begin()+k);
            T.push_back(i);
            T.push_back(tmp-j-1);
        }
    }
    int G = T[0];
    for(int i = 1; i < T.size(); ++i) {
        G ^= T[i];
    }
        for(int i = 0; i < N.size(); ++i) {
            G ^= N[i];
        }
    return G;
}

int movetest(vector<int> N, vector<int> T, char c, int k, int i, int j, int op) {
    return move(N,T,c,k,i,j, op);
}

int main() {
    int op, n;
    cin >> op >>n;
    vector<int> T(n), N(n);
    for(int i = 0; i < n; ++i) {
        cin >> T[i];
        N[i] = T[i];
    }
    char c;
    cin >> c;
    int k, i, j;
    cin >> k >> i >> j;
    if(op == 1) {
        bool result = !!move(N, T, c, k-1, i, j, op);

        for(int k = 0; k < T.size(); k++) {
            for(int i = 0; i < T[k]; ++i) {
                for(int j = i; j < T[k]; ++j) {
                    if(!movetest(N, T, 'T', k, i, j, op)) {
                        cout << "T " << k+1 << ' ' << i << ' ' << j << endl;
                        return 0;
                    }
                }
            }
        }
        for(int k = 0; k < N.size(); k++) {
            for(int i = 0; i < N[k]; ++i) {
                if(!movetest(N, T, 'N', k, 0, i, op)) {
                    cout << "N " << k+1 << ' ' << 0 << ' ' << i << endl;
                    return 0;
                }
            }
        }
    }
    else if(op == 2) {
        bool result = !!move(N, T, c, k-1, i, j, op);
        cout << !!result << endl;
        if(result) {
            for(int k = 0; k < T.size(); k++) {
            for(int i = 0; i < T[k]; ++i) {
                for(int j = i; j < T[k]; ++j) {
                    if(!movetest(N, T, 'T', k, i, j, op)) {
                        cout << "T " << k+1 << ' ' << i << ' ' << j << endl;
                        return 0;
                    }
                }
            }
        }
        }
    }
    return 0;
}