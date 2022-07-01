/**
* user:  VR472361
* fname: ELIA
* lname: PERANTONI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 09:50:07.151397
*/
#include <iostream>

using namespace std;

const int MAX = 10000;

int g, n;
int nums[MAX];

int when_peak_at(int i) {
    int c = 1, at = nums[i];

    // <<<
    for(int j=i-1; j>=0; j--) {
        if(nums[j] < at) {
            at = nums[j];
            c++;
        }
    }

    // >>>
    at = nums[i];
    for(int j=i+1; j<n; j++) {
        if(nums[j] < at) {
            at = nums[j];
            c++;
        }
    }

    return c;
}

int main() {
    cin >> g >> n;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    int best = -1;
    for(int i=0; i<n; i++) {
        int this_did = when_peak_at(i);
        if(this_did > best) {
            best = this_did;
        }
    }

    cout << best << endl;
}
