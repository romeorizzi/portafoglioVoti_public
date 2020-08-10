/**
* user:  VR419626_id746dxp
* fname: MARIAN CLAUDIU
* lname: SOLOMON
* task:  risparmio
* score: 23.0
* date:  2020-07-14 11:14:31.482774
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int N, M;
vector<int> inc;

int count_intervals(int k, int j) {
    int current = 0, max_so_far = 0;

    for (int i = k; i <= j; i++) {

        if (inc[i] == 1)
            current++;
        else {
            if (current > 0)
                max_so_far++;
            current = 0;
        }
    }
    if (current > 0)
        max_so_far++;

    return max_so_far;
}

void flipBit(int i) {
    inc[i] = inc[i] == 0 ? 1 : 0;
}

int main() {
    cin >> N >> M;
    inc.resize(N, 0);

#ifndef EVAL
    printf("%d %d\n", N, M);
    cout << "init vector:" << endl;
    copy(inc.begin(), inc.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
#endif

    for (int k = 0, t, i, j; k < M; k++) {
        cin >> t >> i;
        if (t == 2) {
            cin >> j;
#ifndef EVAL
            cout << "query t2" << endl;
            copy(inc.begin(), inc.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
#endif
            cout << count_intervals(i, j) << endl;
        } else {
            flipBit(i);
#ifndef EVAL
            cout << "flip [" << i << "]" << endl;
            copy(inc.begin(), inc.end(), ostream_iterator<int>(cout, " "));
            cout << endl << endl;
#endif
        }
    }

}