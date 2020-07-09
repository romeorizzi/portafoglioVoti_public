/**
* user:  VR445666
* fname: GAIARDELLI
* lname: SEBASTIANO
* task:  poldo_sums
* score: 59.0
* date:  2020-06-18 12:29:44.295884
*/
#include <bits/stdc++.h>

using namespace std;
int N;


int max_val = 1;
int max_index=0;

void find_maxsubseq_menu_or_gym(int menu[], int lds[],int prev[]){

    for(int i = 1; i < N ; i++){
        int j = 0;

        for(j = 0; j < i ;j++){
            if(lds[i]<lds[j]+1 && menu[j]  <= menu[i]){
                
                lds[i]=lds[j]+1;
                prev[i]=j;
            }
        }

        if(lds[i] > max_val){
            max_val = lds[i];
            max_index=i;
        }
    }
}

void find_maxsubseq_menu_and_gym(int menu[], int lds[],int prev[], long int sum[]){

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

        if(lds[i] > max_val){
            max_val = lds[i];
            max_index=i;
        }
    }
}

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

    bool menu_divzero = false;
    bool gym_divzero = false;
    for(int i = 1; i < N ; i++){
        input >> menu[i];
        input >> gym[i];
        if(menu[i]!=0){
            menu_divzero=true;
        }

        if(gym[i]!=0){
            gym_divzero=true;
        }

        sum[i] = sum[i-1] + gym[i];
        lds[i]=1;
        prev[i]=-1;
    }

    if(!menu_divzero){
        find_maxsubseq_menu_or_gym(gym,lds,prev);
    }else if(!gym_divzero){
        find_maxsubseq_menu_or_gym(menu,lds,prev);
    }else{
        find_maxsubseq_menu_and_gym(menu, lds,prev, sum);
    }

    
    output << max_val << "\n";

    //find sequence
    deque<int> seq;
    //std::string seq = "";
    //seq = std::to_string(max_index) + " " + seq;
    seq.push_front(max_index); 
    while(prev[max_index]!=-1){
        max_index = prev[max_index];
        //seq = std::to_string(max_index) + " " + seq;
        seq.push_front(max_index); 
    }

    deque<int>::iterator it; 
    for (it = seq.begin(); it != seq.end(); ++it){ 
        output << *it << " ";
    }
    output << "\n";

    return 0;
}