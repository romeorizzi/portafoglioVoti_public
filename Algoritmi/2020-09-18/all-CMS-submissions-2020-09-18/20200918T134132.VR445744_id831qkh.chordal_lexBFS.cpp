/**
* user:  VR445744_id831qkh
* fname: RICCARDO
* lname: BARTOLOMIOLI
* task:  corrected-chordal_lexBFS
* score: 20.0
* date:  2020-09-18 13:41:32.008407
*/
#include <iostream>
#include <algorithm>
using namespace  std;
int g, N, M;
bool adj[10000][10000] = {false};

int g_three() {
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
    return max_clique;
}

void g_five() {
    int coloring[100000], color = 1;
    int colors_count[100000] = {0}, colors_sub[100000] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (adj[j][i] && coloring[j] == color) {
                //cout << j << "-" << i << ", " << color << endl;
                color++;
                j = 0;
            }
        }
        colors_count[color]++;
        coloring[i] = color;
        color = 1;
    }
    int colnum = g_three();
    for (int i = 1; i <= colnum; i++){
        int x = distance(colors_count, max_element(colors_count, colors_count + colnum));
        colors_count[x] = 0;
        colors_sub[x] = i;
    }
    for (int i = 0; i <= N-1; i++)
        cout << colors_sub[coloring[i]];
    cout << endl;
}

/* incompleto
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
 */

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

    switch (g) {
        case 3: {
            g_three();
            break;
        }
        case 5: {
            g_five();
            break;
        }
        default: {
            cout << "Errore";
        }
    }
    return 0;
}

