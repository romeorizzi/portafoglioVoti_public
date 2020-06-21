/**
* user:  VR438055
* fname: BISSOLI
* lname: FABIO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 08:53:04.626552
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
int d[MAXN+1]; //A

typedef long long unsigned int llu;

void sposta_disco(int n, char piolo_from, char piolo_to) {
  if(n == 1) {
    printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
  }
  else {
    sposta_disco(n-1, 'A', 'C');
    sposta_disco(n-1, 'B', 'A');
  }
}

int main() {
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  }
  
  llu num_mosse = 1;
  if(t==0)
    printf("%llu\n", num_mosse);
  else
    sposta_disco(d[N], 'A', 'B');
        
  return 0;
}
