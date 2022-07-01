/**
* user:  VR474275
* fname: MICHELE
* lname: QUARESMINI
* task:  k_up_1_down_seq
* score: 58.0
* date:  2022-06-29 12:27:27.548646
*/
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int G, N, K;
int RANK;
string line = "";

int myRank = 0;
int myLine = 0;

int solve(int index, int value, string sequence){
    if(index == N){
        if((G == 2 && myRank == RANK) || G == 4){
            cout << sequence << endl;
            myRank++;
        }
        else if(G == 3 && line == sequence){
            cout << myLine;
        }
        else{
            myRank++;
            myLine++;
        }
        return 1;
    }

    if(value == 0 && index < N - K){
        return solve(index + 1, value, sequence + "0 ") + solve(index + 1, value + K, sequence + to_string(value + K) + " ");
    }
    else if(value == 0 && index >= N - K){
        return solve(index + 1, value, sequence + "0 ");
    }
    else{
        if(index < N - value - K){
            return solve(index + 1, value - 1, sequence + to_string(value-1) + " ") + solve(index + 1, value, sequence + to_string(value) + " ") + solve(index + 1, value + K, sequence + to_string(value + K) + " ");
        }
        else if(index < N - value){
            return solve(index + 1, value - 1, sequence + to_string(value-1) + " ") + solve(index + 1, value, sequence + to_string(value) + " ");
        }
        else{
            return solve(index + 1, value - 1, sequence + to_string(value-1) + " ");
        }
    }
}


int main(){
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));

    cin >> G;
    cin >> N;
    cin >> K;

    if(G == 2)
        cin >> RANK;

    int num;
    if(G == 3){
        for(int i = 0; i < N; i++){
            cin >> num;
            line += to_string(num) + " ";
        }
    }

    int result = solve(1, 0, "0 ");
    
    if(G == 1)
        cout << result;
}