/**
* user:  VR450864_id939fgd
* fname: ANDREA
* lname: RANCAN
* task:  gioco_parentesi
* score: 5.0
* date:  2020-09-18 10:45:59.649295
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void){
    int num_par;
    char *stringa;
    stringa  = malloc(2000000);
    int i = 0, j=0, a=0, k=0, b=0, c=0, d, e, f;
    int length;
    int conta1 = 0;
    int conta2 = 0;
    int conta3 = 0;
    int trovato = 0;
    int posizione[1000000] = {};
    int posizione2;
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
            if(conta1 == 0){
                posizione[a] = i;
                a++;
            }
        }
    }
    //printf("%i\n", conta2);
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
        printf("%i\n", 0);

}

//( ( () ()())

//  ( () ( () () )) ( ( ( ) ) ) parentesizzazione ben formata: il n° di partentesi chiuse non supera main
//  quello di parentesi aperte e alla fine i 2 numeri devono coincidere



/*(()) () ()
( ()())

1 ( (()()()) ((())()) (()()) ((())()) (()()) )
2( (()()()()) () (()) )  3( (()()) (()()()) (()()) (()) ()() )  4(()())  5(()()())*/
