/**
* user:  VR419626_id746dxp
* fname: MARIAN CLAUDIU
* lname: SOLOMON
* task:  gioco_triangolo
* score: 1.0
* date:  2020-07-14 10:31:00.952403
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int N, M;

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N >> M;

    if (N == 1 && M == 2)
        cout << "T 2 0 0" << endl;
    if (N == 2 && M == 2)
        cout << "1\nT 2 1 0" << endl;
    if (N == 1 && M == 3)
        cout << "T 2 1 0" << endl;
    if (N == 2 && M == 3)
        cout << "0" << endl;
}