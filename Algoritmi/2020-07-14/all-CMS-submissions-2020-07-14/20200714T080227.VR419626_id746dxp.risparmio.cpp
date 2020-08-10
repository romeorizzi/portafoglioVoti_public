/**
* user:  VR419626_id746dxp
* fname: MARIAN CLAUDIU
* lname: SOLOMON
* task:  risparmio
* score: 0.0
* date:  2020-07-14 08:02:27.870013
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int N, M;
vector<int> inc;

int count_intervals(int k, int j) {
    int current_max = 0, max_so_far = 0;

    for (int i = k; i <= j; i++) {

        if (inc[i] == 1)
            current_max++;
        else {
            if (current_max > 0)
                max_so_far++;
            current_max = 0;
        }
    }

    return max_so_far;
}

void flipBit(int i) {
    inc[i] = inc[i] == 0 ? 1 : 0;
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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
            cout << "query t2" << endl;
#ifndef EVAL
            copy(inc.begin(), inc.end(), ostream_iterator<int>(cout, " "));
            cout << endl << endl;
#endif
            cout << count_intervals(i, j) << endl;
        } else {
            cout << "flip [" << i << "]" << endl;
            flipBit(i);
#ifndef EVAL
            copy(inc.begin(), inc.end(), ostream_iterator<int>(cout, " "));
            cout << endl << endl;
#endif
        }
    }

}