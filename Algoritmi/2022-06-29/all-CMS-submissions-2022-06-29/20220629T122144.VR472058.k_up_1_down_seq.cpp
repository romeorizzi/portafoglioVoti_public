/**
* user:  VR472058
* fname: ALESSANDRO
* lname: FURIA
* task:  k_up_1_down_seq
* score: 14.0
* date:  2022-06-29 12:21:44.927548
*/
#include <iostream>
#define N 1000

using namespace std;

int counter = 0;

int memo[1000][1000] = {0};

int ric_fun(int num, int n, int k){
    if(memo[num][n] != 0){
        return memo[num][n];
    }
    else if(n == 0){
        if(num == 0 || num == 1)
            memo[num][n] = 1;
            return memo[num][n];
    }
    else{
        memo[num][n] = ric_fun(num, n-1, k) + ric_fun(num+k, n-1, k);
        if(num != 0)
            memo[num][n] += ric_fun(num-1, n-1, k);
        return memo[num][n];
    }

}

int main()
{
    int g, n, k;

    cin >> g;

    cin >> n;

    cin >> k;

    ric_fun(0, n-2, k);

    cout << memo[0][n-2];
    return 0;
}

