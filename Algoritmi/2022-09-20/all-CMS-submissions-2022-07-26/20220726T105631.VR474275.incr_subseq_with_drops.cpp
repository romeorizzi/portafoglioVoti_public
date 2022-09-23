/**
* user:  VR474275
* fname: MICHELE
* lname: QUARESMINI
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 10:56:31.818713
*/
#include <cassert>
#include <iostream>
using namespace std;

int G, N, K;
const int MAX = 100;
int arr[MAX];

int max(int num1, int num2){
    return num1 > num2 ? num1 : num2;
}

int max(int num1, int num2, int num3){
    if(num1 > num2){
        return num1 > num3 ? num1 : num3;
    }
    else{
        return num2 > num3 ? num2 : num3;
    }
}

/*
int max_sequence(int index, int drop){
    if(index >= N)
        return 0;

    if(drop >= N - index - 1){
        memo[index][drop] = N - index;
        return N - index;
    }

    if(memo[index][drop] != -1)
        return memo[index][drop];

    int result;
    if(arr[index] >= arr[index + 1] && index != N - 1)
        result = max(max_sequence(index + 1, drop - 1) + 1, max_sequence(index + 1, drop));
    else
        result = max_sequence(index + 1, drop) + 1;

    memo[index][drop] = result;
    return result;
    

    int didDrop = 0;
    int noDrop = 0;
    int leave = 0;

    if(arr[index] > arr[index - 1])
        noDrop = 1 + max_sequence(index + 1, drop);

    leave = max_sequence(index + 1, drop);

    if(drop > 0 && arr[index] <= arr[index - 1])
       didDrop = 1 + max_sequence(index + 1, drop - 1);

    return max(noDrop, leave, didDrop);
}


int check_memo(int num){
    int sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(memo[i][j] == num){
                sum++;
                
            }
            //cout << memo[i][j] << " ";
        }
        //cout << endl;
    }
    return sum + 1;
}
*/

int max_sequence(int index, int prev, int drop){
    if(index >= N)
       return 0;
    
    int take = 0;
    int take_wrong = 0;
    int leave = 0;

    if(arr[index] > prev)
       take = 1 + max_sequence(index+1, arr[index], drop);

    leave = max_sequence(index+1, prev, drop);

    if(drop > 0 && arr[index] <= prev)
       take_wrong = 1 + max_sequence(index+1, arr[index], drop - 1);

    return max(take, leave, take_wrong);
}


int main(){
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));

    cin >> G >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        //for(int j = 0; j < N; j++)
            //memo[i][j] = -1;
    }

    if(G == 1){
        int n_max = 0;
        for(int i = 1; i < N; i++){
            if(n_max > N - i)
                break;
            n_max = max(n_max, 1 + max_sequence(i, arr[i - 1], K));

            cout << n_max;
        }
    }
}