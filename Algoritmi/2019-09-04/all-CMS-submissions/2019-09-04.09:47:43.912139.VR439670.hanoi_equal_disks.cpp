/**
* user:  VR439670
* fname: LUCCHESE
* lname: MARCO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 09:47:43.912139
*/
#include <cassert>
#include <cstdio>
#include <cmath>





typedef long long unsigned int llu;
llu count=0;
using namespace std;
const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int t, N;
int k[MAXN+1];
int d[MAXN+1];
void hanoi(int n, char piolo_from, char piolo_to, char piolo_temp){
    count+=1;
    if (n==1){
    printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
    //printf<<"sposta il disco "<<n<<" dal piolo "<<from_rod<<" al piolo"<<to_rod;
    //muovo un disco da rod from rod a to rod
    return;
    }
hanoi(n-1, piolo_from,piolo_temp,piolo_to);
//muovi disco n da fromrod a torod
//printf<<"sposta il disco "<<n<<" dal piolo "<<from_rod<<" al piolo"<<to_rod;
printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
hanoi(n-1,piolo_temp, piolo_to,piolo_from);
}
unsigned long long int count (int c, int k[]){
    llu sum=0;
    for(int i=1;i<=c;i++){
        sum=sum+k[i]*pow(2,c-i);
    }
    return sum;
}
int main(){

//printf("numero mosse %d",count);
//return 0;
 scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  }
llu num_mosse = 1;
int c=0,check=1,occ=1;
    for(int i =1; i<=N;i++){
        for(int j=i+1; j<=N;j++){
            if (d[i]==d[j]){
                check=0;
                occ++;
            }
        }
            if(check==1){
                c++;
                k[i]=1;
            }
            if(check==0){
                k[i]=occ;
            }
            occ=1;
            check=1;
    }
//printf("%d",d[1]);
  if(t==0){
    //printf("%llu\n", count-2);
     printf("%llu\n", num_mosse=count(c,k));    
    }
  else
    hanoi(N, 'A','B', 'C');
        
  return 0;

}

