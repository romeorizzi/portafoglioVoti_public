/**
* user:  VR445744_id831qkh
* fname: RICCARDO
* lname: BARTOLOMIOLI
* task:  chordal_lexBFS
* score: 20.0
* date:  2020-09-18 11:36:48.639337
*/
#include <iostream>
using namespace  std;
int g, N, M;
bool adj[10000][10000] = {false};

void g_three(){
    int max_clique = 0;
    for(int i = 0; i < N; i++) {
        int counter = 0;
        for (int j = i; j < N; j++) {
            if (adj[i][j])
                counter++;
        }
        max_clique = max(max_clique, counter);
    }
    cout << max_clique << endl;
}

//incompleto
void g_two() {
    for (int i = N-1; i > 0; i--) {
        for (int j = N-1; j >= i; j--) {
            if (!adj[i][j] && adj[i - 1][j]){
                cout << "no perfect: " << i+1 << endl;
                return;
            }
        }
    }
    cout << "perfect" << endl;
}

int main() {
    cin >> g >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1][v-1] = true;
        adj[v-1][u-1] = true;
    }

    for (int i = 0; i < N; i++)
        adj[i][i] = true;

    g_three();
    return 0;
}

