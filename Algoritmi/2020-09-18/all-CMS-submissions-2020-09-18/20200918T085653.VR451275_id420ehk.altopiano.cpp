/**
* user:  VR451275_id420ehk
* fname: EDOARDO
* lname: GRASSI
* task:  altopiano
* score: 25.0
* date:  2020-09-18 08:56:53.733441
*/
#include <iostream>

using namespace std;

const auto MAX_N = 100000;

const auto RANGE_SIZE = 16;

int B[MAX_N + 2 * RANGE_SIZE];
int* A = B + RANGE_SIZE;
int R[MAX_N / RANGE_SIZE + 1];

int main()
{
    int N, M;
    cin >> N >> M;
    
    for (auto i = 0; i < RANGE_SIZE; ++i)
        B[i] = -1;
    
    for (auto i = 0; i < N; ++i)
        cin >> B[RANGE_SIZE + i];
    
    for (auto i = 0; i < RANGE_SIZE; ++i)
        B[RANGE_SIZE + N] = -1;
    
    // precompute query table
    const auto range_count = N / RANGE_SIZE;
    for (auto i = 0; i < range_count; ++i)
    {
        int max_a = -1;
        const auto local_i = i * RANGE_SIZE;
        for (auto j = 0; j < RANGE_SIZE + 2; ++j)
        {
            const auto a = i * RANGE_SIZE + j;
            if (A[a] == A[a - 1] && A[a] == A[a - 2])
            {
                max_a = max(max_a, A[a]);
            }
        }
        R[i] = max_a;
    }
    
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
            const auto x_index = x / RANGE_SIZE;
            
            int max_a = -1;
            const auto a = x_index;
            for (auto j = 0; j < RANGE_SIZE + 2; ++j)
            {
                if (A[a] == A[a - 1] && A[a] == A[a - 2])
                {
                    max_a = max(max_a, A[a]);
                }
            }
            R[x_index] = max_a;
            
            const auto x_offset = x % RANGE_SIZE;
            if (x_offset < 2 && x > RANGE_SIZE)
            {
                int max_a = -1;
                const auto a = x_index - RANGE_SIZE;
                for (auto j = 0; j < RANGE_SIZE + 2; ++j)
                    if (A[a] == A[a - 1] && A[a] == A[a - 2])
                        max_a = max(max_a, A[a]);

                R[x_index - 1] = max_a;
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            
            int max_a = -1;
            const auto l_index = l / RANGE_SIZE + 1;
            const auto r_index = r / RANGE_SIZE - 1;
            
            // query inbetween subranges
            for (auto i = l_index; i < r_index; ++i)
                max_a = max(max_a, R[i]);
                
            // query leftmost subrange
            const auto ll = l;
            const auto lr = l + RANGE_SIZE - (l % RANGE_SIZE);
            for (auto i = ll; i <= lr ; ++i)
            {
                if (A[i] == A[i + 1] && A[i] == A[i + 2])
                {
                    max_a = max(max_a, A[i]);
                }
            }
            
            // query rightmost subrange
            const auto rl = r - (r % RANGE_SIZE);
            const auto rr = r;
            for (auto i = rl; i <= rr ; ++i)
            {
                if (A[i] == A[i - 1] && A[i] == A[i - 2])
                {
                    max_a = max(max_a, A[i]);
                }
            }
            
            if (max_a == -1)
                cout << "NESSUN_ALTOPIANO" << '\n';
            else
                cout << max_a << '\n';
        }
    }
}
