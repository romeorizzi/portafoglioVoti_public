/**
* user:  VR419626_id746dxp
* fname: MARIAN CLAUDIU
* lname: SOLOMON
* task:  altopiano
* score: 25.0
* date:  2020-09-18 09:10:12.124999
*/
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10000;
int N[MAX], M[MAX][3];

void solve(int i, const int j) {
    bool solved = false;
    for (int q = i + 1; q < j; q++)
        if (N[q - 1] == N[q] && N[q] == N[q + 1])
            i = solved++ ? max(i, N[q - 1]) : N[q - 1];

    printf("%s\n", solved ? to_string(i).c_str() : "NESSUN_ALTOPIANO");
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> N[i];

    for (int i = 0; i < m; i++) {
        cin >> M[i][0] >> M[i][1] >> M[i][2];
        if (M[i][0] == 1)
            N[M[i][1]] += M[i][2];
        else if (M[i][0] == 2)
            solve(M[i][1], M[i][2]);
    }
}
