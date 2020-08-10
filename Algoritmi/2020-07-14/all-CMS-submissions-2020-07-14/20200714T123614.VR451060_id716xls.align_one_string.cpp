/**
* user:  VR451060_id716xls
* fname: NICHOLAS
* lname: CARON
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 12:36:14.894599
*/
#include <iostream>
#include <vector>
using namespace std;

int cost(string a, string b,int gap, int i, int j, int p, vector<int>& price, vector<vector<vector<int> > >& container) {
    if(gap > p) {
        return 2147483647;
    }
    else if(i == 0) {
        if(j!=0) {
            return   2147483647;
        }
        else
        {
            return price[gap];
        }
    }
    else {
        if(container[gap][i][j] == -2) {
            if(a[a.size()-i] == b[b.size()-j]) {
                int c = cost(a, b, p, i-1, j-1, 0, price, container);
                if(c != 2147483647) c += price[gap];
                container[gap][i][j] = min(c, cost(a, b, p, i-1, j, gap+1, price, container));
            }
            else {
                container[gap][i][j] = cost(a, b, p, i-1, j, gap+1, price, container);
            }
        }
        return container[gap][i][j];
    }
}




int main() {
    int n, p, m;
    cin >> m >> n >> p;
    vector<int> price(p+1, 0);
    string a;
    string b;
    cin >> a;
    cin >> b;
    vector<int> js(n+1, -2);
    vector<vector<int> > is(m+1, js);
    vector<vector<vector<int> > > container(p+1, is);
    for(int i = 0; i<=p; ++i) {
        cin >> price[i];
    }
    cout << (cost(a, b, p, a.size(), b.size(), 0, price, container) == 2147483647 ? -1 : cost(a, b, p, a.size(), b.size(), 0, price, container));
    return 0;
}
