/**
* user:  VR445666
* fname: GAIARDELLI
* lname: SEBASTIANO
* task:  poldo_sums
* score: 59.0
* date:  2020-06-18 11:29:58.707146
*/
#include <bits/stdc++.h>

using namespace std;
int N;

int main(){

    ifstream input;
    ofstream output;
    input.open("input.txt");
    output.open("output.txt");

    input >> N;

    int *menu, *lds, *gym;
    //array chain
    int prev[N];
    //array sum
    long int *sum;

    menu = new int[N];
    gym = new int[N];
    lds = new int[N];
    sum = new long int[N];

    input >> menu[0];
    input >> gym[0];
    sum[0] = gym[0];
    lds[0] = 1;
    prev[0]= -1;
    for(int i = 1; i < N ; i++){
        input >> menu[i];
        input >> gym[i];
        sum[i] = sum[i-1] + gym[i];
        lds[i]=1;
        prev[i]=-1;
    }

    int max = 1;
    int max_index=0;
    for(int i = 1; i < N ; i++){
        int j = 0;
        //case j = 0
        if(lds[i]<lds[j]+1 && menu[j] + (sum[i-1])<= menu[i]){
            lds[i]=lds[j]+1;
            prev[i]=j;
        }

        for(j = 1; j < i ;j++){
            if(lds[i]<lds[j]+1 && menu[j] + (sum[i-1]-sum[j-1]) <= menu[i]){
                
                lds[i]=lds[j]+1;
                prev[i]=j;
            }
        }

        if(lds[i]>max){
            max = lds[i];
            max_index=i;
        }
    }
    output << max << "\n";

    //find sequence
    std::string seq = "";
    seq = std::to_string(max_index) + " " + seq;
    
    while(prev[max_index]!=-1){
        max_index = prev[max_index];
        seq = std::to_string(max_index) + " " + seq;
    }

    output << seq << "\n";

    return 0;
}