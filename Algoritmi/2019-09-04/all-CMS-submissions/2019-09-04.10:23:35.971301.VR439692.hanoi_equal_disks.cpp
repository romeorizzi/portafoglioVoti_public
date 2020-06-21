/**
* user:  VR439692
* fname: ASTOLFI
* lname: RICCARDO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 10:23:35.971301
*/
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <math.h>
#include <cassert>

using namespace std;

int mode;
int N;
vector<int> disks;
vector<int> card;
vector<int> partsum;

unsigned long long int count(){
    long long int sum=0;
    for(int i=1;i<=disks.size();i++){
        sum = sum+card[i-1]*pow(2,disks.size()-i);
    }
    return sum;
}

void sposta_disco(int n, int piolo_from, int piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}

void sposta_torre(int N,int from,int to,int aux){
    assert(N>=0);
    if(N==0) return;

    assert(N>=1);
    sposta_torre(N-1,from,aux,to);
    sposta_disco(N,from,to);
    sposta_torre(N-1,aux,to,from);
}


int main(){
    scanf("%i%i",&mode,&N);
    int tmp;
    for(int i=0;i<N;i++){
        scanf("%i",&tmp);
        if(disks.size()==0 || disks[disks.size()-1]!=tmp){
            disks.push_back(tmp);
            card.push_back(0);
        }
        card[disks.size()-1] = card[disks.size()-1] +1;
        //printf("%i",card[disks.size()-1]);
    }
    if(mode ==0) print("%i",count());
    else sposta_torre(N,'A','B','C'):
    return 0;
} 
