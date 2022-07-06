/**
* user:  VR474723
* fname: MARCELLO
* lname: DE VINCENZI
* task:  A_seq
* score: 13.0
* date:  2022-06-29 10:32:36.066447
*/
#include <iostream>
#include <fstream>
using namespace std;

int max_sequence(int *);
int num_insiemi(int *);
int longest_sequence(int,int*,int);
int g,n;

int main(){
    cin >> g;
    cin >> n;
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
    for(int i=0;i<n;i++){
        count=max(count,longest_sequence(i,seq,0));
    }
    return count;
}

int num_insiemi(int *seq){
    int res;
    res=0;
    return res%1000000007;
}

int longest_sequence(int start,int *seq,int op){
    int count=1;
    if(start==n-1)
        return count;
    for(int j=start+1;j<n;j++){
        if(seq[start] < seq[j] && op==0)
            count=max(count,1+longest_sequence(j,seq,0));
        else{
            if(seq[start] > seq[j])
                count=max(count,1+longest_sequence(j,seq,1));
        }
    }
    return count;
}
