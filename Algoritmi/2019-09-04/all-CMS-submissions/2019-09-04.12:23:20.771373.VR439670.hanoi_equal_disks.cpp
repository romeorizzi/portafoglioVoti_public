/**
* user:  VR439670
* fname: LUCCHESE
* lname: MARCO
* task:  Prob2_hanoi_equal_disks
* score: 60.0
* date:  2019-09-04 12:23:20.771373
*/
#include <cassert>
#include <cstdio>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <stdio.h>


std::vector<int> disks;
std::vector<int> card;
std::vector<int> partSum;

typedef long long unsigned int llu;

unsigned long long int numero_mosse (){
    llu mosse=0;
    for(int i=1;i<=disks.size();i++){
        mosse+=card[i-1]*pow(2,disks.size()-i);
    }
    return mosse;
}
void sposta_disco(int N, int from, int to){
printf("sposto il disco %d dal piolo %c al piolo %c\n",N,from,to);
}
void sposta_torre(int N, int piolo_from, int piolo_to, int piolo_temp){
assert(N>=0);
if(N==0) return;
assert(N>=1);
sposta_torre(N-1, piolo_from,piolo_temp, piolo_to);
sposta_disco(N,piolo_from,piolo_to);
sposta_torre(N-1, piolo_temp,piolo_to,piolo_from);
}

llu counter=0;
using namespace std;
const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int t, N;
int arr[MAXN+1];
int d[MAXN+1];
void hanoi(int n, char piolo_from, char piolo_to, char piolo_temp){
    counter+=1;
    if (n==1){
    printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
    //printf<<"sposta il disco "<<n<<" dal piolo "<<from<<" al piolo"<<to;
    //muovo un disco da  from  a to 
    return;
    }
hanoi(n-1, piolo_from,piolo_temp,piolo_to);
//muovi disco n da from a to
//printf<<"sposta il disco "<<n<<" dal piolo "<<from<<" al piolo"<<to;
printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
hanoi(n-1,piolo_temp, piolo_to,piolo_from);
}

int main(){

    //printf("numero mosse %d",count);
    //return 0;
    scanf("%d%d", &t, &N);
    int tmp;
    for(int i = 1; i <= N; i++) {
        //scanf("%d", &d[i]);
        scanf("%d", &tmp);
        if(disks.size()==0|| disks[disks.size()-1]!=tmp){
            disks.push_back(tmp);
            card.push_back(0);
        }
        card[disks.size()-1]=card[disks.size()-1]+1;
    }
    if(t==0)
printf("%llu",numero_mosse());
else
sposta_torre(N,'A','B','C');
 

    return 0;

}

