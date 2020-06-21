/**
* user:  VR440462
* fname: GOBBI
* lname: FRANCESCO
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 10:16:55.711974
*/
/**
 * Un template per la tua soluzione di hanoi_equal_disks
 * Romeo Rizzi, 2019-08-28
 *
 */

#include <iostream>
#include <cassert>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;
vector<int> disks;
vector<int> card;

int t, N; //esercuzione e numero diversi, k
int d[MAXN+1];
int k[MAXN+1];//per le occorrenzediversi, k

typedef long long unsigned int llu;

unsigned long long int conta_mosse() {//conta le mosse
 
  long long int  somma = 0;
  for(int i = 1; i<=disks.size(); i++) {
    somma = somma +card[i-1] * pow(2,disks.size()-1);
  } 
  return somma;
}

void sposta_disco(int n, char piolo_from, char piolo_to) { //funzione di solo stampa
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

void sposta_torre(int n, char from, char to, char piolo_appoggio) {

  assert(n>=0) ;
  if(n==0) return; //sono alla fine

  assert(n>=1);
  
  sposta_torre(n-1,from,piolo_appoggio, to);
  sposta_disco(n, from, to);
  sposta_torre(n-1, piolo_appoggio,to, from);
}

int main() {
  scanf("%d%d", &t, &N);
  int tmp;
  for(int i = 1; i <= N; i++) { //prendo le dimensioni dei dischi
    scanf("%d", &d[i]);
  

    if(disks.size()==0 || disks[disks.size()-1] != d[i]) {
      disks.push_back(tmp);
      card.push_back(0);
    }
    card[disks.size()-1] = card[disks.size()-1]+1;
  }
  llu num_mosse = 1;

  //controllo i valori delle dimensioni se sono diversi o meno
  
  
  if(t==0)
    printf("%llu\n", conta_mosse());
  else
    sposta_torre(N, 'A','B','C');
    //sposta_disco(1,'A','B');
        
  return 0;
}