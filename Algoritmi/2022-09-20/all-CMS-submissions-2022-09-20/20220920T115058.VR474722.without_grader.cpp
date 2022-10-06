/**
* user:  VR474722
* fname: LUIGI
* lname: HU
* task:  esame_without_grader
* score: 4.0
* date:  2022-09-20 11:50:58.781137
*/
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C){
        int i, k, max, sum;

        for(i = 0; i < M; i++){
            max = H[A[i]] + C[i];
            if(H[B[i]] > max){
                H[B[i]] = max;
                for(k = 0; k < i; k++){
                    if(A[k] == B[i]){
                        max = H[A[k]] + C[k];
                        if(H[B[k]] > max){
                             H[B[k]] = max;
                        }
                    }
                }
            }
        }
        sum = 0;
        for(i = 0; i < N; i++){
            sum = sum + H[i];
        }

    return sum;
}

int main(){
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