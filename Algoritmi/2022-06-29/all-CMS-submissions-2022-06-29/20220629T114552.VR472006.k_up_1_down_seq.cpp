/**
* user:  VR472006
* fname: JACOPO
* lname: ZAGOLI
* task:  k_up_1_down_seq
* score: 14.0
* date:  2022-06-29 11:45:52.637501
*/
#include <bits/stdc++.h>
using namespace std;

int G, N, K;

int num_seq(int last, int lev){
    if (lev == 0){
        if(last == 0){
            return 1;
        } else {
            return 0;
        }
    }
    return  (   
                num_seq(last, lev-1)
                + (last > 0 ? num_seq(last-1, lev-1): 0)
                + num_seq(last + K, lev-1)
            )
        % 1000000007;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // --- Lettura input -----------------------------------------------------------------
    cin >> G;
    cin >> N;
    cin >> K;

    cout << num_seq(0, N-1) << endl;
}