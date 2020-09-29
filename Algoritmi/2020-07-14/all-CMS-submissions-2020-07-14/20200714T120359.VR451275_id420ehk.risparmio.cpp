/**
* user:  VR451275_id420ehk
* fname: EDOARDO
* lname: GRASSI
* task:  risparmio
* score: 80.0
* date:  2020-07-14 12:03:59.473537
*/
#include <iostream>
#include <vector>

const auto MAX_N = 100000;
const auto MAX_M = 200000;

int main()
{
    using namespace std;
    
    int N, M;
    cin >> N >> M;
    std::vector<bool> a(N, false);
    for (auto i = 0; i < M; ++i)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i;
            cin >> i;
            a[i] = !a[i];
        }
        else
        {
            int l, r;
            cin >> l >> r;
            
            int count = static_cast<int>(a[l]);
            for (auto j = l; j < r; ++j)
            {
                count += static_cast<int>(!a[j] & a[j + 1]);
            }
            cout << count << '\n';
        }
    }
}
