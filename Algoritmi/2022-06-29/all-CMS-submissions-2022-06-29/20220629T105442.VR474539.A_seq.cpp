/**
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  A_seq
* score: 13.0
* date:  2022-06-29 10:54:42.286955
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
    if (currentIndex == in.size() - 1) {
        if (crescendo && in[currentIndex] > lastTaken)
            return length + 1;
        else if (!crescendo && in[currentIndex] < lastTaken)
            return length + 1;
        else
            return length;
    }
    
    if (crescendo) {
        if (in[currentIndex] > lastTaken) {
            return max(sol(currentIndex + 1, length + 1, true, in[currentIndex]),
                        sol(currentIndex + 1, length, true, lastTaken));
        }
        else if (in[currentIndex] < lastTaken)
        {
            return max(sol(currentIndex + 1, length + 1, false, in[currentIndex]),
                        sol(currentIndex + 1, length, true, lastTaken));
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

    return length;
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