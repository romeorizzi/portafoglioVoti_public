/**
* user:  VR436747
* fname: BRAGOI
* lname: VLADISLAV
* task:  online_budget
* score: 1.0
* date:  2019-07-30 11:59:22.428066
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
#include <math.h>
using namespace std;

const int MAX_N = 500;
const int MAX_VAL = 10;

int n, B0, x[MAX_N];
int B[MAX_N];
int B_primo[MAX_N];
int y[MAX_N];
int counts[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int main() {
    cin >> n;

    fill_n(y, n+1, 0);                      // vettore y
    fill_n(B_primo, n+1, 0);
    fill_n(B, n+1, 0);
    fill_n(counts, n+1, 0);
    cin >> B[0];

    int tmp = 0;
    long unsigned sum= 0L;
    for(int i = 1; i <= n; i++) {
       cin >> x[i];
    }

    int y = 0;
    for (int i = 1; i <= n; ++i)            // ciclo sugli n>=1 periodi
    {
        B_primo[i] = B[i-1];
        counts[i] = B_primo[i];

        y = counts[i];
        while (y >= 0) {
            sum += (counts[i] - y);           
            y--;
        }
       
        B[i] = B_primo[i] + x[i];
    }

    cout << ++sum << endl; // *max_element(counts+1, counts+n) % 1000000007 << endl;
    return 0;
}