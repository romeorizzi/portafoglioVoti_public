/**
* user:  VR474723
* fname: MARCELLO
* lname: DE VINCENZI
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 09:15:30.381172
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
    for(int i=0;i<n;i++)
        cout << seq[i] << "\t";
    cout << "\n";
    if(g==1)
        cout << max_seq(seq,0,k);
    if(g==2)
        cout << max_sol_ottime(seq);

}
int max_seq(int *seq,int i,int k){
    int max_len=1;
    int len;
    for(int j=i;j<n;j++){
        len=1;
        for(int w=j+1;w<n;w++){
            if(seq[j]<seq[w]){
                max_len=max(max_len,1+max_seq(seq,w,k));
            }
            else{
                if(k>0)
                    max_len=max(max_len,1+max_seq(seq,w,k-1));
            }
        }
    }
    return max_len;
}

int max_sol_ottime(int *seq){
    return 0;
}
