/**
* user:  VR439870
* fname: SACCHETTO
* lname: LINDA
* task:  poldo_sums
* score: 47.0
* date:  2020-06-18 13:04:11.375936
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
    int indice;
    poset* prec;
    poset(int p){
        peso = p;
    }
    poset(){}
};

int N;
long int pesi[MAXN];
int chain[MAXN];
poset lista[MAXN];
long int g[MAXN];
long int tmp=0;
int maxp = 0;


void stampa_ris(poset *nodo){
    if( nodo->prec == nullptr ){

    }else{
        stampa_ris(nodo->prec);
    }
    printf("%d ", nodo->indice);
}

int main(){

    int t;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%li", &pesi[i]);
        lista[i].peso = pesi[i];
        lista[i].indice = i;
        scanf("%li", &g[i]);
        
    }
    for(int i=0  ; i < N-1; i++){
      for(int j=i+1; j < N  ; j++){
            int tot =0;
            for(int k=i; k<j; k++)
                tot+=g[i];
            if(pesi[j]>=pesi[i]+tot && chain[i]>=chain[j]){
                chain[j] = chain[i]+1;
                lista[j].prec = &lista[i];
            }
      }
    }
     for(int i=0;i<N;i++){
        if(chain[i]> chain[maxp]){
            maxp = i;
        }
    }

    //stampo massimo
    printf("%d\n", chain[maxp]+1);

    //gli passo l'ultimo elemento della catena più lunga
    stampa_ris(&lista[maxp]);

    return 0;
}
