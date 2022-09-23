/**
* user:  VR474723
* fname: MARCELLO
* lname: DE VINCENZI
* task:  esame_linear_diff_constraints
* score: 0.0
* date:  2022-09-20 10:14:57.220025
*/
#include <iostream>
#include <string>
#include <vector>
#include "./grader.cpp"
using namespace std;

bool check(int N,int M, vector <int> &A, vector <int>& B,vector<int>& C, vector<int>& altezze);

long max(long,long);


long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C){

vector <int> altezze(N);
for(size_t i = 0; i < N; i++) {
        altezze[i]=1;
    }

long result=0;
long somma=0;
int i=0;
while(altezze[0]<=H[0]){
    
    if(check(N,M,A,B,C,altezze)){
        somma=0;
        for(int i=0;i<N;i++)
            somma+=altezze[i];
    result=max(result,somma);
    }
    //Aumento le altezze
    altezze[N-1]+=1;

    //Controllo come sono messo
    for(int i=1;i<N;i++ ){
        if(altezze[i]>H[i]){
            altezze[i]=0;
            altezze[i-1]=altezze[i-1]+1;
        }
    }
}

return result;
}

bool check(int N,int M, vector <int> &A, vector <int>& B,vector<int>& C, vector<int>& altezze){
    for(int i=0;i<M;i++){
        if(altezze[B[i]]<=(altezze[A[i]] + C[i]));
        else
            return false;
    }
    return true;

}

long max(long a,long b){
    if(a>b)
        return a;
    else
        return b;
}