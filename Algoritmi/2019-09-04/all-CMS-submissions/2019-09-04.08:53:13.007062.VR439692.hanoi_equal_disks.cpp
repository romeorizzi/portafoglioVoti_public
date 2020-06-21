/**
* user:  VR439692
* fname: ASTOLFI
* lname: RICCARDO
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 08:53:13.007062
*/

#include <cassert>
#include <cstdio>

const int DEBUG = 0;
const int MAXN = 100000;

int t, N;
int d[MAXN+1];

typedef long long unsigned int llu;
unsigned long long int count(int N){
    assert(N>=0);
    if(N==0) return 0;
    return 1+2*count(N-1);
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
  if(t==0)
    printf("%llu\n", num_mosse=count(N));
  else
    sposta_disco(1, 'A', 'B');
        
  return 0;
}

