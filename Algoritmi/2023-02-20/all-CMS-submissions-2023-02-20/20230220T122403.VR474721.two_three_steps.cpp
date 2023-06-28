/**
* user:  VR474721
* fname: RICCARDO
* lname: BOLOGNA
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:24:03.751344
*/
#include<iostream>
#include<string>
using namespace std;

int sogno[1000];
int k;
int calc(int ind){
    if(ind>=k)
        return 0;
    else{
        int massimo = 0;
        massimo = max(sogno[ind]+calc(ind+2), sogno[ind]+calc(ind+3));
        return massimo;
    }
}

int main(){
    
    cin>>k;
    for(int i=0;i<k;i++)
        cin>>sogno[i];

    for(int i=0;i<k;i++)
        cout<<sogno[i]<<" ";

    cout<<"\n";
    cout<<calc(0);
}