/**
* user:  VR420921
* fname: AGRILLO
* lname: ENRICO CARLO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 08:10:50.092531
*/
/**
 * Un template per la tua soluzione di hanoi_equal_disks
 * Romeo Rizzi, 2019-08-28
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int t, N;
int d[MAXN+1];

typedef long long unsigned int llu;

llu mosse = 0;

void sposta_disco(int n, char piolo_from, char piolo_to) {
    printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

void hanoi(int N, char from_rod, char to_rod, char aux_rod)
{
    
    if (N == 1)
    {
        cout << "sposta il disco 1 dal piolo " << from_rod << " al piolo " << to_rod << endl;
        return;
    }

    hanoi(N - 1, from_rod, aux_rod, to_rod);
    cout << "sposta il disco " << N << " dal piolo " << from_rod << " al piolo " << to_rod << endl;
    hanoi(N - 1, aux_rod, to_rod, from_rod);

}

int main() {
    scanf("%d%d", &t, &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &d[i]);
    }
    llu num_mosse = 1;
    if(t==0)
        cout << num_mosse << endl;
    else
        hanoi(N, 'A', 'C', 'B');

    return 0;
}
