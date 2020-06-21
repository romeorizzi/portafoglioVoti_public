/**
* user:  VR420921
* fname: AGRILLO
* lname: ENRICO CARLO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 11:04:30.314811
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
vector<int> d;
vector<int> k;

void sposta_disco(int n, int from, int to) {
    printf("sposta il disco %d dal piolo %d al piolo %d\n", n, from, to);
}

unsigned long long int conteggio()
{
    long long int sum = 0;
    
    for (int i = 1; i <= d.size(); i++) {

        sum = sum + k[i-1] * pow(2, d.size() - 1);

    }

    return sum;

}

void hanoi(int N, char from, char to, char aux)
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
        if (d.size() == 0 || d[d.size() - 1] != tmp) {
            d.push_back(tmp);
            k.push_back(0);
        }
        k[d.size() - 1] = k[d.size() - 1] + 1;
    }

    if(t==0) {
        printf("%i", conteggio());
    }
    else
        hanoi(N, 'A', 'B', 'C');

    return 0;
}
