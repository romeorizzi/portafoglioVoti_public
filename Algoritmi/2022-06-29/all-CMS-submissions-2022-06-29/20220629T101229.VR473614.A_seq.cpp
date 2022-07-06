/**
* user:  VR473614
* fname: LEONARDO
* lname: ZUANAZZI
* task:  A_seq
* score: 48.0
* date:  2022-06-29 10:12:29.088920
*/
#include <iostream>
#include <string>
using namespace std;
#define DIM 10000

int soluzioni[DIM] = {};
int soluzioni2[DIM] = {};
int seq[DIM] = {};

int g = 1;

void readSeq(int n);
void printSeq(int n);
int precedenti(int k, int n);
int precedenti2(int k);
int solver(int n);

int main(void){

    int n;

    cin>>g;
    cin>>n;

    //cout<<"\n";

    readSeq(n);
    //printSeq(n);

    //cout<<"\n";
    if (g == 1)
        cout<<solver(n);
    //cout<<"\n";

    return 0;
}

void readSeq(int n){
    for(int i=0; i<n; i++){
        cin>>seq[i];
        soluzioni[i] = 1;
        soluzioni2[i] = 1;
    }
}

void printSeq(int n){
    for(int i=0; i<n; i++){
        cout<<seq[i]<<" ";
    }
}

int solver(int n){
    for(int i=n-2; i>=0; i--){
        soluzioni[i] = precedenti(i,n) + 1;
    }

    // for(int i=0; i<n; i++){
    //      cout<<soluzioni[i]<<" ";
    // }

    for(int i=1; i<n; i++){
        soluzioni2[i] = precedenti2(i) + 1;
    }

    // cout<<"\n";
    // for(int i=0; i<n; i++){
    //      cout<<soluzioni2[i]<<" ";
    // }
    // cout<<"\n";

    for(int i=0; i<n; i++){
        soluzioni[i] = soluzioni[i] + soluzioni2[i] - 1;
    }

    // cout<<"\n";
    // for(int i=0; i<n; i++){
    //      cout<<soluzioni[i]<<" ";
    // }
    // cout<<"\n";

    int max = 0;
    for(int i=0; i<n; i++){
        if (max < soluzioni[i])
            max = soluzioni[i];
    }

    return max;
}

int precedenti(int k, int n){
    int max=0;
    for(int i=n; i>k; i--){
        if (seq[i]<seq[k] && max <= soluzioni[i]){
            max = soluzioni[i];
        }
    }
    return max;
}

int precedenti2(int k){
    int max=0;
    for(int i=0; i<k; i++){
        if (seq[i]<seq[k] && max <= soluzioni2[i]){
            max = soluzioni2[i];
        }
    }
    return max;
}

// 1 2 3 4 5 6 7 3 7 8 2 4 7 3 9 3 2 6 3 7
// 1 1 2 3 4 4 4 2 4 4 1 3 3 2 3 2 1 2 1 1 
// 1 2 2 3 4 5 5 2 5 5 2 3 5 2 5 2 2 5 2 5