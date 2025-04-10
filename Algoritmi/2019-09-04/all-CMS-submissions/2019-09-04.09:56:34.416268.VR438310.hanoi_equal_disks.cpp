/**
* user:  VR438310
* fname: ZAMPIERI
* lname: AMEDEO
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 09:56:34.416268
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

long long unsigned int mosse[MAXN+1] = {0};

typedef long long unsigned int llu;

int ind_disco = 0;

void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

int calcola_mosse(int index)
{
  //se l'ho già calcolato non lo ricalcolo di nuovo
  int dim_disco = d[index];

  if (mosse[dim_disco] != 0)
    return mosse[dim_disco];

  //se sono all'disco più piccolo allora sposto 1 solo disco
  if (index == N - 1)
  {
    mosse[dim_disco] = 1;
    return 1;
  }

  mosse[dim_disco] = 2 * calcola_mosse(index + 1) + 1;
  return mosse[dim_disco];


}


int main() {
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  }
  llu num_mosse = calcola_mosse(0);
  if(t==0)
    printf("%llu\n", num_mosse);
  else
    sposta_disco(1, 'A', 'B');
        
  return 0;
}

