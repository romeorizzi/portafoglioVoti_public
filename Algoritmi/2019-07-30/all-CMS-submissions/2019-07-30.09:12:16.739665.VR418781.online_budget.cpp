/**
* user:  VR418781
* fname: BRENTEGANI
* lname: MATTEO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 09:12:16.739665
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;                             

const int MAX_N = 500;
const int MAX_VAL = 10;

int n, B0, x[MAX_N], combinazioni, index;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int fattoriale(int val) {
    int fatt = 1;
    for (int i = 1; i < val; i++ ) {
        fatt=fatt*i;
    }
    return fatt;
} 

int path(int *v, int  B, int index) {
    if (index == n) return 0;
    combinazioni = fattoriale(B)/fattoriale(n)*(fattoriale(B-n));
    return combinazioni + path(v, B + v[index], index++);
}

int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    //print_array(x, n);

    index = combinazioni = 0;
    //path(x, B0, 0);

    cout << path(x, B0, 0) << endl;
    return 0;
}


/*                                                                                                                                                                                                                                                                                                                                                               
                                    0           1               2
                            0   1   2       0       1       0   1   2
                        0       01 012      0       01      0   01  012

                        000
                        001
                        010
                        011
                        100
                        110
                        111
                        200
                        020
                        002                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

                        3*2 6
                        2*2 4
                        2*1 2
                        2*0 0 
  */                      
