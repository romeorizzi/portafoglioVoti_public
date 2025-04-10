/**
* user:  VR439254_id142nxb
* fname: ANDREA
* lname: TOAIARI
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 11:14:05.088015
*/
#include <iostream>

using namespace std;

#define MAX 1000

char first[MAX];
char second[MAX];
int costs[MAX];
int M, N, p;
int table[MAX][MAX];



int diff(int index1, int index2){
    if (first[index1] != second[index2])
        return 1;
    else 
        return 0;
}

int main(){

    cin >> M >> N >> p;


    for (int i=1; i<=M; i++){
        cin >> first[i];
        table[i][0] = i;
    }
    for (int i=1; i<=N; i++){
        cin >> second[i];
        table[0][i] = i;
    }
    for (int i=0; i<p; i++)
        cin >> costs[i];
    
    for (int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            table[i][j] = min(min(table[i-1][j] +1, table[i][j-1] + 1), table[i-1][j-1] + diff(i, j));
        }
    }


    // cout << table[M][N] << endl;


    // for (int i=0; i<=M; i++){
    //     for(int j=0; j<=N; j++){
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << costs[table[M][N]] << endl;
    return 0;
}