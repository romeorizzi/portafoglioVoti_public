/**
* user:  VR439370
* fname: FERRO
* lname: GIACOMO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 10:52:02.571910
*/
#include<stdio.h>


void comando1(int altezze[], int numNani, int pos1, int pos2 );
void comando2(int altezze[], int numNani, int inf, int sup);


int main(){
   
    
    int numNani=0;
    int numRichieste=0;
    
    puts("numero nani:");
    scanf("%d",&numNani);
    puts("num richieste:");
    scanf("%d", &numRichieste);

     int altezze[numNani];
     int richieste[3*numRichieste];

     for(int i=0; i<numNani; i++){
        scanf("%d",&altezze[i]);
     }

     puts("nani sono:");
    for(int i=0; i< numNani; i++){
        printf("%d ", altezze[i]);
    }
    puts("");

     for(int j=0; j<(3*numRichieste); j++){

        scanf("%d", &richieste[j]);
    }
    puts("le richieste sono:");
    for(int i=0; i< (3*numRichieste); i++){
        printf("%d ", richieste[i]);
    }
    puts("");
    


    //processo le richieste
    int cont=0;
    while(cont < (3*numRichieste)-2){

        if(richieste[cont]==1){
            comando1(altezze, numNani, richieste[cont+1]-1, richieste[cont+2]-1);
        }
        if(richieste[cont]==2){
            comando2(altezze, numNani, richieste[cont+1], richieste[cont+2]);
        }


        /*puts("nani sono:");
        for(int i=0; i< numNani; i++){
            printf("%d ", altezze[i]);
        }
        puts("");*/
        cont+=3;
    }


}//fine main


void comando1(int altezze[], int numNani, int pos1, int pos2 ){

    int tmp=altezze[pos2];
    
    altezze[pos2]=altezze[pos1];
    
    altezze[pos1]=tmp;

    /*puts("comando1");
    for(int i=0; i< numNani; i++){
            printf("%d ", altezze[i]);
        }
        puts("");*/

    return;

}


void comando2(int altezze[], int numNani, int inf, int sup){

    int indexMin=0;
    int indexMax=numNani-1;

    int check=0;
    
    for(int i=0; i< numNani; i++){
        if(altezze[i]==inf){
            indexMin=i;
        }

        if(altezze[i]==sup){
            indexMax=i;
        }
    }
    
    int min=indexMin;
    int max=indexMax;
    if(indexMax < indexMin){
        min=indexMax;
        max=indexMin;
    }

    for(int i=min; i<=max; i++){
        if(altezze[i]<inf || altezze[i]>sup){
            check=1;
            break;
        }
    }

    if(check){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
    return;

}


