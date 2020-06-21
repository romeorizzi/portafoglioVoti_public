/**
* user:  VR439692
* fname: ASTOLFI
* lname: RICCARDO
* task:  is_shuffle_of
* score: 0.0
* date:  2019-06-25 11:44:21.908921
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream input("input.txt");
ofstream output("output.txt");

int M[1000];
int N[1000];
int MN[2000];
int S[2000];

int main(){
int m,n,t;

input>>m>>n>>t; 
    for(int i = 0;i<m;i++){
        input>>M[i];
    }

    for(int i = 0;i<n;i++){
        input>>N[i];
    }

    int pm = 0;
    int pn = 0;
    bool correct = true;

    for(int i = 0;i<n+m;i++){
        int val;
        input >> val;

        if(pm<m && val == M[pm]){
            S[i]=0;
            pm++;
         }
        else if(pn<n && val==N[pn]) {
            S[i]=1;
            pn++;
        }else{
            correct = false;
        }
    }   

output<<correct<<endl;
    if(t==1 && correct){
        for(int i =0;i<n+m;i++){
        output<<S[i]<<"";
    }
    output<<endl;}
}






