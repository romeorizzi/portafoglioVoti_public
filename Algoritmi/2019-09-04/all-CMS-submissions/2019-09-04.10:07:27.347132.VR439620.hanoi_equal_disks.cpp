/**
* user:  VR439620
* fname: MOLINARI
* lname: DAVIDE
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 10:07:27.347132
*/
/**
 * Un template per la tua soluzione di hanoi_equal_disks
 * Romeo Rizzi, 2019-08-28
 *
 */

#include <cassert>
#include <cstdio>

const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int t, N;
int d[MAXN+1];
int sol[MAXN+1];

typedef long long unsigned int llu;

void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

void RisolviRic(int N, char from, char to, char appoggio)
{
    assert(N >= 0);
    if(N == 0) return;
    assert(N>=1);
    RisolviRic(N-1,from,appoggio,to);
    sposta_disco(N,from,to);
    RisolviRic(N-1,appoggio,to,from);
}

int main() {
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
    dCount[d[i]]++;
  }
  llu num_mosse = 1;
  if(t==0)
    printf("%llu\n", num_mosse);
  else
  {
    RisolviRic(N,'A','C','B');
  }
        
  return 0;
}
