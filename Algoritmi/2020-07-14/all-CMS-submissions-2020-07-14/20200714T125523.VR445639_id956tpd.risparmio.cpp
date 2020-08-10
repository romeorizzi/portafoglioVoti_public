/**
* user:  VR445639_id956tpd
* fname: ROSA
* lname: RUSSO
* task:  risparmio
* score: 0.0
* date:  2020-07-14 12:55:23.576961
*/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int n_intervalli(vector<bool> &ls, int begin, int end) {
	
    bool sottointervallo = ls[i];
    int count = sottointervallo;
    for(++i; i <= j; ++i) {
        if(ls[i]!=ls[i-1]) {
            sottointervallo = !sottointervallo;
            count += sottointervallo;
        }
    }
    return count; // numero di intervalli di luci accese nel sottointervallo
}

int main() {
	
    int N, M;
    
    cin >> N; // numero di luci
    assert(N >= 1);
    assert(N <= 10000);
    cin >> M; // numero di operazioni da eseguire
    assert(M >= 1);
    assert(M <= 20000);
    
    vector<bool> ls(N, false);

    for(int k = 0; k<M; ++k) {
        int op;
        cin >> op;
        
        if(op == 1) { // 1 + punto luce con stato invertito
            int punto_luce;
            cin >> punto_luce;
            ls[punto_luce] = !ls[punto_luce];
        }        
        if(op == 2){ // 2 + inizio intervallo + fine intervallo
            int begin, end;
            cin >> begin;
            cin >> end;
            cout << n_intervalli(ls, begin, end) << endl;
        }
        
    }
    return 0;
}
