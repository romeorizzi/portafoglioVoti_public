/**
* user:  VR418781
* fname: BRENTEGANI
* lname: MATTEO
* task:  Prob2_hanoi_equal_disks
* score: 40.0
* date:  2019-09-04 11:39:17.628336
*/
#include <cassert>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

int mode;
int n;
vector<int> disk;
vector<int> card;

int count() {
    long long int sum =0;

    for (int i=1; i <=disk.size(); i++) {
        sum = sum + card[i-1]*pow(2, disk.size()-i);
    }
    return sum;
}

void sposta_torre(int N, char from, char to, char piolo_di_appoggio) {
    assert(n>=0);
    if (n==0) return;

    assert(n>=1);

    sposta_torre(n-1, from, piolo_di_appoggio, to);
     cout << "sposta il disco " << n << " dal piolo " << from << " al piolo " << to << endl;
    sposta_torre(n-1, piolo_di_appoggio, to, from);
}

int main() {
    scanf("%i %i", &mode, &n);
    unsigned int temp;
    for (int i=0; i < n; i++) {
        scanf("%i", &temp);
        if (disk.size() == 0 || disk[disk.size() - 1] != temp) {   
            disk.push_back(temp);
            card.push_back(0);        
        }    
        card[disk.size() - 1] = card[disk.size() - 1] + 1;
    }

    if (mode==0) cout << count();
    else 
        sposta_torre(n, 'A', 'B', 'C');

    return 0;
}
