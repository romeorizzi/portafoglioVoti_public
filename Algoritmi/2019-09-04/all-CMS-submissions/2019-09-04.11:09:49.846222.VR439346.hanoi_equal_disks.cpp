/**
* user:  VR439346
* fname: MASOTTO
* lname: GIOVANNI
* task:  Prob2_hanoi_equal_disks
* score: 80.0
* date:  2019-09-04 11:09:49.846222
*/
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <cassert>

using namespace std;

int t;
int N;
vector<int> disks;
vector<int> card;
unsigned long long int num_mosse(){
    long long int s_mossa =0;
    for (int i=1;i<=disks.size();i++){
        s_mossa = s_mossa+card[i-1]*pow(2,disks.size()-i);
    }
    return s_mossa;
}

void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

void sposta_torre(int N, char piolo_from, char piolo_to, char piolo_extra){
    //assert(N==0);
    if(N==0) return;
    //assert(N>=1);
    sposta_torre(N-1,piolo_from, piolo_extra,piolo_to);
    sposta_disco(N,piolo_from,piolo_to);
    sposta_torre(N-1,piolo_extra,piolo_to,piolo_from);
}

int main() {
  scanf("%i%i", &t, &N);
  int d;
  for(int i = 1; i <= N; i++) {
    scanf("%i", &d);
    if(disks.size()==0 || disks[disks.size()-1]!= d){
        disks.push_back(d);
        card.push_back(0);
    }
    card[disks.size()-1] = card[disks.size()-1]+1;
    //printf("%i ",card[disks.size()-1]);
  }
  if (t==0){
  printf("%llu",num_mosse());}
  else
    { sposta_torre(N,'A','B','C');
    }
  return 0;
}