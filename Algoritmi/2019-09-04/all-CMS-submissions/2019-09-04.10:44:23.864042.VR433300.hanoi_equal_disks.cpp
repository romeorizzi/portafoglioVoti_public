/**
* user:  VR433300
* fname: INCUDINI
* lname: MASSIMILIANO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 10:44:23.864042
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

typedef long long unsigned int llu;
llu num_mosse = 0;

void sposta(int n, char piolo_from, char piolo_to, int piolo_not_used, void (*diskaction)(int,char,char)) {
  if(n <= 0) return;
  sposta(n-1, piolo_from, piolo_not_used, piolo_to, diskaction);
  (*diskaction)(n, piolo_from, piolo_not_used);
  sposta(n-1, piolo_not_used, piolo_to, piolo_from, diskaction);
}

void incmosse(int n, char piolo_from, char piolo_to) {
  num_mosse++;
}

void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}


int main() {
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  }
  llu num_mosse = 1;
  if(t==0) {
    sposta(N, 'A', 'B', 'C', &incmosse);
    printf("%llu\n", num_mosse);
  }
  else
    sposta(N, 'A', 'B', 'C', &sposta_disco);
        
  return 0;
}

