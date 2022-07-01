/**
* user:  VR472006
* fname: JACOPO
* lname: ZAGOLI
* task:  k_up_1_down_seq
* score: 7.0
* date:  2022-06-29 12:05:37.058012
*/
#include <bits/stdc++.h>
using namespace std;

int G, N, K;
int** mem;

int num_seq(int last, int lev){
    if (mem[last][lev] != -1)
        return mem[last][lev];
    if (lev == 0){
        if(last == 0){
            return 1;
        } else {
            return 0;
        }
    }
    mem[last][lev] = (   
                num_seq(last, lev-1)
                + (last > 0 ? num_seq(last-1, lev-1): 0)
                + num_seq(last + K, lev-1)
            )
        % 1000000007;
    return mem[last][lev];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // --- Lettura input -----------------------------------------------------------------
    cin >> G;
    cin >> N;
    cin >> K;

    mem = new int *[N];
    for (int i = 0; i < N; i++){
        mem[i] = new int [N];
        for (int j = 0; j < N; j++)
            mem[i][j] = -1;
    }

    cout << num_seq(0, N-1) << endl;
}