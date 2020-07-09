/**
* user:  VR431394
* fname: BONATO
* lname: JENNY
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 12:40:32.151587
*/
#include<stdlib.h>
#include<stdio.h>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cassert>
#include<algorithm>

#define MAXN 1000005
//#define DEBUG 1

int N, task;
int A[MAXN];
int E[MAXN];
int F[MAXN];

using namespace std;

//scambio valori in A
void scambio_A(int i, int j){
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

//risponde a t=1 (alla peggio lineare)
int e_bonta(int *vett){
    for(int i=0; i<N; i++)
        if(E[i] == 1)
            //violazione E-bontà
            if( vett[i] < vett[(i-1)/2])
                return 0;
    return 1;
}

/*tentativo di soluzione brute-force ma sbagliata!
scambia solo ed esclusivamente due elementi ma è una permutazione
valida di A anche quella che ha n scambi ma in questo caso non viene
considerata*/
int exist_ricollocamento(){
    int scambiati = 0;
    for(int i=0; i<N;i++){
        //check sui fissati
        if(F[i] == 0){
            for(int j=0; j<N;j++){
                if(F[j] == 0){
                    /*questa soluzione è così approssimativa
                    che non considera nemmeno che la coppia (i,j) è
                    uguale alla coppia (j,i)
                    */
                    scambiati = 1;
                    scambio_A(i,j);
                    //check di bontà
                    if(e_bonta(A) == 1)
                        return 1;

                    //se li ho scambiati li rimetto a posto
                    if(scambiati == 1){
                        scambiati = 0;
                        scambio_A(j, i);
                    }
                }
            }
        }
    }
    return 0;
}


/*
IDEA di tutte le permutazioni prendo la più vantaggiosa ovvero quella
che ha i tutti i numeri ordinati dal più piccolo al più grande tranne quelli
fissati. Se questa non è ammessa allora nessun'altra lo è.
*/
int exist_ricollocamento2(int *aux){
    int index=0;

    //creo un vettore con i soli valori non fissati
    for(int i=0; i<N; i++)
        if(F[i] == 0)
            aux[index++] = A[i];
    //li ordino
    sort(&aux[0], &aux[index]);

    index = 0;
    int newv[MAXN];
    /*li inserisco ordinati in un vettore nuovo che ha agli appositi
    valori fissati nei posti già fissati*/
    for(int i=0; i<N;i++)
        if(F[i] == 1){
            newv[i] = A[i];
        }else{
            newv[i] = aux[index];
            index++;
        }

    //check di validità
    if(e_bonta(newv) == 1)
        return 1;
    return 0;
}


int main(){
    #ifdef DEBUG
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
    #endif

    scanf("%d%d",&N, &task);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);

    for(int i=0; i<N; i++)
        scanf("%d", &E[i]);

    for(int i=0; i<N; i++)
        scanf("%d", &F[i]);

    if( task == 1){
        printf("%d", e_bonta(A));
    }else{
        int aux[MAXN];
        printf("%d", exist_ricollocamento2(aux));
    }
}
