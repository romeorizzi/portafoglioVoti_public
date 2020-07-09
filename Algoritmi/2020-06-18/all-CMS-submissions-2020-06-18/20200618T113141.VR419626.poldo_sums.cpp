/**
* user:  VR419626
* fname: SOLOMON MARIAN
* lname: CLAUDIU
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 11:31:41.827901
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N;
vector<int> p, g, Xi, Xv;

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &N);
    Xi.resize(1);
    Xv.resize(1);
    p.resize(N);
    g.resize(N);

    for (int i = 0; i < N; i++)
        cin >> p[i] >> g[i];
#ifndef EVAL
    copy(p.begin(), p.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(g.begin(), g.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
#endif
    for (int i = 0, j, x; i < N; i++) {
        bool to_insert = true;
        for (j = 0, x = p[i]; j < Xi.size() && to_insert; j++)
            if (x > Xv[j]) {
                Xv[j] = x;
                to_insert = false;
            }

        if (to_insert) {
            Xi.push_back(i);
        }
    }
    cout << Xi.size() << endl;
    copy(Xi.begin(), Xi.end(), ostream_iterator<int>(cout, " "));

    return 0;
}