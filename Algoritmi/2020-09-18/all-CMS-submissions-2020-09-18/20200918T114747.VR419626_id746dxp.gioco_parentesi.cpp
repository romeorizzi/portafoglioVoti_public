/**
* user:  VR419626_id746dxp
* fname: MARIAN CLAUDIU
* lname: SOLOMON
* task:  gioco_parentesi
* score: 5.0
* date:  2020-09-18 11:47:47.877312
*/
#include <iostream>

using namespace std;

int main() {
    int N, open = 0, close = 0, round = 0;
    string FBF;
    cin >> N >> FBF;

    for (char c : FBF) {
        if (c == '(')
            open++;
        else
            close++;

        if (open == close) {
            open = close = 0;
            round++;
        }
    }

    if (round % 2 == 0)
        cout << "0" << endl;
    else
        cout << "1\n0 " << N - 1 << endl;

}