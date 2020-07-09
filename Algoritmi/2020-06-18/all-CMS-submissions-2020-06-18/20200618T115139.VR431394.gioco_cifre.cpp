/**
* user:  VR431394
* fname: BONATO
* lname: JENNY
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 11:51:39.562863
*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    int num, flag=1;
    scanf("%d", &num);


    /*
    ( -M-> mossa di martina, -A-> mossa avversaria)
    IDEA DI BASE:
    23 -M-> 20 -A-> 18 -M-> 10 -A-> 9 -M-> 0
    20 -M-> 18 -A-> 10 -M-> 9 -A-> 0

    Gli stati sicuramente fallimentari sono i multipli di 10,
    la miglior mossa è quella che mi porta alla vittoria ovvero quella di
    abbassare il numero della sua cifra più piccola in quanto consegna
    al mio avversario un multiplo di 10 e quindi pone il mio avversario in
    uno stato di fallimento assicurato
    */


    if( num % 10 == 0){
        flag = 0;
        printf("%d ", flag);
    }else{
        printf("%d %d", flag, num%10);
    }

    return 0;
}
