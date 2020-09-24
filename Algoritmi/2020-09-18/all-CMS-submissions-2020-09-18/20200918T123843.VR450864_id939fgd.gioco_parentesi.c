/**
* user:  VR450864_id939fgd
* fname: ANDREA
* lname: RANCAN
* task:  gioco_parentesi
* score: 1.0
* date:  2020-09-18 12:38:43.725480
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void){
    int num_par;
    char *stringa;
    stringa  = malloc(2000000);
    int i = 0, j=0, a=0, k=0, d;
    int length;
    int conta1 = 0;
    int conta2 = 0;
    int conta3 = 0;
    int max = 0;
    int trovato = 0;
    int posizione[1000000] = {};
    int posizione2;
    int pos;
    scanf("%i", &num_par);
    scanf("%s", stringa);
    //printf("%i\n", num_par);
    //printf("%s\n", stringa);
    length = strlen(stringa);
    for(i=0; i<=length; i++){
        if(stringa[i] == '(') {
            conta1++;
        }
        else if(stringa[i] == ')') {
            conta1--;
            conta2++;
            if(conta1 ==0){
                posizione[a] = i;
                a++;
            }
        }
    }

    int array[conta2];
    int posi[conta2];
    for(i=0; i<=length; i++){
        if(stringa[i] == '('){
            for(j=0; j<=i; j++){
                array[j]++;
                posi[j] = i;
            }
        }
        if(stringa[i] == ')'){
            for(j=0; j<=i; j++){
                array[j]--;
                if(array[j] == 0)
                    posi[j] = (i - posi[j] + 1)/2;
            }
        }
    }
    for(i=0; i<=conta2; i++){
        if(a%2 ==0){
            if (posi[j]%2 == 1 && posi[j]%2 > max){
                max = posi[j];
                d = j;
            }
            for(int a = 0; a<length && k<d; a++){
                if(stringa[i] == '(')
                    a++;
            }
            pos = a;
        }
    }

    if(a == 1){
        printf("%i\n", 1);
        printf("%i %i\n", 0, length - 1);
    }
    else if(a % 2 == 1 && a>1){
        printf("%i\n", 1);
        if(conta2%2 ==1)
            printf("%i %i\n", 0, posizione[0]);
        else
            printf("%i %i\n", pos, (pos +2*max -1));
    }
    else if(a%2 == 0){
        if(conta2 %2 ==0)
            printf("%i\n", 0);
        else{
            printf("%i\n", 1);
            printf("%i %i\n", pos, (pos +2*max -1));
        }

    }

    /*//printf("%i\n", conta2);
    conta1 = 0;
    if(a %2 == 1){
        if(a>1){
            printf("%i\n", 1);
            for(k = 0; k<a; k++){
                c = 0;
                d = 0;
                e = b+1;
                for(i=b+1; i<posizione[k]; i++){
                    if(stringa[i] == '('){
                        conta1++;
                    }
                    else if(stringa[i] == ')'){
                        conta1--;
                        if(conta1 == 0){
                            b = posizione[k] + 1;
                            c++;
                            if(d == 0)
                                f = i;
                            d++;
                        }
                    }

                }
                if(c%2 ==1 && c > 1){
                    printf("%i %i\n", e, f);
                    trovato = 1;
                    break;
                }

            }
            if(trovato == 0)
                printf("%i %i\n", 0, posizione[0]);

        }
        else if(a == 1 || trovato == 0){
            printf("%i\n", 1);
            printf("%i %i\n", 0, length - 1);
        }

    }
    if(a%2 != 1)
        printf("%i\n", 0);*/

}

//( ( () ()())

//  ( () ( () () )) ( ( ( ) ) ) parentesizzazione ben formata: il n° di partentesi chiuse non supera main
//  quello di parentesi aperte e alla fine i 2 numeri devono coincidere



/*(()) () ()
( ()())

1 ( (()()()) ((())()) (()()) ((())()) (()()) )
2( (()()()()) () (()) )  3( (()()) (()()()) (()()) (()) ()() )  4(()())  5(()()())*/
