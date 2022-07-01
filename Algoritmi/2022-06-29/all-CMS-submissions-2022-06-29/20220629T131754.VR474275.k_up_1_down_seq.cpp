/**
* user:  VR474275
* fname: MICHELE
* lname: QUARESMINI
* task:  k_up_1_down_seq
* score: 14.0
* date:  2022-06-29 13:17:54.022350
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

int solve(int index, int value, string sequence, int **memo){
    if(index == N){
        return 1;
    }

    if(memo[index][value] != -1 && G == 1){
        return memo[index][value];
    }

    int result;
    string resultString;
    if(value == 0 && index < N - K){
        result = solve(index + 1, value, sequence + "0 ", memo) + solve(index + 1, value + K, sequence + to_string(value + K) + " ", memo);
    }
    else if(value == 0 && index >= N - K){
        result = solve(index + 1, value, sequence + "0 ", memo);
    }
    else{
        if(index < N - value - K){
            result = solve(index + 1, value - 1, sequence + to_string(value-1) + " ", memo) + solve(index + 1, value, sequence + to_string(value) + " ", memo) + solve(index + 1, value + K, sequence + to_string(value + K) + " ", memo);
        }
        else if(index < N - value){
            result = solve(index + 1, value - 1, sequence + to_string(value-1) + " ", memo) + solve(index + 1, value, sequence + to_string(value) + " ", memo);
        }
        else{
            if((G == 2 && myRank == RANK) || G == 4){
                cout << sequence;
                for(int i = value - 1; i >= 0; i--)
                    cout << i << " ";
                cout << endl;
                myRank++;
                return 1;
            }
            else if(G == 3 && line == sequence){
                for(int i = value - 1; i >= 0; i--)
                    sequence += to_string(i) + " ";
                if(line == sequence)
                    cout << myLine;
                return 1;
            }
            else{
                myRank++;
                myLine++;
            }
            result = solve(index + 1, value - 1, sequence + to_string(value-1) + " ", memo);
        }
    }

    memo[index][value] = result;
    return result;
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

    int **memo = new int*[N];
    for(int i = 0; i < N; i++){
        memo[i] = new int[N];
        for(int j = 0; j < N; j++){
            memo[i][j] = -1;
        }
    }

    int result = solve(1, 0, "0 ", memo);
    
    if(G == 1)
        cout << result;
}