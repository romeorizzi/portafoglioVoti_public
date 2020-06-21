/**
* user:  VR439346
* fname: MASOTTO
* lname: GIOVANNI
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 10:14:01.971833
*/
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int t;
int N;
vector<int> disks;
vector<int> card;
unsigned long long int count(){
    long long int sum =0;
    for (int i=1;i<=disks.size();i++){
        sum = sum+card[i-1]*pow(2,disks.size()-i);
    }
    return sum;
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
  printf("%llu",count());}
  
 
  return 0;
}


if(t==0){
    sposta(N,'A','C','B', &increment_mosse);
    printf("%llu\n", num_mosse);
    }
  else
    sposta(N,'A','C','B',&sposta_disco);