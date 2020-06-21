/**
* user:  VR439232
* fname: PENZO
* lname: MICHELE
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 11:18:49.040294
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

typedef long long unsigned int llu;

llu num_mosse = 0;

void sposta(int n, int from, int to, int aux, void (*basicActionOnDisk) (int, char, char))
{
    if(n<=0)
        return;

    sposta(n-1, from, aux, to, basicActionOnDisk);
    (*basicActionOnDisk)(n, from, aux);
    sposta(n-1, aux, to, from, basicActionOnDisk);
}


void sposta_disco(int n, char from, char to)
{
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, from, to);
}

void mosse(int n, char from, char to){
    num_mosse++;
}

int main() {
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  }


  if(t==0){
    sposta(N, 'A', 'C', 'B', &mosse);
    printf("%llu\n", num_mosse);
  }
  else
    sposta(N, 'A', 'C', 'B', &sposta_disco);
        
  return 0;
}

