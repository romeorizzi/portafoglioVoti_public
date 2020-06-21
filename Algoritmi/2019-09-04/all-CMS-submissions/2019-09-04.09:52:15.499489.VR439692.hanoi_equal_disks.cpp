/**
* user:  VR439692
* fname: ASTOLFI
* lname: RICCARDO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 09:52:15.499489
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
    return 2^n-1;
}

void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

void sposta_torre(int N,char from,char to,char aux){
    assert(N>=0);
    if(N==0) return;

    assert(N>=1);
    sposta_torre(N-1,from,aux,to);
    sposta_disco(N,from,to);
    sposta_torre(N-1,aux,to,from);
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
    sposta_torre(N,'A','B','C');
    //sposta_disco(1, 'A', 'B');
        
  return 0;
}

