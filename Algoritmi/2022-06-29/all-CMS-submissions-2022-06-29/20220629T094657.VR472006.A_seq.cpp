/**
* user:  VR472006
* fname: JACOPO
* lname: ZAGOLI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 09:46:57.684407
*/
#include <bits/stdc++.h>
using namespace std;

int N;
int task;
int* sequence;
int* length;
int* length_decr;

constexpr int max_3(int a, int b, int c) {
    int r = max(a,b);
    return max(r,c);
}

void lcs_inv(){
    for (int k = 0; k < N; k++) {
        length[k] = 1;
        length_decr[k] = 1;
            for (int i = 0; i < k; i++) {
                if (sequence[i] < sequence[k]) {
                    length[k] = max(length[k],length[i]+1);
                }
                if (sequence[i] > sequence[k]) {
                    length_decr[k] = max_3(length_decr[k], length[i]+1, length_decr[i]+1);
                }
        }
    }
}


int max_a_seq(){
    lcs_inv();
    int m = -1;
    for (int i = 0; i < N; ++i) {
        m = length[i] > m ? length[i] : m;
        m = length_decr[i] > m ? length_decr[i] : m;
    }
    return m;
}

int how_many(){
    int n = max_a_seq();
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (length[i] == n || length_decr[i] == n)
            count = (count + 1) % 1000000007;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // --- Lettura input -----------------------------------------------------------------
    cin >> task;
    cin >> N;
    sequence = new int[N]{};
    length = new int[N]{};
    length_decr = new int[N]{};
    for (int i = 0; i < N; ++i) {
        cin >> sequence[i];
    }

    // --- Output ------------------------------------------------------------------------
    if (task == 1){
        cout << max_a_seq();
    } else {
        cout << how_many();
    }

    // --- DEBUG --- stampa la sequenza ----------------------------------------------------
    #ifdef debug
    max_a_seq();
    cout << "SEQUENCE:\n";
    for (int i = 0; i < N; ++i) {
        cout << sequence[i] << " ";
    }
    cout << endl;
    cout << "LENGTH:\n";
    for (int i = 0; i < N; ++i) {
        cout << length[i] << " ";
    }
    cout << endl;
    cout << "LENGTH_DECR:\n";
    for (int i = 0; i < N; ++i) {
        cout << length_decr[i] << " ";
    }
    cout << endl;
    #endif

    // --- Cleanup ---------------------------------------------------------------------------
    delete[] sequence;
    delete[] length;
    delete[] length_decr;
}