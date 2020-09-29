/**
* user:  VR451275_id420ehk
* fname: EDOARDO
* lname: GRASSI
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 13:00:24.592977
*/
#include <iostream>
#include <limits>
#include <string>

using namespace std;

const auto MAX_M = 1000;
const auto MAX_N = 1000;
const auto MAX_P = 1000;

int m, n, p;    
string a;
string b;
uint32_t cost[MAX_P];

uint32_t solve(int len_b, int ia, int ib)
{
    if (len_b == m)
    {
        if (ia == m && ib == n)
            return 0;
        else
            return numeric_limits<uint32_t>::max();
    }
        
    auto c = numeric_limits<uint32_t>::max();
    if (ia < m && ib < n && a[ia] == b[ib])
    {
        c = solve(len_b + 1, ia + 1, ib + 1);
    }
    for (auto i = 1; i <= min(m - len_b, p); ++i)
    {
        c = min(c, solve(len_b + i, ia + i, ib) + cost[i]);
    }
    return c;
}

int main()
{
    cin >> m >> n >> p;
    cin >> a;
    cin >> b;
    for (auto i = 0; i < p + 1; ++i)
        cin >> cost[i];
    
    /*
    int c[MAX_M + 1][MAX_N + 1] = {};    
    for (auto i = 1; i < m; ++i)
    {
        for (auto j = 1; j < n; ++p)
        {
            if (a[i] == b[j])
        }
    }
    */
    
    const auto s = solve(0, 0, 0);
    if (s == numeric_limits<uint32_t>::max())
        cout << "-1" << '\n';
    else
        cout << s << '\n';
}
