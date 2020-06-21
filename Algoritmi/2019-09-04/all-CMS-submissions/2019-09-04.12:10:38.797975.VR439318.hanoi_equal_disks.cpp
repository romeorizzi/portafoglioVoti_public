/**
* user:  VR439318
* fname: PAVAN
* lname: GIANLUCA
* task:  Prob2_hanoi_equal_disks
* score: 60.0
* date:  2019-09-04 12:10:38.797975
*/
/**
 * Un template per la tua soluzione di hanoi_equal_tot
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
int N;
vector<int> tot;
vector<int> pos;

typedef long long unsigned int llu;

unsigned long long int count(){
  long long unsigned int sum = 0;
  for(int i=1;i<=tot.size();i++){
    sum=sum+pos[i-1]*pow(2,tot.size()-i);
  }
    return sum;
}

void sposta_disco(int N, int from, int to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", N, from, to);
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
  scanf("%i%i", &mode, &N);
  int tmp;
  for(int i = 0; i < N; i++) {
    scanf("%i", &tmp);
    if(tot.size() == 0 || tot[tot.size()-1] != tmp){
      tot.push_back(tmp);
      pos.push_back(0);
    }
    pos[tot.size()-1] = pos[tot.size()-1]+1;
    }

  if(mode==0)
    printf("%llu", count());
  else
    sposta_torre(N, 'A', 'C', 'B');
  
  
  
  return 0;
}

