/**
* user:  VR472361
* fname: ELIA
* lname: PERANTONI
* task:  k_up_1_down_seq
* score: 14.0
* date:  2022-06-29 11:49:15.878892
*/
#include <iostream>

using namespace std;

long long int g, n, k;

long long int memo[10000][1000];

long long int f(long long int at, long long int ttl) {
    if (ttl == 0) {
        if (at == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    long long int res = 0;

    if (at-1 >= 0) {
        res += f(at-1, ttl-1);
    }
    res += f(at, ttl-1);
    res += f(at+k, ttl-1);

    return res;
}

int main() {
    cin >> g >> n >> k;
    cout << f(0, n-1) % 1000000007 << endl;
    return 0;
}
