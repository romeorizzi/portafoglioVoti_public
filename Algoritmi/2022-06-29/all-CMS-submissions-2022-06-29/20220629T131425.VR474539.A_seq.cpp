/**
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 13:14:25.616114
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int g, n;
vector<int> in;

const int MAX_N = 10000;
const int UNKNOWN = 0;
vector<int> memo;
int mem = 0;

int sol(int currentIndex, int length, bool crescendo, int lastTaken)
{
    static int prevLength = 0;

    if (currentIndex == in.size() - 1) {
        if (crescendo && in[currentIndex] > lastTaken)
            return length + 1;
        else if (!crescendo && in[currentIndex] < lastTaken)
            return length + 1;
        else
            return length;
    }

    for (int i = 0; i < n +5; i++)
        cout << memo[i] << " ";
    cout << '\n';
    cout << length << endl;

    if (memo[currentIndex] != UNKNOWN && prevLength < length)
    {
        prevLength = length;
        return memo[currentIndex];
    }
    
    if (crescendo) {
        if (in[currentIndex] > lastTaken) {
            memo[currentIndex] = max(sol(currentIndex + 1, length + 1, true, in[currentIndex]),
                        sol(currentIndex + 1, length, true, lastTaken));
            return memo[currentIndex];
        }
        else if (in[currentIndex] < lastTaken)
        {
            memo[currentIndex] = max(sol(currentIndex + 1, length + 1, false, in[currentIndex]),
                        sol(currentIndex + 1, length, true, lastTaken));
            return memo[currentIndex];
        }
        else
        {
            memo[currentIndex] = sol(currentIndex + 1, length, true, lastTaken);
            return memo[currentIndex];
        }
    }
    else {
        if (in[currentIndex] < lastTaken) {
            memo[currentIndex] = max(sol(currentIndex + 1, length + 1, false, in[currentIndex]),
                        sol(currentIndex + 1, length, false, lastTaken));
            return memo[currentIndex];
        }
        else 
        {
            memo[currentIndex] = sol(currentIndex + 1, length, false, lastTaken);
            return memo[currentIndex];
        }
    } 
}

int main()
{
    cin >> g >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        in.push_back(0);
        in[i] = tmp;
    }

    for (int i = 0; i < MAX_N; i++)
        memo.push_back(UNKNOWN);

    int res = sol(0, 0, true, -1);
    cout << res << endl;

    for (int i = 0; i < n +5; i++)
        cout << memo[i] << " ";
    cout << '\n';

    return 0;
}