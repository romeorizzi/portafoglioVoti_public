/**
* user:  VR472058
* fname: ALESSANDRO
* lname: FURIA
* task:  k_up_1_down_seq
* score: 14.0
* date:  2022-06-29 11:52:27.251464
*/
#include <iostream>

using namespace std;

int counter = 0;

void ric_fun(int num, int n, int k){
    if(n == 0){
        if(num == 0 || num == 1)
            counter++;
    }
    else{
        ric_fun(num, n-1, k);
        ric_fun(num+k, n-1, k);
        if(num != 0)
            ric_fun(num-1, n-1, k);
    }

}

int main()
{
    int g, n, k;

    cin >> g;

    cin >> n;

    cin >> k;


    ric_fun(0, n-2, k);

    cout << counter;
    return 0;
}

