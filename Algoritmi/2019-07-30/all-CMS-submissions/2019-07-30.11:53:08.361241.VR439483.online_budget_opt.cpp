/**
* user:  VR439483
* fname: MIRKO
* lname: MORATI
* task:  online_budget_opt
* score: 0.0
* date:  2019-07-30 11:53:08.361241
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 50;
const int MAX_VAL = 10;

int n, B0, x[MAX_N], q[MAX_N], t;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int mem[200][50];

void rec(int r, int p, int max) {
    if (p > 0)
        max += x[p] - mem[r][p - 1];
 
    for (int i = 0; i < max; i++) {
        mem[r + i][p] = i;
        if (p < n)
            rec(r, p + i + 1, max);
    }
}

int recc(int r, int p, int max, vector<tuple<int, int>> tt) {
    static int count = 0;
    if (p > 0) {
        max += x[p - 1] - mem[r][p - 1];
    }
    static int maxg = 0;
    // cout << "max: " << max << endl; 
    for (int i = 0; i <= max; i++) {
        mem[r + i][p] = i;
       // cout << "r, r + i, p: " << r << " " << r + i << " " << p << endl;        
        for (int j = 0; j < 4; j++) {
        //    print_array(mem[j], 4);
        }
        // cout << endl;
        if (p < n - 1)
            recc(r + i, p + 1, max, tt);
        else if (mem[r + i][p] >= 0) {
            count++;
                    
        }   
        if (p == get<1>(tt[n - 1])) {
        //    cout << "gemme: " << mem[r+i][p] * get<0>(tt[n - 1]) << endl;
            if (mem[r+i][p] * get<0>(tt[n - 1])  > maxg) {
                maxg = mem[r+i][p] * get<0>(tt[n - 1]) ;                    
            }
        }
    }
    if (t == 1) return maxg;
    return count;
}

int main() {
    cin >> n >> B0 >> t;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> q[i];

    //print_array(x, n);
    // cout << "B0: " << B0 << endl;
    vector<tuple<int, int>> tmp;
    
    for (int i = 0; i < n; i++) {
        tmp.emplace_back(q[i], i);    
    }
    
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++) {
    //    cout << get<0>(tmp[i]) <<": " << get<1>(tmp[i]) << endl;
    }
    cout << recc(0, 0, B0, tmp) << endl;
       
    return 0;
}

