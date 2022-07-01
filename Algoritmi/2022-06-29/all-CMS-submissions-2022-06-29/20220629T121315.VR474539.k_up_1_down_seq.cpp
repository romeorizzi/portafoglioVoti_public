/**
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  k_up_1_down_seq
* score: 0.0
* date:  2022-06-29 12:13:15.175494
*/
#include <iostream>

using namespace std;

int g, n, k;

int sol(int n)
{
    if (n <= 3)
        return 1;
    
    return sol(n - 1) + sol(n - 2);
}

int main()
{
    cin >> g >> n >> k;
    int res = sol(n) + 1;

    cout << res << endl;
}