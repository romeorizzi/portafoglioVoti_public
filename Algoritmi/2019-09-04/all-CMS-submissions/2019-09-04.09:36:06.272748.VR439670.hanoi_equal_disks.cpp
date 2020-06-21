/**
* user:  VR439670
* fname: LUCCHESE
* lname: MARCO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 09:36:06.272748
*/
/**
 * Un template per la tua soluzione di hanoi_equal_disks
 * Romeo Rizzi, 2019-08-28
 *
 */

#include <cassert>
#include <cstdio>
#include <cmath>

const int DEBUG = 0;
//const int DEBUG = 1;
const int MAXN = 100000;

int t, N;
int d[MAXN+1];
int k[MAXN+1];

typedef long long unsigned int llu;

unsigned long long int count (int c, int k[]){
    llu sum=0;
    for(int i=1;i<=c;i++){
        sum=sum+k[i]*pow(2,c-i);
    }
    return sum;
}
void sposta_disco(int n, char piolo_from, char piolo_to) {
  printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}
void sposta_torre(int N, char piolo_from,char to, char piolo_extra){
    assert(N>=0);
    if(N==0) return;
    assert(N>=1);
    sposta_torre(N-1,piolo_from,piolo_extra,piolo_to);
    sposta_disco(N, piolo_from,piolo_to);
    sposta_torre(N-1, piolo_extra, piolo_to,piolo_from);
}

int main() {
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
  if(t==0)
    printf("%llu\n", num_mosse=count(c,k));
  else
    sposta_torre(N, 'A','C', 'B');
        
  return 0;
}

