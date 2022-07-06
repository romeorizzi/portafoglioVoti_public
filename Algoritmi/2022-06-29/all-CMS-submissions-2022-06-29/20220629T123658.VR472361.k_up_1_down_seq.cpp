/**
* user:  VR472361
* fname: ELIA
* lname: PERANTONI
* task:  k_up_1_down_seq
* score: 14.0
* date:  2022-06-29 12:36:58.683529
*/
#include <iostream>
#include <vector>

using namespace std;

const int MAGIC = 1000000007;

int g, n, k, r;

int f(int at, int ttl) {
    if (ttl == 0) {
        if (at == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    int res = 0;

    if (at-1 >= 0) {
        res += f(at-1, ttl-1);
    }
    res += f(at, ttl-1);
    res += f(at+k, ttl-1);

    return res;
}

int main() {
    cin >> g >> n >> k;
    switch (g) {
        case 1:
            cout << f(0, n-1) % MAGIC << endl;
            break;
    }
    
    return 0;
}
