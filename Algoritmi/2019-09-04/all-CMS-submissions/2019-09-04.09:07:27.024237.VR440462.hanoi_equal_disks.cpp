/**
* user:  VR440462
* fname: GOBBI
* lname: FRANCESCO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 09:07:27.024237
*/
/**
 * Un template per la tua soluzione di hanoi_equal_disks
 * Romeo Rizzi, 2019-08-28
 *
 */

#include <cassert>
#include <cmath>
#include <cstdio>

const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int t, N; //esercuzione e numero di dischi
int d[MAXN+1];
int k[MAXN+1];//per le occorrenze

typedef long long unsigned int llu;

unsigned long long int conta_mosse(int diversi, int k[]) {//fa (1 + 2^(n-1))
 
  llu somma = 0;
  for(int i = 1; i<=diversi; i++) {
    somma = somma + k[i] * pow(2,diversi-1);
  } 
  return somma;
}

void sposta_disco(int n, char piolo_from, char piolo_to) { //funzione di solo stampa
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

void sposta_torre(int n, char from, char to, char piolo_appoggio) {

  assert(n>=0) ;
  if(n==0) return; //sono alla fine
  if (n==1) sposta_disco(n,from,to);
  sposta_torre(n-1,from,piolo_appoggio, to);
  sposta_disco(n, from, to);
  sposta_torre(n-1, piolo_appoggio,to, from);
}

int main() {
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) { //prendo le dimensioni dei dischi
    scanf("%d", &d[i]);
  }

  //controllo i valori delle dimensioni se sono diversi o meno
  int diversi = 0;
  int check = 1;
  int occ = 1;

  for(int i=1; i<=N; i++) {
    for(int j=i+1; j<=N; j++) {
      if(d[i]==d[j]) {
        check = 0;
        occ++;
      }
    }
    if (check ==1) {
      diversi++;
      k[i]=occ;
    }

    occ=1;
    check=1;
  }

  llu num_mosse = 1;
  
  if(t==0)
    printf("%llu\n", conta_mosse(diversi, k));
  else
    sposta_torre(N, 'A','C','B');
    //sposta_disco(1,'A','B');
        
  return 0;
}

