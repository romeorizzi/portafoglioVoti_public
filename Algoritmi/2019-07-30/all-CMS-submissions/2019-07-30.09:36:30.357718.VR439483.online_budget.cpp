/**
* user:  VR439483
* fname: MIRKO
* lname: MORATI
* task:  online_budget
* score: 67.0
* date:  2019-07-30 09:36:30.357718
*/
#include <iostream>
using namespace std;

const int MAX_N = 50;
const int MAX_VAL = 10;

int n, B0, x[MAX_N];

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

int recc(int r, int p, int max) {
    static int count = 0;
    if (p > 0) {
        max += x[p - 1] - mem[r][p - 1];
    }
    // cout << "max: " << max << endl; 
    for (int i = 0; i <= max; i++) {
        mem[r + i][p] = i;
       // cout << "r, r + i, p: " << r << " " << r + i << " " << p << endl;        
        for (int j = 0; j < 4; j++) {
        //    print_array(mem[j], 4);
        }
        // cout << endl;
        if (p < n - 1)
            recc(r + i, p + 1, max);
        else if (mem[r + i][p] >= 0) {
            count++;
        }    
    }
    return count;
}


int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    //print_array(x, n);
    // cout << "B0: " << B0 << endl;
    cout << recc(0, 0, B0) << endl;
       
    return 0;
}

