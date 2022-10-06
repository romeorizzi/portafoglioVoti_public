/**
* user:  VR471628
* fname: ROBERT OCTAVIAN
* lname: TIMOFTE
* task:  esame_linear_diff_constraints
* score: 0.0
* date:  2022-09-20 12:02:59.018179
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>

using namespace std;

const long long MAX_HEIGHT = 8;

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C) {
    assert(N<=MAX_HEIGHT);
    long long height_max_sum = 0;

    vector<long long> myH(MAX_HEIGHT, 0LL);
    for (size_t i = 0; i < N; i++) {
        myH[i] = H[i];
    }

    for (long long a0 = 0; a0 <= myH[0]; a0++) {
        for (long long a1 = 0; a1 <= myH[1]; a1++) {
            for (long long a2 = 0; a2 <= myH[2]; a2++) {
                for (long long a3 = 0; a3 <= myH[3]; a3++) {
                    for (long long a4 = 0; a4 <= myH[4]; a4++) {
                        for (long long a5 = 0; a5 <= myH[5]; a5++) {
                            for (long long a6 = 0; a6 <= myH[6]; a6++) {
                                for (long long a7 = 0; a7 <= myH[7]; a4++) {
                                    vector<long long> height = {a0, a1, a2, a3, a4};
                                    bool ok = true;
                                    for (size_t i = 0; i < M && ok; i++) {
                                        if (!(height[A[i]] >= height[B[i]] - C[i])) {
                                            ok = false;
                                        }
                                    }

                                    if (ok) {
                                        height_max_sum = max(height_max_sum, accumulate(height.begin(), height.end(), 0LL));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return height_max_sum;
}

// int main() {
//     // Input da file:
//     // freopen("input.txt", "r", stdin);

//     // Output su file:
//     // freopen("output.txt", "w", stdout);

//     int n, m;
//     cin >> n >> m;
//     vector<long long> h(n);
//     vector<int> a(m), b(m), c(m);

//     for(size_t i = 0; i < n; i++) {
//         cin >> h[i];
//     }
//     for(size_t j = 0; j < m; j++) {
//         cin >> a[j] >> b[j] >> c[j];
//     }
//     cout << costruisci(n, m, h, a, b, c) << endl;
//     return 0;
// }
