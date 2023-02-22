/**
* user:  VR474721
* fname: RICCARDO
* lname: BOLOGNA
* task:  esame_two_three_steps
* score: 50.0
* date:  2023-02-20 12:45:11.709042
*/
#include<iostream>
#include<string>
#include<fstream>


using namespace std;

ifstream fileIn("input.txt");
ofstream fileOut("output.txt");

int sogno[1000]={};
int mem[1000] = {};
int k;
int calc(int ind){
    if(ind>=k)
        return 0;
    else{
        int massimo = 0;
        if(mem[ind+2]==-1)
            mem[ind+2] = calc(ind+2);
        if(mem[ind+3]==-1)
            mem[ind+3] = calc(ind+3);

        massimo = max(sogno[ind]+mem[ind+2], sogno[ind]+mem[ind+3]);
        return massimo;
    }
}

int main(){
    
    fileIn>>k;
    
    for(int i=0;i<k;i++){
        fileIn>>sogno[i];
        mem[i]=-1;
    }

    /*for(int i=0;i<k;i++)
        cout<<sogno[i]<<" ";*/
    fileOut<<calc(0);
    
}