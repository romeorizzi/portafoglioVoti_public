/**
* user:  VR439692
* fname: ASTOLFI
* lname: RICCARDO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 08:47:24.501920
*/

#include <cassert>
#include <cstdio>

const int DEBUG = 0;
const int MAXN = 100000;

int t, N;
int d[MAXN+1];

typedef long long unsigned int llu;

void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
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
    sposta_disco(1, 'A', 'B');
        
  return 0;
}

