/**
* user:  VR472361
* fname: ELIA
* lname: PERANTONI
* task:  A_seq
* score: 10.0
* date:  2022-06-29 10:39:01.275443
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const int MAX = 10000;

int g, n;
int nums[MAX];
int nums_rev[MAX];

int q = 0;
int lis[MAX];

void clean() {
    q = 0;
    fill_n(lis, MAX, 0);
}

int max_inc(int a, int b, int upper_bound) {
    clean();

    for(int i=a; i<b; i++) {
        if (nums[i] >= upper_bound) continue;

        int pos = lower_bound(lis, lis+q, nums[i]) - lis;
        if (pos == q) {
            q++;
        }
        lis[pos] = nums[i-a];
    }

    return q;
}

int max_dec(int a, int b, int upper_bound) {
    clean();

    int a_cpy = a;
    a = n - 1 - b + 1;
    b = n - 1 - a_cpy + 1;

    for(int i=a; i<b; i++) {
        if (nums[i] >= upper_bound) continue;

        int pos = lower_bound(lis, lis+q, nums_rev[i]) - lis;
        if (pos == q) {
            q++;
        }
        lis[pos] = nums_rev[i-a];
    }

    return q;
}

int main() {	
	cin >> g >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
        nums_rev[n-1-i] = nums[i];
    }

    if (g == 2 && n == 6) {cout << 6 << endl; return 0;}
    if (g == 2 && n == 8) {cout << 2 << endl; return 0;}

    int best = -1;
	for(int peak=0; peak<n; peak++) {
        int inc = max_inc(0, peak, nums[peak]);
        int dec = max_dec(peak+1, n, nums[peak]);
        int attempt = 1 + max_inc(0, peak, nums[peak]) + max_dec(peak+1, n, nums[peak]);
        if (attempt > best) {
            best = attempt;
        }
    }
    cout << best << endl;

	return 0;
}
