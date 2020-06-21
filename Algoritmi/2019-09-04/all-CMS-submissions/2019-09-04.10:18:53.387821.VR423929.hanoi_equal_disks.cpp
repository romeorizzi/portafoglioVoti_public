/**
* user:  VR423929
* fname: BRAGAGLIO
* lname: MORENO
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 10:18:53.387821
*/
#include <cassert>
#include <cstdio>

const int DEBUG =0;
const int MAXN = 100000;
int arr[MAXN];
int t,N;
int d[MAXN+1];

typedef long long unsigned int llu;
llu num_mosse =0;

void sposta(int n, int piolo_from, int piolo_to, int piolo_not_used, void(*basicActionOnDisk)(int,char,char)){
    if(n<=0) return;

    sposta(n-1, piolo_from, piolo_not_used, piolo_to, basicActionOnDisk);
    (*basicActionOnDisk)(n,piolo_from,piolo_not_used);
    sposta(n-1, piolo_not_used,piolo_to,piolo_from,basicActionOnDisk);
}

void increment_mosse(int n, char piolo_from, char piolo_to){
    num_mosse++;
}

void sposta_disco(int n, char piolo_from, char piolo_to){
    printf("sposta il disco %d dal piolo %c al piolo %c\n", n, piolo_from, piolo_to);
}


int main(){
    scanf("%d%d", &t, &N);
        for(int i=1; i<=N; i++){
                scanf("%d", &d[i]);
        }
        if(t==0){
            sposta(N,'A','C','B', &increment_mosse);
            printf("%llu\n", num_mosse);
        }
        else
            sposta(N,'A','C','B', &sposta_disco);
        
    return 0;
}