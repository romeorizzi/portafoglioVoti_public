/**
* user:  VR474721
* fname: RICCARDO
* lname: BOLOGNA
* task:  esame_two_three_steps
* score: 25.0
* date:  2023-02-20 12:39:45.022526
*/
#include<iostream>
#include<string>
#include<fstream>


using namespace std;

ifstream fileIn("input.txt");
ofstream fileOut("output.txt");

int sogno[1000]={};
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
    
    fileIn>>k;
    
    for(int i=0;i<k;i++)
        fileIn>>sogno[i];

    /*for(int i=0;i<k;i++)
        cout<<sogno[i]<<" ";*/
    fileOut<<calc(0);
    
}