/**
* user:  VR451275_id420ehk
* fname: EDOARDO
* lname: GRASSI
* task:  gioco_triangolo
* score: 0.0
* date:  2020-07-14 10:23:18.214122
*/
#include <iostream>

using namespace std;

const auto MAX_N = 100000;

void print_move(char m, int x, int y1, int y2)
{
    cout << m << ' ' << x << ' ' << y1 << ' ' << y2;
}

int xor_all(int* l, int size)
{
    int res = 0;
    for (auto i = 0; i < size; ++i)
        res = res ^ l[i];
    return res;
}

int main()
{    
    int t, n;
    int L[MAX_N];
    cin >> t >> n;
    
    for (auto i = 0; i < n; ++i)
        cin >> L[i];
    
    char m;
    int x, y1, y2;
    cin >> m >> x >> y1 >> y2;
    
    if (t == 1)
    {
        if (m == 'N')
            print_move('T', x, y1, y2);
        else
        {
            const auto max_y = max(y1, y2);
            const auto min_y = min(y2, y2);
            
            L[x + 1] = max_y;
            if (min_y != 0)
            {
                L[n] = min_y;
                ++n;
            }
            
            const auto all = xor_all(L, n);
            for (auto i = 0; i < n; ++i)
            {
                const auto leftover = all ^ L[i];
                if (leftover < L[i])
                {
                    print_move('T', i + 1, leftover, 0);
                    break;
                }
            }   
        }
    }
    else
    {
        const auto all = xor_all(L, n);
        if (all == 0)
            cout << 0;
        else
        {
            for (auto i = 0; i < n; ++i)
            {
                const auto leftover = all ^ L[i];
                if (leftover < L[i])
                {
                    cout << 1 << '\n';
                    print_move('T', i + 1, leftover, 0);
                    break;
                }
            }
        }
    }
}
