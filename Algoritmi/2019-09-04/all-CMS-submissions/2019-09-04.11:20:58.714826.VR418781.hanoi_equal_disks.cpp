/**
* user:  VR418781
* fname: BRENTEGANI
* lname: MATTEO
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 11:20:58.714826
*/
#include <cassert>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int mode;
int N;
vector<int> disk;
vector<int> card;
vector<int> partSum;

unsigned long long int count() {
    long long int sum =0;

    for (int i=1; i <=disk.size(); i++) {
        sum = sum +card[i-1]*pow(2, disk.size()-i);
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
    int temp;
    for (int i=1; i<= n; i++) {
        cin >> temp;
        if (disk.size() == 0 || disk[disk.size()-1] != temp) {   
            disk.push_back(temp);
            card.push_back(0);        
        }    
        card[disk.size()-1] = card[disk.size()-1]+1;
    }

    if (t==0) cout << count();

    sposta_torre(n, 'A', 'B', 'C');

    return 0;
}
