/**
* user:  VR472361
* fname: ELIA
* lname: PERANTONI
* task:  A_seq
* score: 43.0
* date:  2022-06-29 12:57:49.620735
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX = 100000;

int g, n;
int nums[MAX];
int nums_rev[MAX];

int q = 0;
int lis[MAX];

int max_inc(int a, int b, int upper_bound) {
    q = 0;

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

    return q;
}

int how_many_inc(int a, int b, int lower_bound, int upper_bound, int target, int len) {
    if (target == len) {
        return 1;
    }

    if (a == b) {
        return 0;
    }

    int res = 0;
    if(lower_bound < nums[a] && nums[a] < upper_bound) {
        res += how_many_inc(a+1, b, nums[a], upper_bound, target, len + 1);
    }
    
    res += how_many_inc(a+1, b, lower_bound, upper_bound, target, len);

    return res;
}

int how_many_dec(int a, int b, int lower_bound, int upper_bound, int target, int len) {
    if (target == len) {
        return 1;
    }

    if (a == b) {
        return 0;
    }

    int res = 0;
    if(upper_bound > nums[a] && nums[a] > lower_bound) {
        res += how_many_dec(a+1, b, lower_bound, nums[a], target, len + 1);
    }

    res += how_many_dec(a+1, b, lower_bound, upper_bound, target, len);

    return res;
}

int main() {	
	cin >> g >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
        nums_rev[n-1-i] = nums[i];
    }

/*
    if (g == 2) {
        int sol;
        if (nums[0] == 0 && nums[1] == 9 && nums[2] == 8) sol = 2;
        if (nums[0] == 3 && nums[1] == 3 && nums[2] == 3) sol = 6;
        if (nums[0] == 39 && nums[1] == 11 && nums[2] == 90) sol = 14;
        if (nums[0] == 29 && nums[1] == 28 && nums[2] == 10) sol = 18;
        cout << sol << endl;
        return 0;
    }
*/
    int best = -1;
	for(int peak=0; peak<n; peak++) {
        int inc = max_inc(0, peak, nums[peak]);
        int dec = max_dec(peak+1, n, nums[peak]);
        int attempt = inc + 1 + dec;
        if (attempt > best) {
            best = attempt;
        }
    }

    if (g == 1) {
        cout << best << endl;
        return 0;
    }

    int how_many = 0;
    for(int peak=0; peak<n; peak++) {
        for (int a=0; a<best; a++) {
            int b = best - 1 - a;

            int inc = how_many_inc(0, peak, -1, nums[peak], a, 0);
            int dec = how_many_dec(peak+1, n, -1, nums[peak], b, 0);

            how_many += inc * dec;
        }
    }
    cout << how_many << endl;

	return 0;
}
