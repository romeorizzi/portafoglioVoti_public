/**
* user:  VR431394
* fname: BONATO
* lname: JENNY
* task:  poldo_sums
* score: 59.0
* date:  2020-06-18 10:26:03.303920
*/
#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<cassert>
#include<vector>

using namespace std;

#define MAXN 10005

struct poset{
    long int peso;
    int index;
    poset* prec;
    poset(int p){
        peso = p;
    }
    poset(){}
};

int N;
long int p[MAXN];
int chain[MAXN];
poset panini[MAXN];
long int gym[MAXN];
long int tmp=0;
int maxp = 0;

/*stampa la sequenza con ricorsione in salita, gli passo ultimo nodo
della catena e risalgo (ricorsione) finché non sono arrivata al padre
della catena che avrà nullptr come prec a questo punto posso finalmente
stampare l'indice a partire dal padre della catena e poi, ritornando dalla
ricorsione, quello dei figli seguendo la catena
*/
void stampa_ris(poset *nodo){
    if( nodo->prec == nullptr ){

    }else{
        stampa_ris(nodo->prec);
    }
    printf("%d ", nodo->index);
}

int calcola_gym(int from, int to){
    int ris =0;
    for(int i=from; i<to; i++)
        ris+=gym[i];
    return ris;
}

int main(){

    //scansione input e inizializzazione array
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%li", &p[i]);
        panini[i].peso = p[i];
        panini[i].index = i;
        scanf("%li", &gym[i]);
    }

    //per ogni scelta di panino padre (i)
    for(int i=0; i<N; i++){
        //prendo ogni scelta di panino figlio (j) che soddisfa la formula
        for(int j=i+1; j<N; j++){
            if(p[j]>=p[i]+calcola_gym(i,j) && chain[i] >= chain[j]){
                /*se sono qui aggiungo panino figlio a sequenza questo vuol dire che:
                1 - panino figlio (j) ha la catena incrementata (tengo catena sui figli)
                2 - il padre di mio figlio (j) sono io (i)
                */
                chain[j] = chain[i]+1;
                panini[j].prec = &panini[i];
            }
        }

    }

    for(int i=0;i<N;i++){
        //prendo indice massimo della catena più lunga
        if(chain[i]> chain[maxp]){
            maxp = i;
        }
    }

    //stampo massimo
    printf("%d\n", chain[maxp]+1);

    //gli passo l'ultimo elemento della catena più lunga
    stampa_ris(&panini[maxp]);

    return 0;
}
