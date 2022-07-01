/**
* user:  VR474723
* fname: MARCELLO
* lname: DE VINCENZI
* task:  A_seq
* score: 48.0
* date:  2022-06-29 10:59:16.596444
*/
#include <iostream>
#include <fstream>
using namespace std;

int max_sequence(int *);
int longest_sequence(int,int*,int);
const int MAX=99999;
int num_insiemi(int *);
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
        result=num_insiemi(seq);
    cout << result;

}

int max_sequence(int *seq){
    int count=1;
    int num_insiemi;
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
int num_insiemi(int *seq){
    int num=0;
    int maximum=max_sequence(seq);
    for(int i=0;i<n;i++)
        if(longest_sequence(i,seq,0)==maximum)
        num++;
    return num;
}
