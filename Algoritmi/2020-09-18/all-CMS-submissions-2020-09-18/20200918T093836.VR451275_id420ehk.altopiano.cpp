/**
* user:  VR451275_id420ehk
* fname: EDOARDO
* lname: GRASSI
* task:  altopiano
* score: 25.0
* date:  2020-09-18 09:38:36.083558
*/
#include <iostream>
#include <limits>

using namespace std;

const auto MAX_N = 100000;

int A[MAX_N];

int main()
{
    int N, M;
    cin >> N >> M;
    
    for (auto i = 0; i < N; ++i)
        cin >> A[i];
    
    for (auto m = 0; m < M; ++m)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            
            // update altitude at x
            A[x] += y;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            
            const auto LIMIT = std::numeric_limits<int>::min();
            
            auto max_a = LIMIT;
            for (auto i = l; i <= r - 2; ++i)
            {
                if (A[i] == A[i + 1] && A[i] == A[i + 2])
                    max_a = max(max_a, A[i]);
            }
            
            if (max_a == LIMIT)
                cout << "NESSUN_ALTOPIANO" << '\n';
            else
                cout << max_a << '\n';
        }
    }
}
