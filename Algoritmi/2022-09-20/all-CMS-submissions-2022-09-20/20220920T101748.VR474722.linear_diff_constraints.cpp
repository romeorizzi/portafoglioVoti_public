/**
* user:  VR474722
* fname: LUIGI
* lname: HU
* task:  esame_linear_diff_constraints
* score: 0.0
* date:  2022-09-20 10:17:48.238196
*/
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C){
    return 0;
}

int main() {
    // Input da file:
    // freopen("input.txt", "r", stdin);

    // Output su file:
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<long long> h(n);
    vector<int> a(m), b(m), c(m);

    for(size_t i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(size_t j = 0; j < m; j++) {
        cin >> a[j] >> b[j] >> c[j];
    }
    cout << costruisci(n, m, h, a, b, c) << endl;
    return 0;
}
