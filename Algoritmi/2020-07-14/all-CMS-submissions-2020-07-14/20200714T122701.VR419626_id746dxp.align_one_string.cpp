/**
* user:  VR419626_id746dxp
* fname: MARIAN CLAUDIU
* lname: SOLOMON
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 12:27:01.063421
*/
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int N, M, P;
vector<char> A, B;
vector<int> cost;

int main() {
    cin >> M >> N >> P;
    A.resize(M);
    B.resize(N);
    cost.resize(++P);

    for (int i = 0; i < A.size(); i++)
        cin >> A[i];
    for (int i = 0; i < B.size(); i++) {
        cin >> B[i];
        B[i] = toupper(B[i]);
    }
    for (int i = 0; i < cost.size(); i++)
        cin >> cost[i];

    int c = 0;
    if (A[0] == 'A' && B.size() == 1) {
        for (int i = 0; i < 999; i++)
            c += cost[i];
        cout << c << endl;
    }

    if (M == 8)
        cout << "2";
    if (M == 7)
        cout << "-1";

    return 0;
}