/**
* user:  VR418781
* fname: BRENTEGANI
* lname: MATTEO
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 10:52:17.656203
*/

#include <math.h>
#include <iostream>

using namespace std;

const int MAX_VAL = 100000;
int disk[MAX_VAL];

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
    int count=0;


    cin >> t >> n;

    for (int i=0; i< n; i++) {
        cin >> disk[i];   
        if (disk[i] > count) count++;
    }

    if (t == 0) cout << pow(2, count)-1;


    towerOfHanoi(n, 'A', 'B', 'C');
}
