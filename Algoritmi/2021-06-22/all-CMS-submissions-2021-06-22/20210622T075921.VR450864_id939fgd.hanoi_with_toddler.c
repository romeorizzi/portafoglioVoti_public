/**
* user:  VR450864_id939fgd
* fname: ANDREA
* lname: RANCAN
* task:  hanoi_with_toddler
* score: 10.0
* date:  2021-06-22 07:59:21.341516
*/
#include <stdio.h>

int main(void){
    int n, tipo;
    int i;
    scanf("%i %i", &tipo, &n);
    char conf_finale[n];
    scanf("%s", conf_finale);

    long long int numero_mosse = 1;
    if(tipo == 0){
        for(i = 0; i<n; i++){
            numero_mosse *=2;
        }
        printf("%lld\n", numero_mosse-1);
    }

}
