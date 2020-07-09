/**
* user:  VR439870
* fname: SACCHETTO
* lname: LINDA
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 12:05:47.118265
*/
#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<cassert>
#include<utility>

using namespace std;

#define MAXN 10005

int N;
int p[MAXN];
int chain[MAXN];
long int tmp=0;
int maxp = 0;

int main(){
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");


    int t;
    fscanf(in,"%d \n", &N);
    for(int i=0; i<N; i++){
        fscanf(in,"%d\n", &p[i]);
    }

    for(int i=0; i<N; i++)
        chain[i] = 1;

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(p[i]>p[j] && chain[i]>=chain[j])
                chain[j] = chain[i]+1;
        }
    }

    for(int i=0;i<N;i++)
        maxp = max(maxp, chain[i]);

    fprintf(out,"%d\n", maxp);
    return 0;
}
