/**
* user:  VR431394
* fname: BONATO
* lname: JENNY
* task:  bin_heap_fill
* score: 24.0
* date:  2020-06-18 10:31:47.070802
*/
#include<stdlib.h>
#include<stdio.h>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cassert>

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
int e_bonta(){
    for(int i=0; i<N; i++)
        if(E[i] == 1)
            //violazione E-bontà
            if( A[i] < A[(i-1)/2])
                return 0;
    return 1;
}

int exist_ricolocamento(){
    int scambiati = 0;
    for(int i=0; i<N;i++){
        if(F[i] == 0){
            for(int j=0; j<N;j++){
                /* utilizzo la matrice visit per tenere traccia
                degli scambi già avvenuti. */
                if(F[j] == 0){
                    scambiati = 1;
                    scambio_A(i,j);
                    //NB: scambiare (i,j) o (j,i) è la stessa cosa
                    if(e_bonta() == 1)
                        return 1;

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
        printf("%d", e_bonta());
    }else{
        printf("%d", exist_ricolocamento());
    }

}
