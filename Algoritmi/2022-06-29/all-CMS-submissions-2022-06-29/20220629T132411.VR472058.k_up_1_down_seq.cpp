/**
* user:  VR472058
* fname: ALESSANDRO
* lname: FURIA
* task:  k_up_1_down_seq
* score: 14.0
* date:  2022-06-29 13:24:11.707607
*/
#include <iostream>
#define N 1000

using namespace std;

int counter = 0;

int memo[N][N] = {0};

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

int nk_series[N][N];
int ranking = 0;

void ric_fun_due(int num, int n, int k, int maximum){
    if(n == 0){
        if(num == 0 || num == 1){
            nk_series[ranking][maximum-n] = num;
            ranking++;
        }
    }
    else{
        nk_series[ranking][maximum-n] = num;
        ric_fun_due(num, n-1, k, maximum);
        nk_series[ranking][maximum-n] = num+k;
        ric_fun_due(num+k, n-1, k, maximum);
        if(num != 0)
            nk_series[ranking][maximum-n] = num-1;
            ric_fun_due(num-1, n-1, k,maximum);
    }

}

int main()
{
    int g, n, k, r;

    cin >> g;

    cin >> n;

    cin >> k;

    if(g == 1){
        ric_fun(0, n-2, k);
        cout << memo[0][n-2]%1000000007;
    }

    if(g == 2){
        cin >> r;
        ric_fun_due(0, n-2, k, n-2);
        cout << "0 ";
        for(int i=1; i<=n-2; i++){
            cout << nk_series[r][i] << " ";
        }
        cout << "0";
    }



    return 0;
}

