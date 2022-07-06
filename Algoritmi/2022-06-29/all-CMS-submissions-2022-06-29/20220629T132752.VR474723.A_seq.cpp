/**
* user:  VR474723
* fname: MARCELLO
* lname: DE VINCENZI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 13:27:52.548374
*/
#include <iostream>
#include <fstream>
using namespace std;

int max_sequence(int *);
int longest_sequence(int,int*,int);
int tell_sequence(int,int *,int,int);
const int MAX=100000;
int enum_insiemi(int *);
int mem[MAX][2];
int g,n;

int main(){
    cin >> g;
    cin >> n;
    for(int i=0;i<MAX;i++){
        mem[i][0]=0;
        mem[i][1]=0;
    }
    int *seq=new int[n];
    for(int i=0;i<n;i++)
        cin >> seq[i];
    int result;
    if(g==1)
        result=max_sequence(seq);
    else
        result=enum_insiemi(seq);
    cout << result;

}

int max_sequence(int *seq){
    int count=1;
    int found;
    for(int i=0;i<n;i++){
        found=longest_sequence(i,seq,0);
        count=max(count,longest_sequence(i,seq,0));
    }
    return count;
}

int longest_sequence(int start,int *seq,int op){
    int count=1;
    if(start==n-1)
        return count;
    for(int j=start+1;j<n;j++){
        if(seq[start] < seq[j] && op==0){
            if(mem[j][0]==0){
                mem[j][0]=longest_sequence(j,seq,0);
            }
            count=max(count,1+mem[j][0]);
        }
        else{
            if(seq[start] > seq[j]){
                if(mem[j][1]==0)
                    mem[j][1]=longest_sequence(j,seq,1);
                count=max(count,1+mem[j][1]);
        }
        }
    }
    return count;
}
int enum_insiemi(int *seq){
    int maximum=max_sequence(seq);
    int count=0;
    for(int i=0;i<n;i++)
        count+=tell_sequence(i,seq,maximum,0);
    return count;
}
int tell_sequence(int start,int *seq,int maxi,int op,int length){
    
}
