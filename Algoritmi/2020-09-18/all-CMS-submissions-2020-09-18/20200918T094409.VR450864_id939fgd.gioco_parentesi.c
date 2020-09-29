/**
* user:  VR450864_id939fgd
* fname: ANDREA
* lname: RANCAN
* task:  gioco_parentesi
* score: 5.0
* date:  2020-09-18 09:44:09.082637
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void){
    int num_par;
    char *stringa;
    stringa  = malloc(2000000);
    int i = 0, j=0;
    int length;
    int conta1 = 0;
    int conta2 = 0;
    int conta3 = 0;
    int trovata = 0;
    int posizione;
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
            if(conta1 == 0 && trovata == 0){
                trovata ++;
                conta2++;
                posizione = i;

            }
            else if(conta1 == 0 && trovata != 0){
                trovata ++;
                conta2++;
            }
        }
    }
    //printf("%i\n", conta2);
    conta1 = 0;
    if(conta2 %2 == 1){
        if(trovata>1){
            printf("%i\n", 1);
            for(i=1; i<posizione; i++){
                if(stringa[i] == '('){
                    conta1++;
                }
                else if(stringa[i] == ')'){
                    conta1--;
                    if(conta1 == 0){
                        posizione2 = i;
                        break;
                    }
                }
            }
            printf("%i %i\n", 1, posizione2);
        }
        else{
            printf("%i\n", 1);
            printf("%i %i\n", 0, length - 1);
        }

    }
    else
        printf("%i\n", 0);

}

//( ( () ()())

//  ( () ( () () )) ( ( ( ) ) ) parentesizzazione ben formata: il n° di partentesi chiuse non supera main
//  quello di parentesi aperte e alla fine i 2 numeri devono coincidere



/*(()) () ()
( ()())

1 ( (()()()) ((())()) (()()) ((())()) (()()) )
2( (()()()()) () (()) )  3( (()()) (()()()) (()()) (()) ()() )  4(()())  5(()()())*/
