/**
* user:  VR439318
* fname: PAVAN
* lname: GIANLUCA
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 11:44:47.930079
*/
/**
 * Un template per la tua soluzione di hanoi_equal_disks
 * Romeo Rizzi, 2019-08-28
 *
 */

#include <cassert>
#include <cstdio>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int mode;
vector<int> disks;
vector<int> card;
vector<int> partSum;

int t, N;
int d[MAXN+1];
int k[MAXN+1];

typedef long long unsigned int llu;

unsigned long long int count(){
  llu sum = 0;
  for(int i=1;i<=disks.size();i++){
    sum=sum+card[i-1]*pow(2,disks.size()-i);
  }
    return sum;
}

void sposta_disco(int n, int from, int to) {
  printf("sposta il disco %d dal piolo %d al piolo %d\n", n, from, to);
}

void sposta_torre(int N, int from, int to, int piolo_app){
  assert(N>=0);
  if(N==0) return;

  assert(N>=1);

  sposta_torre(N-1, from, piolo_app, to);
  sposta_disco(N, from, to);
  sposta_torre(N-1, piolo_app, to, from);
  
}


int main() {
  scanf("%d%d", &t, &N);
  int tmp;
  for(int i = 0; i <= N; i++) {
    scanf("%i", &tmp);
    if(disks.size() == 0 || disks[disks.size()-1] != tmp){
      disks.push_back(tmp);
      card.push_back(0);
    }
    card[disks.size()-1] = card[disks.size()-1]+1;
    }

  if(mode==0)
    printf("%llu", count());
  else
    sposta_torre(N, 'A', 'C', 'B');
  
  
  
  return 0;
}

