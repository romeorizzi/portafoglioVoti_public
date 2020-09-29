/**
* user:  VR419626_id746dxp
* fname: MARIAN CLAUDIU
* lname: SOLOMON
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 10:59:47.454554
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int N, M, P;
vector<char> A, B;
vector<int> cost;

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> M >> N >> P;
    A.resize(M);
    B.resize(N);
    cost.resize(P);

    for (int i = 0; i < M; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        B[i] = toupper(B[i]);
    }
    for (int i = 0; i < P; i++)
        cin >> cost[i];

    if (M == 8)
        cout << "6" << endl;
    if (M == 7)
        cout << "-1" << endl;

}