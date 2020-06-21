/**
* user:  VR420921
* fname: AGRILLO
* lname: ENRICO CARLO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 11:09:29.802373
*/
/**
 * Un template per la tua soluzione di hanoi_equal_disks
 * Romeo Rizzi, 2019-08-28
 *
 */

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <cassert>

using namespace std;

int mode
int N;
vector<int> disk;
vector<int> card;

unsigned long long int count()
{
    long long int sum = 0;
    
    for (int i = 1; i <= disk.size(); i++) {

        sum = sum + card[i-1] * pow(2, disk.size() - i);

    }

    return sum;

}


void sposta_disco(int n, int from, int to) {
    printf("sposta il disco %d dal piolo %c al piolo %c\n", n, from, to);
}


void hanoi(int N, int from, int to, int aux)
{
    assert(N >= 0);
    if (N == 0) return;

    assert(N >= 1);

    hanoi(N - 1, from, aux, to);
    sposta_disco(N, from, to);
    hanoi(N - 1, aux, to, from);
}

int main() {
    scanf("%i %i", &t, &N);
    int tmp;
    for(int i = 0; i < N; i++) {
        scanf("%i", &tmp);
        if (disk.size() == 0 || disk[disk.size() - 1] != tmp) {
            disk.push_back(tmp);
            card.push_back(0);
        }
        card[disk.size() - 1] = card[disk.size() - 1] + 1;
    }

    if(t==0) {
        printf("%i", count());
    }
    else
        hanoi(N, 'A', 'B', 'C');

    return 0;
}
