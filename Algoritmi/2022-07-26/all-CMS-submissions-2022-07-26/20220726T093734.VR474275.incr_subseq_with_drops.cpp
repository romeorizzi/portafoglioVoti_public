/**
* user:  VR474275
* fname: MICHELE
* lname: QUARESMINI
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 09:37:34.821207
*/
#include <cassert>
#include <iostream>
using namespace std;

int G, N, K;
const int MAX = 100;
int arr[MAX];
int memo[MAX][MAX];

int max(int num1, int num2){
    return num1 > num2 ? num1 : num2;
}

int max_sequence(int index, int drop){
    if(index == N - 1 && drop == -1)
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


/*
int num_drop(int index){
    int maximumIndex = 0;
    for(int i = index + 1; i < N; i++){
        if(arr[i] <= arr[i - 1]){
            maximum[maximumIndex] = i;
            maximumIndex++;
        }
    }
    return maximumIndex;
}

int max_sequence(){
    int drop = K;
    int sequence_length = 0;
    for(int i = 0; i < N; i++){

        if(maximumIndex <= drop)
            return sequence_length + (N - i);
        
        
    }
}
*/

int main(){
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));

    cin >> G >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        for(int j = 0; j < N; j++)
            memo[i][j] = -1;
    }

    int result = max_sequence(0, K);
    if(G == 1)
        cout << result;
    if(G == 2)
        cout << check_memo(result);
}