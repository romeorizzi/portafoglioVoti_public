/**
* user:  VR451060_id716xls
* fname: NICHOLAS
* lname: CARON
* task:  align_one_string
* score: 2.0
* date:  2020-07-14 12:48:09.222543
*/
#include <iostream>
#include <vector>
using namespace std;

int effort(string a, string b, int p, int i, int j, int range, vector<int>& prices, vector<vector<vector<int> > >& matrixx) {
    if(range > p) {
        return 2147483647;
    }
    else if(i == 0) {
        if(j!=0) {
            return   2147483647;
        }
        else
        {
            return prices[range];
        }
    }
    else {
        if(matrixx[range][i][j] == -2) {
            if(a[a.size()-i] == b[b.size()-j]) {
                int c = effort(a, b, p, i-1, j-1, 0, prices, matrixx);
                if(c != 2147483647) c += prices[range];
                matrixx[range][i][j] = min(c, effort(a, b, p, i-1, j, range+1, prices, matrixx));
            }
            else {
                matrixx[range][i][j] = effort(a, b, p, i-1, j, range+1, prices, matrixx);
            }
        }
        return matrixx[range][i][j];
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
    vector<vector<vector<int> > > matrixx(p+1, is);
    for(int i = 0; i<=p; ++i) {
        cin >> prices[i];
    }
    cout << (effort(a, b, p, a.size(), b.size(), 0, prices, matrixx) == 2147483647 ? -1 : effort(a, b, p, a.size(), b.size(), 0, prices, matrixx));
    return 0;
}
