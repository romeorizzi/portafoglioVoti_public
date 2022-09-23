/**
* user:  VR474723
* fname: MARCELLO
* lname: DE VINCENZI
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 09:42:57.978241
*/
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

int g,n,k;
int max_seq(int*,int,int);
int find_max_seq(int *);
int max_sol_ottime(int *);
const int MAXMEM=100;
int mem[MAXMEM][MAXMEM];

int main(){
    cin >> g;
    cin >> n;
    cin >> k;
    int *seq=new int[n];
    int temp;
    for(int i=0;i<n;i++){
        cin >> temp;
        seq[i]=temp;
    }
    if(g==1)
        cout << max_seq(seq,0,k);
    if(g==2)
        cout << max_sol_ottime(seq);

    for(int i=0;i<MAXMEM;i++)
        for(int j=0;j<MAXMEM;j++)
            mem[i][j]=0;


}
int max_seq(int *seq,int i,int k){
    int max_len=1;
    int len;
    for(int j=i;j<n;j++){
        len=1;
        for(int w=j+1;w<n;w++){
            if(seq[j]<seq[w]){
                if(mem[w][k]!=0)
                    max_len=max(max_len,1+mem[w][k]);
                else{
                    mem[w][k]=max_seq(seq,w,k);
                    max_len=max(max_len,1+mem[w][k]);
                }
            }
            else{
                if(k>0){
                    if(mem[w][k-1]!=0)
                        max_len=max(max_len,1+mem[w][k-1]);
                    else{
                        mem[w][k-1]=max_seq(seq,w,k-1);
                        max_len=max(max_len,1+mem[w][k-1]);
                    }
            }}
        }
    }
    return max_len;
}

int max_sol_ottime(int *seq){
    return 0;
}
