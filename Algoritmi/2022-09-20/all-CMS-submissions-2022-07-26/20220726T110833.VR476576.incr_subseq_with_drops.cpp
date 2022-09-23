/**
* user:  VR476576
* fname: CRISTIANO
* lname: DI BARI
* task:  esameincr_subseq_with_drops
* score: 50.0
* date:  2022-07-26 11:08:33.159092
*/
#include<bits/stdc++.h>
using namespace std;

const int64_t MOD = 1000000007;

const int MAX_N = 100;

int G = 0;
int N = 0;
int K = 0;

int S[MAX_N] = { 0 };

unordered_map<string, int> MEMO;


int max_subseq(int i, int prev, int k) {
    string key = to_string(i) + "~" + to_string(prev) + "~" + to_string(k);

    if (MEMO.find(key) != MEMO.end())
    {
        return MEMO[key];
    }

    if (i >= N) {
        return 0;
    }

    int s1 = 0, s2 = 0, s3 = 0;

    if (S[i] > prev) {
        s1 = 1 + max_subseq(i + 1, S[i], k);
    }

    if (S[i] <= prev && k > 0) {
        s2 = 1 + max_subseq(i + 1, S[i], k - 1);
    }

    s3 = max_subseq(i + 1, prev, k);

    MEMO[key] = max(s1, max(s2, s3));
    return MEMO[key];
}

int main() {
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));

    cin >> G;
    cin >> N;
    cin >> K;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    if (G == 1) {
        int max_subseq_len = 0;
        for (int i = 0; i < N; i++) {
            if (max_subseq_len > (N - i)) break;

            max_subseq_len = max(max_subseq_len, max_subseq(i, S[i - 1], K));
        }

        cout << max_subseq_len;
    }

    if (2 == 2) {
        // TODO
    }

    return 0;
}
