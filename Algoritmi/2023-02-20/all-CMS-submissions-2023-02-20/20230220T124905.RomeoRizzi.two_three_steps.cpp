/**
* user:  RomeoRizzi
* fname: Romeo
* lname: Rizzi
* task:  esame_two_three_steps
* score: 100.0
* date:  2023-02-20 12:49:05.048261
*/
/**
 *  Soluzione di two_three_steps
 *
 *  Autore: Romeo Rizzi, 2018-06-14
 *
 *  Costo di questa soluzione: lineare.
 *
 *  Descrizione: programmazione dinamica.
 */

#include <cassert>
#include <cstdio>
#include <algorithm>

#define MAXN 1000000

int N;
int GGG[MAXN]; // GGG[i] = valore del ricordo i-esimo.

int max_sum[MAXN];

int main() {
#ifdef EVAL
    assert( freopen("input.txt", "r", stdin) );
    assert( freopen("output.txt", "w", stdout) );
#endif
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
       scanf("%d", &GGG[i]);
    
    max_sum[N-1] = GGG[N-1];
    if(N >= 2)
       max_sum[N-2] = GGG[N-2];
    if(N >= 3)
       max_sum[N-3] = GGG[N-3] + GGG[N-1];
    for(int i = N-4; i >= 0; i--)
      max_sum[i] = GGG[i] + std::max(max_sum[i+2], max_sum[i+3]); 
    printf("%d\n", max_sum[0]);
    
    return 0;
}

