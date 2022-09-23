/**
* user:  VR476576
* fname: CRISTIANO
* lname: DI BARI
* task:  esameincr_subseq_with_drops
* score: 60.0
* date:  2022-07-26 11:41:19.593465
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

    if (MEMO.find(key) != MEMO.end()) {
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


pair<int, int> max_subseq_count(int i, int prev, int k, int same) {

    if (i >= N) {
        return pair<int,int>{1,1};
    }

    pair<int,int> s1{0,0};
    pair<int,int> s2{0,0};
    pair<int,int> s3{0,0};

    if (S[i] > prev) {
        s1 = max_subseq_count(i + 1, S[i], k, same);
    }

    if (S[i] <= prev && k > 0) {
        s2 = max_subseq_count(i + 1, S[i], k - 1, same);
    }

    s3 = max_subseq_count(i + 1, prev, k, same);

    int max_val = max(s1.first + 1, max(s2.first + 1, s3.first));
    int tmp = 0;

    if (max_val == (s1.first + 1)) {
        tmp += s1.second;
    } 
    
    if (max_val == (s2.first + 1)) {
        tmp += s2.second;
    } 
    
    if (max_val == s3.first) {
        tmp += s3.second;
    }

    pair<int,int> res;
    res.first = max_val;
    res.second = same + tmp;

    return res;
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

    if (G == 2) {
        int num_max_subseq = 0;
        int max_subseq_len = 0;

        for (int i = 0; i < N; i++) {
            pair<int, int> res = max_subseq_count(i, S[i - 1], K, 0);

            if (res.first == max_subseq_len) {
                num_max_subseq = (res.second + num_max_subseq) % MOD;
            }

            if (res.first > max_subseq_len) {
                max_subseq_len = res.first;
                num_max_subseq = (res.second) % MOD;
            }
        }

        cout << num_max_subseq;
    }

    return 0 ;
}
