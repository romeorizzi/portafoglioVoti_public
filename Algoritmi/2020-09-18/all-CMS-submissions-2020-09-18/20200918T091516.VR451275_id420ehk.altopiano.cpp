/**
* user:  VR451275_id420ehk
* fname: EDOARDO
* lname: GRASSI
* task:  altopiano
* score: 1.0
* date:  2020-09-18 09:15:16.023248
*/
#include <iostream>

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
            
            int max_a = -1;
            for (auto i = 0; i < r - 2; ++i)
            {
                if (A[i] == A[i + 1] && A[i] == A[i + 2])
                    max_a = max(max_a, A[i]);
            }
            
            if (max_a == -1)
                cout << "NESSUN_ALTOPIANO" << '\n';
            else
                cout << max_a << '\n';
        }
    }
}
