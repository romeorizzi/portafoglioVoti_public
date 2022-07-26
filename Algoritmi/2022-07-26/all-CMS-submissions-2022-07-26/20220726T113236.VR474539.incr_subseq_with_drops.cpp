/**
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 11:32:36.429162
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input;

int sol(int drops) {
    vector<int> resultAtIndex;

    for (int i = 0; i < input.size(); i++) {
        results.push_back(1);
    }

    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (input[i] > input[j] && resultAtIndex[i] <= resultAtIndex[j])
                resultAtIndex[i] = resultAtIndex[j] + 1;
        }
    }

    return *max_element(resultAtIndex.begin(), resultAtIndex.end());
}

int main() {
    int g, n, k;

    cin >> g >> n >> k;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }

    cout << sol(k) << endl;

}