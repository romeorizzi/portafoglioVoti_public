/**
* user:  VR439692
* fname: ASTOLFI
* lname: RICCARDO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 10:07:32.775143
*/
#include <iostream>
#include <stdio.h>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <vector>
#include <math.h>

using namespace std;

int mode;
int N;
vector<int>disks;
vector<int>card;

unsigned long long int count(){
    long long int sum=0;
    for(int i=1;i<=disks.size();i++){
        sum = sum+card[i-1]*pow(2,disks.size()-i);
    }
    return sum;
}

int main(){
    scanf("%i %i",&mode,&N);
    int tmp;
    for(int i=0;i<N;i++){
        scanf("%i",&tmp);
        if(disks.size()==0 || disks[disks.size()-1]!=tmp){
            disks.push_back(tmp);
            card.push_back(0);
        }
        card[disks.size()-1] = card[disks.size()-1] +1;
        printf("%i",card[disks.size()-1]);
    }
    printf("%i",count());
    return 0;
} 
