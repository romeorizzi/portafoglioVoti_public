/**
* user:  VR445261_id096lay
* fname: NICOLA
* lname: SCARABELLO
* task:  align_one_string
* score: 2.0
* date:  2020-07-14 09:29:03.460653
*/
#include <iostream>
#include <vector>
using namespace std;

int cost(string a, string b, int i, int j, int gap, vector<int>& costs, vector<vector<vector<int> > >& mat) {
    if(i == 0) {
        if(j!=0) {
            return 	2147483647;
        }
        else
        {
            return costs[gap];
        }
    }
    else {
        if(mat[gap][i][j] == -2) {
            if(a[a.size()-i] == b[b.size()-j]) {
                mat[gap][i][j] = min(costs[gap]+cost(a, b, i-1, j-1, 0, costs, mat), cost(a, b, i-1, j, gap+1, costs, mat));
            }
            else {
                mat[gap][i][j] = cost(a, b, i-1, j, gap+1, costs, mat);
            }
        }
        return mat[gap][i][j];
    }
}

int main() {
    int m, n, p;
    cin >> m >> n >> p;
    vector<int> costs(m+1, 0);
    string a;
    string b;
    cin >> a;
    cin >> b;
    vector<int> js(n+1, -2);
    vector<vector<int> > is(m+1, js);
    vector<vector<vector<int> > > mat(m+1, is);
    for(int i = 0; i<=p; ++i) {
        cin >> costs[i];
    }
    cout << (cost(a, b, a.size(), b.size(), 0, costs, mat) == 2147483647 ? -1 : cost(a, b, a.size(), b.size(), 0, costs, mat));
    return 0;
}