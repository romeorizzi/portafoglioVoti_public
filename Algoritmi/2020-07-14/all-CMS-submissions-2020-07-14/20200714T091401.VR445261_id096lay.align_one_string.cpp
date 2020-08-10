/**
* user:  VR445261_id096lay
* fname: NICOLA
* lname: SCARABELLO
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 09:14:01.782395
*/
#include <iostream>
#include <vector>
using namespace std;

int cost(string a, string b, int i, int j, int gap, vector<int>& costs, vector<vector<int>>& mat) {
    if(i == 0) {
        if(j!=0) {
            return -1;
        }
        else
        {
            return costs[gap];
        }
    }
    else {
        if(mat[i][j] == -2) {
            if(a[a.size()-i] == b[b.size()-j]) {
                mat[i][j] = max(costs[gap]+cost(a, b, i-1, j-1, 0, costs, mat), cost(a, b, i-1, j, 1, costs, mat));
            }
            else {
                mat[i][j] = cost(a, b, i-1, j, gap+1, costs, mat);
            }
        }
        return mat[i][j];
    }
}

int main() {
    int m, n, p;
    cin >> m >> n >> p;
    vector<int> costs(p+1);
    string a;
    string b;
    cin >> a;
    cin >> b;
    vector<int> js(n+1, -2);
    vector<vector<int>> is(m+1, js);
    for(int i = 0; i<=p; ++i) {
        cin >> costs[i];
    }
    cout << cost(a, b, a.size(), b.size(), 0, costs, is);
    return 0;
}