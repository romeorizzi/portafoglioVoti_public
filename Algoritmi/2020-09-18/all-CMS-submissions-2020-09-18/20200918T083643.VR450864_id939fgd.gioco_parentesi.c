/**
* user:  VR450864_id939fgd
* fname: ANDREA
* lname: RANCAN
* task:  gioco_parentesi
* score: 0.0
* date:  2020-09-18 08:36:43.818438
*/
#include <assert.h>
#include <stdio.h>
#include <string.h>


int main(void){
    int num_par;
    char *stringa;
    int i = 0;
    int length;
    int conta1 = 0;
    int conta2 = 0;
    int trovata = 0;
    int posizione;
    scanf("%i", &num_par);
    assert(num_par %2 == 0  && num_par >=2 && num_par <= 1000000);
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
                trovata = 1;
                conta2++;
                posizione = i;

            }
            else if(conta1 == 0 && trovata == 1)
                conta2++;
        }
    }
    //printf("%i\n", conta2);
    if(conta2 %2 ==1){
        printf("%i\n", 1);
        printf("%i%i", 0, posizione);
    }
    else
        printf("%i\n", 0);

}

//( ( () ()())

//  ( () ( () () )) ( ( ( ) ) ) parentesizzazione ben formata: il n° di partentesi chiuse non supera main
//  quello di parentesi aperte e alla fine i 2 numeri devono coincidere



/*(()) () ()
( ()())

1(  ( (()) ()) (()()) ( (())()) (()()) )
2( (()()()()) () (()) )  3( (()()) (()()()) (()()) (()) ()() )  4(()())  5(()()())*/
