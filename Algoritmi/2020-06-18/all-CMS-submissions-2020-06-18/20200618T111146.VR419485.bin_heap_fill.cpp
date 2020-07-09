/**
* user:  VR419485
* fname: QUINCI
* lname: OLIVIO
* task:  bin_heap_fill
* score: 23.0
* date:  2020-06-18 11:11:46.803935
*/
#include <iostream>
#include <vector>
using namespace std;
int N, PP;
vector<int> GG, VV;
bool HP(vector<int> SS) {
    for (int i = 0; i <= (N - 2) / 2; i++) {
        if (VV[i] == 1 && SS[i] < SS[(i - 1) / 2])
            return false;
    }
    return true;
}
int main() {
    cin >> N >> PP;
    GG.resize(N);
    VV.resize(N);

    for (int i = 0; i < N; i++)
        cin >> GG[i];
    for (int i = 0; i < N; i++)
        cin >> VV[i];

    if (PP == 1)
        cout << HP(GG) << endl;
    return 0;
}