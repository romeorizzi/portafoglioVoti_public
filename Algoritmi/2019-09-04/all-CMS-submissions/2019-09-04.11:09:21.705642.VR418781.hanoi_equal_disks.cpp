/**
* user:  VR418781
* fname: BRENTEGANI
* lname: MATTEO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 11:09:21.705642
*/
#include <cassert>
#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long unsigned int llu;
const int MAXN = 100000;

int d[MAXN+1];
int k[MAXN+1];

unsigned long long int count(int diversi, int k[]) {
    llu sum = 0;

    for(int i=1; i <= diversi; i++) {
        sum = sum+k[i]*pow(2, diversi-1);
    }
    return sum;
}

void sposta_torre(int N, char from, char to, char piolo_di_appoggio) {
    assert(N>=0);
    if (N==0) return;

    assert(N>=1);

    sposta_torre(N-1, from, piolo_di_appoggio, to);
     cout << "sposta il disco " << N << " dal piolo " << from << " al piolo " << to << endl;
    sposta_torre(N-1, piolo_di_appoggio, to, from);
}

int main() {
    int t, n;
    int diversi=0, check=1, occ=1;
    int num_mosse = 1;

    cin >> t >> n;
    for (int i=1; i<= n; i++) {
        cin >> d[i];   
    }

    for (int i=0; i<= n; i++) {
        for (int j=0; j <= n; j++) {  
            if (d[i] == d[j]) {check=0; occ++;};
        }
        if(check==1) {diversi++; k[i]=1;}
        if(check==0) {k[i]=occ;}
        occ=1;
        check=1;
        
    }

    if (t==0) cout << count(diversi, k);

    sposta_torre(N, 'A', 'B', 'C');

    return 0;
}
