/**
* user:  VR439232
* fname: PENZO
* lname: MICHELE
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 08:24:07.996539
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

llu num_mosse = 1;

void sposta_disco(int n, char piolo_from, char piolo_to, char piolo_aux) {

  if(n==1){
    printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
    return;
  }

  sposta_disco(n-1, piolo_from, piolo_aux, piolo_to);
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);

  sposta_disco(n-1, piolo_aux, piolo_to, piolo_from);
}

void calcola_mosse(int n, char piolo_from, char piolo_to, char piolo_aux)
{
  if(n==1){
    num_mosse += 1;
    return;
  }

  calcola_mosse(n-1, piolo_from, piolo_aux, piolo_to);

  calcola_mosse(n-1, piolo_aux, piolo_to, piolo_from);

}


int main() {
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  }

  if(t==0){
    calcola_mosse(N, 'A', 'C', 'B');
    printf("%llu\n", num_mosse);
  }
  
  if(t==1)
    sposta_disco(N, 'A', 'C', 'B');
        
  return 0;
}

