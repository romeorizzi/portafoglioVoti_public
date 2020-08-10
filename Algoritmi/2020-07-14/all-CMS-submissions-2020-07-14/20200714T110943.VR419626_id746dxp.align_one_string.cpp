/**
* user:  VR419626_id746dxp
* fname: MARIAN CLAUDIU
* lname: SOLOMON
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 11:09:43.761827
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

    if(A[0] == 'A')
        for(int i=0; i<999; i++)
            B.insert(B.begin(), 'A');

#ifndef EVAL
    printf("%d %d %d\n", N, M, P);
    cout << "A: ";
    copy(A.begin(), A.end(), ostream_iterator<char>(cout, " "));
    cout << endl;
    cout << "B: ";
    copy(B.begin(), B.end(), ostream_iterator<char>(cout, " "));
    cout << endl;
    cout << "c: ";
    copy(cost.begin(), cost.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
#endif

}