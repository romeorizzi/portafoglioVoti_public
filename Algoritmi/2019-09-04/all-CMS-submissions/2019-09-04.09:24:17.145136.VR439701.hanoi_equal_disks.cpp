/**
* user:  VR439701
* fname: PUGGIA
* lname: MATTIA
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 09:24:17.145136
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

void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

void spostaTorre(int N, int from, int to, int dest){
  if(N == 0) return;
  spostaTorre(N-1, from, dest, to);
  sposta_disco(N, from, to);
  spostaTorre(N-1, dest, to, from);
  
}


int main() {
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  }
  llu num_mosse = 1;
  if(t==0)
    printf("%llu\n", num_mosse);
  else{
    //sposta_disco(1, 'A', 'B');
    spostaTorre(N, 1, 2, 3);
    spostaTorre(N, 2, 3, 1);
  }
        
  return 0;
}

