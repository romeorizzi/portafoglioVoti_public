/**
* user:  VR424616
* fname: CASTIGLIONI
* lname: ALESSANDRA
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 12:21:32.790204
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


static FILE *file;
static long long int N;
static long long int S;
static long long int lunghezza=0;

void stampa(long long int num);
void stampaacapo();
//void calcolaseq(long long int N, long long int panino[], long long int gym[]);
//bool verificaformula(long long int a, long long int seq[], long long int panino[], long long int gym[]);

/*void calcolaseq(long long int N, long long int panino[], long long int gym[]){
    long long int seq[N];

    seq[0]=0;
    seq[1]=1;
    for(int i = 0; i<N; i++){
        for(int j=1; j<N; j++){
            if(verificaformula(j, seq[], panino[], gym[])==true){
                seq[i]=i;
                seq[j]=j;
                i+=1;
            }
        }
    }  

    stampa(lunghezza);
    for (int i = 0; i<N-1;i++){
        if(i==0 || (i!=0 && seq[i]!=0)) {
            stampa(seq[i]);
        }
    }
}*/

/*bool verificaformula(long long int a, long long int seq[], long long int panino[], long long int gym[]){

    seq[0]=0;
    seq[1]=1;
    sum=gym[a-1];
    for(int i=1; i<a; i++){
        sum+=gym[i];
    }
    if(panino[seq[a]]>=panino[seq[a-1]]+ sum){
        return true;
    }
    else
    {
        return false;
    }
    
}*/

void stampa(long long int num){
    fprintf(file, "%lld ", num);
    //exit(0);
}

void stampaacapo(){
    fprintf(file, "\n");
}

int main(){

#ifdef EVAL
  file = fopen("input.txt", "r");
#else
  file = stdin;
#endif

  assert(fscanf(file, "%lld", &N)==1);
  long long int gym[N];
  long long int panini[N];
  long long int sum[N];


  assert(fscanf(file, "%lld %lld", &panini[0], &gym[0]) ==2);

  sum[0]=gym[0];
  for (int i = 1; i<N;i++){
        assert(fscanf(file, "%lld %lld", &panini[i], &gym[i]) ==2);
        sum[i]=sum[i-1]+gym[i];
  }
  fclose(file);

#ifdef EVAL
  file = fopen("output.txt", "w");
#else
  file = stdout;
#endif

  long long int seq[N]={};
  bool verificaformula;
  long long int temp=0;
  long long int Superseq[N]={};

  seq[0]=0;
  seq[1]=1;

  for(int i = 0; i<N-1; i++){
    
    S=0;

    for(int j=1; j<N; j++){
        if(panini[seq[j]]>=panini[seq[i]]+sum[i]){
            verificaformula==true;
        }
        else{
            verificaformula==false;
        }

        if(verificaformula){
            seq[i]=i;
            seq[j]=j;
            i++;
        }
        else{
            i++;
        }
    }

    for(int x=0; x<N; x++){
        if(x==0 && seq[x]==0){
            S++;
        }
        else if(seq[x]>0){
            S++;
        }
    }

    if(S>=temp){
        temp=S;
        for(int t=0; t<N; t++){
            Superseq[t]=seq[t];
        }
        lunghezza=S;
    }

  }  

  stampa(lunghezza);
  stampaacapo();
  for (int i = 0; i<lunghezza;i++){
    if(i==0 || (i!=0 && Superseq[i]!=0)) {
            stampa(Superseq[i]);
    }
  }

  //calcolaseq(N, panino[], gym[]);
  fclose(file);
  return 0;
}