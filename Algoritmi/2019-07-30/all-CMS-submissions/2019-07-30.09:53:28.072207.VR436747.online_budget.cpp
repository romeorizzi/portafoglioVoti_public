/**
* user:  VR436747
* fname: BRAGOI
* lname: VLADISLAV
* task:  online_budget
* score: 6.0
* date:  2019-07-30 09:53:28.072207
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MAX_N = 500;
const int MAX_VAL = 10;

int n, B0, x[MAX_N + 1];
int B[MAX_N + 1];
int B_primo[MAX_N + 1];
int y[MAX_N + 1];
int counts[MAX_N + 1];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int main() {
    cin >> n;

    fill_n(B, n+1, 0);
    fill_n(B_primo, n+1, 0);
    fill_n(y, n+1, 0);                      // vettore v
    fill_n(counts, n+1, 0);                 // per contare le possibili soluzioni S
    cin >> B[0];
    set<int> tmp;
    long unsigned sum= 0L;
    
    for(int i = 1; i <= n; i++)
       cin >> x[i];
    // print_array(x, n);
    
    for (int i = 1; i <= n; ++i)            // ciclo sugli n>=1 periodi
    {
        B_primo[i] = B[i-1] - y[i];
        counts[i] = B_primo[i] + 1;

        if (B_primo[i] >= 0)
            sum += counts[i];        

        // cout << "B' = " << B_primo[i] << ",\tsum = " << sum << "\n";

        B[i] = B_primo[i] + x[i];
    }
    
    cout <<  sum << endl; // *max_element(counts+1, counts+n) % 1000000007 << endl;
    return 0;
}

