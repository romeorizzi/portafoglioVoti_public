/**
* user:  VR445639_id956tpd
* fname: ROSA
* lname: RUSSO
* task:  align_one_string
* score: 2.0
* date:  2020-07-14 13:09:30.152255
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
using namespace std;

int cost(string a, string b, int p, int i, int j, int gap, vector<int>&costs, vector<vector<vector<int>>>&mat){

    if(gap > p){
        return 2147483647;
    }
    else if(i == 0){
        if(j!=0){
            return 2147483647;
        }
        else{
            return costs[gap];
        }
    }else{
        if(mat[gap][i][j] == -2){
            if(a[a.size()-i] == b[b.size()-j]){
                int c = cost(a, b, p, i-1, j-1, 0, costs, mat);

                if(c != 2147483647){
                    c += costs[gap];
                }
                mat[gap][i][j] = min(c, cost(a, b, p, i-1, j, gap+1, costs, mat));
            }
            else{
                mat[gap][i][j] = cost(a, b, p, i-1, j, gap+1, costs, mat);
            }
        }
        return mat[gap][i][j];
    }
}

int main(){

    int m, n, p;
    
    cin >> m; // len(a)
    cin >> n; // len(b)
    assert(n <= m);
    cin >> p; // cost[p+1]

    assert(m >= 1);
    assert(m <= 1000);
    assert(n >= 1);
    assert(n <= 1000);
    assert(p >= 1);
    assert(p <= 1000);

    vector<int> costs(p+1, 0);
    
    string a;
    string b;
    cin >> a;
    int a_len = a.length();
    assert(a_len = m);
    cin >> b;
    int b_len = b.length();
    assert(b_len = n);
    
    vector<int> js(n+1, -2);
    vector<vector<int> > is(m+1, js);
    vector<vector<vector<int> > > mat(p+1, is);

    for(int i = 0; i<=p; ++i) {
        cin >> costs[i];
    }

    cout << (cost(a, b, p, a.size(), b.size(), 0, costs, mat) == 2147483647 ? -1 : cost(a, b, p, a.size(), b.size(), 0, costs, mat));

    return 0;
}
