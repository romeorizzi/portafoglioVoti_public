/**
* user:  VR418781
* fname: BRENTEGANI
* lname: MATTEO
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 10:45:35.444854
*/

#include <math.h>
#include <iostream>

using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {

    if (n==1) {
        cout << " sposta il disco " << n << " dal piolo " << from_rod << " al piolo " << to_rod << endl;        
        return;    
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    cout << "sposta il disco " << n << " dal piolo " << from_rod << " al piolo " << to_rod << endl;
    
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main() {
    int t, n;


    cin >> t >> n;

    if (t == 0) cout << pow(2, n)-1;


    towerOfHanoi(n, 'A', 'B', 'C');
}
