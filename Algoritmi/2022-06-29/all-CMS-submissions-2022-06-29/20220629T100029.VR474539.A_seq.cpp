/**
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 10:00:29.515976
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int g, n;
vector<int> in;
int indexBigger;

int sol(int currentIndex, int length, bool crescendo, int lastTaken)
{
    if (currentIndex == in.size() - 1)
        return length + 1;
    
    if (crescendo) {
        if (in[currentIndex] > lastTaken) {
            return max(sol(currentIndex + 1, length + 1, true, in[currentIndex]),
                        sol(currentIndex + 1, length, true, lastTaken));
        }
        else if (in[currentIndex] < lastTaken)
        {
            return max(sol(currentIndex + 1, length + 1, false, in[currentIndex]),
                        sol(currentIndex + 1, length, false, lastTaken));
        }
        else
            return sol(currentIndex + 1, length, true, lastTaken);
    }
    else {
        if (in[currentIndex] < lastTaken) {
            return max(sol(currentIndex + 1, length + 1, false, in[currentIndex]),
                        sol(currentIndex + 1, length, false, lastTaken));
        }
        else 
            return sol(currentIndex + 1, length, false, lastTaken);
    }
    //     else
    //     {
    //         crescendo = false;
    //         return max(sol(currentIndex + 1, length + 1, false, in[currentIndex]),
    //                     sol(currentIndex + 1, length, false, lastTaken));
    //     }
    // }
    // else
    //     if (in[currentIndex + 1] < lastTaken)
    //         return max(sol(currentIndex + 1, length + 1, false),
    //                     sol(currentIndex + 1, length, false));
    //     else
    //         return length;
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

    // Debug
    // cout << g << " " << n << endl;
    // for (int i = 0; i < n; i++)
    //     cout << in[i] << " ";
    // cout << '\n';

    int res = sol(0, 0, true, -1);
    cout << res << endl;

    return 0;
}