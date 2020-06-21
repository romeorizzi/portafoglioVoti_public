/**
* user:  VR439670
* fname: LUCCHESE
* lname: MARCO
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 09:16:22.944779
*/
#include <cassert>
#include <cstdio>





typedef long long unsigned int llu;
llu count=0;
using namespace std;
const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int t, N;
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
int main(){
int n=4;
//hanoi(n, 'A','B','C');
//printf("numero mosse %d",count);
//return 0;
 scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &d[i]);
  }
//printf("%d",d[1]);
  if(t==0)
    printf("%llu\n", count-2);
  else
    hanoi(N, 'A','B', 'C');
        
  return 0;

}

