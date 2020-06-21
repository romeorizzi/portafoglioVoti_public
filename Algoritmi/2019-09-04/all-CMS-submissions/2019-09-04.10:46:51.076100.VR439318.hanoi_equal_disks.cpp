/**
* user:  VR439318
* fname: PAVAN
* lname: GIANLUCA
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 10:46:51.076100
*/
/**
 * Un template per la tua soluzione di hanoi_equal_disks
 * Romeo Rizzi, 2019-08-28
 *
 */

#include <cassert>
#include <cstdio>
#include <cmath>

const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int t, N;
int d[MAXN+1];
int k[MAXN+1];

typedef long long unsigned int llu;

unsigned long long int count(int diversi, int k[]){
  llu sum = 0;
  for(int i=1;i<=diversi;i++){
    sum=sum+k[i]*pow(2,diversi-i);
  }
    return sum;
  }


void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

void sposta_torre(int N, char from, char to, char piolo_app){
  assert(N>=0);
  if(N==0) return;

  assert(N>=1);

  sposta_torre(N-1, from, piolo_app, to);
  sposta_disco(N, from, to);
  sposta_torre(N-1, piolo_app, to, from);
  
}


int main() {
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  }
  llu num_mosse = 1;
  int diversi= 0;
  int check= 1;
  int occ = 1;

  for(int i=1; i<=N; i++){
    for(int j=i+1; j<=N; j++){
      if(d[i]==d[j]){
        check=0;
        occ++;
      }
    }
    if(check==1){
      diversi++;
      k[i]=1;
    }
    if(check==0){
      k[i]=occ;
    }
    occ==1;
    check=1;
    
  }


  if(t==0)
    printf("%llu\n", num_mosse=count(diversi,k));
  else
    sposta_torre(N, 'A', 'C', 'B');
    // sposta_disco(1, 'A', 'B');
    
        
  return 0;
}

