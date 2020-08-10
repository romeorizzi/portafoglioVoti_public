/**
* user:  VR451060_id716xls
* fname: NICHOLAS
* lname: CARON
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 12:40:32.406478
*/
#include <iostream>
#include <vector>
using namespace std;

int cost(string a, string b, int i, int j, int p, int gap, vector<int>& prices, vector<vector<vector<int> > >& matrice) {
    if(gap > p) {
        return 2147483647;
    }
    else if(i == 0) {
        if(j!=0) {
            return   2147483647;
        }
        else
        {
            return prices[gap];
        }
    }
    else {
        if(matrice[gap][i][j] == -2) {
            if(a[a.size()-i] == b[b.size()-j]) {
                int c = cost(a, b, p, i-1, j-1, 0, prices, matrice);
                if(c != 2147483647) c += prices[gap];
                matrice[gap][i][j] = min(c, cost(a, b, p, i-1, j, gap+1, prices, matrice));
            }
            else {
                matrice[gap][i][j] = cost(a, b, p, i-1, j, gap+1, prices, matrice);
            }
        }
        return matrice[gap][i][j];
    }
}

int main() {
    int m, n, p;
    cin >> m >> n >> p;
    vector<int> prices(p+1, 0);
    
    string a;
    string b;
    cin >> a;
    cin >> b;
    
    
    vector<int> js(n+1, -2);
    vector<vector<int> > is(m+1, js);
    vector<vector<vector<int> > > matrice(p+1, is);
    for(int i = 0; i<=p; ++i) {
        cin >> prices[i];
    }
    cout << (cost(a, b, p, a.size(), b.size(), 0, prices, matrice) == 2147483647 ? -1 : cost(a, b, p, a.size(), b.size(), 0, prices, matrice));
    return 0;
}
