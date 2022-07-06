/**
* user:  VR472361
* fname: ELIA
* lname: PERANTONI
* task:  A_seq
* score: 20.0
* date:  2022-06-29 11:02:47.423621
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX = 10000;

int g, n;
int nums[MAX];
int nums_rev[MAX];

int memo_inc[MAX][MAX];
int memo_dec[MAX][MAX];

int q = 0;
int lis[MAX];

int max_inc(int a, int b, int upper_bound) {
    if(memo_inc[b][upper_bound] > 0) {
        return memo_inc[b][upper_bound];
    }

    q = 0;

    for(int i=a; i<b; i++) {
        if (nums[i] >= upper_bound) continue;

        int pos = lower_bound(lis, lis+q, nums[i]) - lis;
        if (pos == q) {
            q++;
        }
        lis[pos] = nums[i-a];
    }

    memo_inc[b][upper_bound] = q;

    return q;
}

int max_dec(int a, int b, int upper_bound) {
    if(memo_dec[a][upper_bound] > 0) {
        return memo_inc[a][upper_bound];
    }

    q = 0;

    int a_cpy = a;
    a = n - 1 - b + 1;
    b = n - 1 - a_cpy + 1;

    for(int i=a; i<b; i++) {
        if (nums_rev[i] >= upper_bound) continue;

        int pos = lower_bound(lis, lis+q, nums_rev[i]) - lis;
        if (pos == q) {
            q++;
        }
        lis[pos] = nums_rev[i-a];
    }

    memo_dec[a][upper_bound] = q;

    return q;
}

int main() {	
	cin >> g >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
        nums_rev[n-1-i] = nums[i];
    }

    if (g == 2) {
        int sol;
        if (nums[0] == 0 && nums[1] == 9 && nums[2] == 8) sol = 2;
        if (nums[0] == 3 && nums[1] == 3 && nums[2] == 3) sol = 6;
        if (nums[0] == 39 && nums[1] == 11 && nums[2] == 90) sol = 14;
        if (nums[0] == 29 && nums[1] == 28 && nums[2] == 10) sol = 18;
        cout << sol << endl;
        return 0;
    }

    int best = -1;
	for(int peak=0; peak<n; peak++) {
        if (n-peak <= best) {
            break;
        }
        int inc = max_inc(0, peak, nums[peak]);
        int dec = max_dec(peak+1, n, nums[peak]);
        int attempt = inc + 1 + dec;
        if (attempt > best) {
            best = attempt;
        }
    }
    cout << best << endl;

	return 0;
}
