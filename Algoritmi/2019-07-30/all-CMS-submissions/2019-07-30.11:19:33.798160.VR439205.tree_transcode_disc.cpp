/**
* user:  VR439205
* fname: LUMPP
* lname: FRANCESCO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 11:19:33.798160
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 500;
const int MAX_VAL = 10;

const int MAXB = 701;
const int MAXX = 51;
int * x;
int val[MAXX][MAXB];
int n, B0;

int ric(int j, int k){
    if (val[j][k] != 0){ 
        return val[j][k];
    }
    if (j == n-1) {
        return k+1;
    }
    
    for (int i = 0; i<=k;i++){
        if (val[j][i] == 0){
            val[j][i] = (val[j][i-1]+ric(j+1, i+x[j]))%1000000007;
        }
    }
    return val[j][k];

}

int main() {
    cin >> n >> B0;

    x = new int[MAX_N];

    for(int i = 0; i < n; i++) {
      cin >> x[i];
    }
    
    int res = ric(0, B0);

    cout << res << endl;
    return 0;
}
