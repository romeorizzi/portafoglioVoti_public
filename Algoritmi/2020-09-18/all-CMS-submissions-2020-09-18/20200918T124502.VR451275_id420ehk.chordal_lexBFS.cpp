/**
* user:  VR451275_id420ehk
* fname: EDOARDO
* lname: GRASSI
* task:  chordal_lexBFS
* score: 0.0
* date:  2020-09-18 12:45:02.094066
*/
#include <iostream>
#include <vector>

using namespace std;

const auto MAX_N = 10000;
const auto MAX_M = 200000;

int g, N, M;
    
vector<int> E[MAX_N] = {};
bool MAT[MAX_N][MAX_N] = { false };

int task2()
{
    bool checked[MAX_N] = { false };
    for (auto i = N - 1; i < 0; --i)
    {
        if (!checked[i])
        {
            checked[i] = true;
            for (auto n : E[i])
                checked[n] = true;
                
            for (auto n1 : E[i])
                for (auto n2 : E[i])
                    if (!MAT[n1][n2])
                        return i + 1;
        }
    }
    return -1;
}

int task3()
{
    auto max_w = 0;
    for (auto i = 0; i < N; ++i)
    {
        auto count = 0;
        for (auto n : E[i])
            if (n > i)
                ++count;
                
        max_w = max(max_w, count);
    }
    return max_w;
}

int task4()
{
    auto max_w = 0;
    auto max_i = 0;
    for (auto i = 0; i < N; ++i)
    {
        auto count = 0;
        for (auto n : E[i])
            if (n > i)
                ++count;
        
        if (count >= max_w)
        {
            max_w = count;
            max_i = i;
        }
    }
    cout << max_w << '\n';
    for (auto n1 : E[i])
        for (auto n2 : E[i])
            if (MAT[n1][n2])
                cout << 
}

int main()
{
    cin >> g >> N >> M;
    
    for (auto i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
        MAT[u][v] = true;
        MAT[v][u] = true;
    }
    
    switch (t)
    {
        case 1:
        {
            break;
        }
        
        case 2:
        {
            const auto r = task2();
            if (r == -1)
            {
                for (auto i = N; i < 0; --i)
                    cout << i << ' ';
            }
            break;
        }
        
        case 3:
        {
            const auto w = task3();
            cout << w;
        }
        
    }
}
