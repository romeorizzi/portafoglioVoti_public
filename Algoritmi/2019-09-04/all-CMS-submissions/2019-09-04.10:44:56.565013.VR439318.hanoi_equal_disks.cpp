/**
* user:  VR439318
* fname: PAVAN
* lname: GIANLUCA
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 10:44:56.565013
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
llu num_mosse = 0;

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

void sposta_torre(int n, char from, char to, char piolo_not, void (*basicActionOnDisk)(int,char,char)){
  if(n<=0) return;

  sposta_torre(n-1, from, piolo_not, to, basicActionOnDisk);
  (*basicActionOnDisk)(n,from,piolo_not);
  sposta_torre(N-1, piolo_not, to, from, basicActionOnDisk);
  
}

void increment_mosse(int n, char piolo_from, char piolo_to){
    num_mosse++;
}


int main() {
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  }

  if(t==0){
      sposta_torre(N, 'A', 'C', 'B', &increment_mosse);
      printf("%llu\n", num_mosse);
  }else
      sposta_torre(N, 'A', 'C', 'B', &sposta_disco);
    // sposta_disco(1, 'A', 'B');
    
        
  return 0;
}

