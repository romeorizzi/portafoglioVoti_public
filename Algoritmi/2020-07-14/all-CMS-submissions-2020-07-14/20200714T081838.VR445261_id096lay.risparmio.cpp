/**
* user:  VR445261_id096lay
* fname: NICOLA
* lname: SCARABELLO
* task:  risparmio
* score: 23.0
* date:  2020-07-14 08:18:38.100662
*/
#include <iostream>
#include <vector>

using namespace std;

int count(vector<bool>& ls, int i, int j) {
    bool interval = ls[i];
    int count = interval;
    for(++i; i <= j; ++i) {
        if(ls[i]!=ls[i-1]) {
            interval = !interval;
            count += interval;
        }
    }
    return count;
}

int main() {
    int lights, ops;
    cin >> lights >> ops;
    vector<bool> ls(lights, false);

    for(int k = 0; k<ops; ++k) {
        int op;
        cin >> op;
        if(op == 1) {
            int pos;
            cin >> pos;
            ls[pos] = !ls[pos];
        }
        else {
            int i, j;
            cin >> i >> j;
            cout << count(ls, i, j) << endl;
        }
    }
    return 0;
}