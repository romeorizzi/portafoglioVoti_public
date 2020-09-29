/**
* user:  VR451275_id420ehk
* fname: EDOARDO
* lname: GRASSI
* task:  altopiano
* score: 0.0
* date:  2020-09-18 13:12:04.882946
*/
#include <iostream>
#include <limits>

using namespace std;

const auto MAX_N = 100000;

const auto RANGE_SIZE = 64;

int B[MAX_N + 2 * RANGE_SIZE + 2];
int* A = B + RANGE_SIZE;
int R[MAX_N / RANGE_SIZE + 1];

const auto LIMIT = std::numeric_limits<int>::min();

int main()
{
    int N, M;
    cin >> N >> M;
    
    for (auto i = 0; i < RANGE_SIZE; ++i)
        B[i] = LIMIT;
    
    for (auto i = 0; i < N; ++i)
        cin >> B[RANGE_SIZE + i];
    
    for (auto i = 0; i < RANGE_SIZE; ++i)
        B[RANGE_SIZE + N + i] = LIMIT;
    
    
    
    
    if (N <= 10000)
    {
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
    
    
    
    // precompute query table
    auto range_count = N / RANGE_SIZE;
    if (N % RANGE_SIZE != 0)
        ++range_count;
        
    for (auto i = 0; i < range_count; ++i)
    {
        int max_a = LIMIT;
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
        
        for (auto i = 0; i < N; ++i)
            cout << A[i] << ' ';
        cout << '\n';
        
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            
            // update altitude at x
            A[x] += y;
            auto x_range_index = x / RANGE_SIZE;
            
            // update Ri range
            int max_a = LIMIT;
            for (auto j = 0; j < RANGE_SIZE + 2; ++j)
            {
                const auto a = x_range_index * RANGE_SIZE + j;
                if (A[a] == A[a - 1] && A[a] == A[a - 2])
                {
                    max_a = max(max_a, A[a]);
                }
            }
            R[x_range_index] = max_a;
            
            const auto x_offset = x % RANGE_SIZE;
            if (x_offset < 2 && x > RANGE_SIZE) // update Ri-1 range
            {
                --x_range_index;
                int max_a = LIMIT;
                for (auto j = 0; j < RANGE_SIZE + 2; ++j)
                {
                    const auto a = x_range_index * RANGE_SIZE + j;
                    if (A[a] == A[a - 1] && A[a] == A[a - 2])
                        max_a = max(max_a, A[a]);
                }

                R[x_range_index] = max_a;
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            
            int max_a = LIMIT;
            const auto l_index = l / RANGE_SIZE + 1;
            const auto r_index = r / RANGE_SIZE;
            
            // query inbetween subranges
            for (auto i = l_index; i <= r_index; ++i)
                max_a = max(max_a, R[i]);
                
            // query leftmost subrange
            const auto ll = l;
            const auto lr = min(r, l + RANGE_SIZE - (l % RANGE_SIZE));
            for (auto i = ll; i <= lr ; ++i)
            {
                if (A[i] == A[i + 1] && A[i] == A[i + 2])
                {
                    max_a = max(max_a, A[i]);
                }
            }
            
            // query rightmost subrange
            const auto rl = max(l, r - (r % RANGE_SIZE));
            const auto rr = r;
            for (auto i = rl; i <= rr ; ++i)
            {
                if (A[i] == A[i - 1] && A[i] == A[i - 2])
                {
                    max_a = max(max_a, A[i]);
                }
            }
            
            if (max_a == LIMIT)
                cout << "NESSUN_ALTOPIANO" << '\n';
            else
                cout << max_a << '\n';
        }
    }
}
