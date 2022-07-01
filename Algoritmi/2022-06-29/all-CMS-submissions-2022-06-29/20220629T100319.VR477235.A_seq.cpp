/**
* user:  VR477235
* fname: MATTEO
* lname: CAVALIERE
* task:  A_seq
* score: 13.0
* date:  2022-06-29 10:03:19.556595
*/
#include <iostream>
#include <set>

int G;
int N;

long long int MOD = 1000000007;
const int MAX_LEN = 10000;
int A[MAX_LEN];
int MAX[2][MAX_LEN + 1];

int max(int a, int b) {
    return a > b ? a : b;
}

int _solve(int i, int j, int asc) {
    if (i == N) {
        return 0;
    }

    if (i == j) {
        int take = _solve(i + 1, i, asc) + 1;
        int skip = _solve(i + 1, i + 1, asc);

        MAX[asc][take]++;
        MAX[asc][skip]++;
        return max(
            take,
            skip
        );
    }

    if (A[i] == A[j]) {
        return 0;
    }

    if (!asc) {
        int take = 0;
        if (A[i] < A[j]) {
            take = _solve(i + 1, i, asc) + 1;
            MAX[asc][take]++;
        }

        int skip = _solve(i + 1, j, asc);
        MAX[asc][skip]++;

        return max(
            take,
            skip
        );
    }

    int take = _solve(i + 1, i, A[j] < A[i]) + 1;
    int skip = _solve(i + 1, j, asc);

    MAX[asc][take]++;
    MAX[asc][skip]++;
    return max(
        take,
        skip
    );
}

long long int solve() {
    int asc_start = _solve(0, 0, 1);
    int desc_start = _solve(0, 0, 0);
    MAX[1][asc_start]++;
    MAX[0][desc_start]++;
    int res = max(asc_start, desc_start);

    if (G == 1) {
        return res;
    }

    return max(MAX[0][res], MAX[1][res]) % MOD;   
}

int main() {
    std::cin >> G;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::cout << solve() << std::endl;
}