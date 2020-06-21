/**
* user:  VR439670
* fname: LUCCHESE
* lname: MARCO
* task:  Prob2_hanoi_equal_disks
* score: 40.0
* date:  2019-09-04 11:39:41.815345
*/
#include <cassert>
#include <cstdio>
#include <cmath>





typedef long long unsigned int llu;

unsigned long long int numero_mosse (int c, int arr[]){
    llu mosse=0;
    for(int i=1;i<=c;i++){
        mosse+=arr[i]*pow(2,c-i);
    }
    return mosse;
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
    for(int i = 1; i <= N; i++) {
        scanf("%d", &d[i]);
    }
    llu num_mosse = 1;
    int c=0;
    int flag=1;
    int cert=1;    

    for(int i =1; i<=N;i++){
        for(int j=i+1; j<=N;j++){
            if (d[i]!=d[j]){
                //pass
            }else{
                cert++;
                flag=0;            
            }
        }
        if(flag==0){
            arr[i]=cert;
        }
        else if(flag==1){
            c++;
            arr[i]=1;
        }
        
        //reset
        flag=1;
        cert=1;
        
    }
    //printf("%d",d[1]);
    if(t==0){
    //printf("%llu\n", count-2);
    printf("%llu\n", num_mosse=numero_mosse(c,arr));    
    }
    else
    hanoi(N, 'A','B', 'C');

    return 0;

}

