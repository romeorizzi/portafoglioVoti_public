/**
* user:  VR445666
* fname: GAIARDELLI
* lname: SEBASTIANO
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 11:54:48.232682
*/
#include <bits/stdc++.h>

using namespace std;
int N;
int t;
int *value, *E, *F;
bool free_swap = true;

bool valid_prop(int parent, int index){
    if(index >= N ){

        return true;
    }

    if(E[index]==1 && parent > value[index]){
        return false;
    }

    return valid_prop(value[index], (2*index)+1) && valid_prop(value[index], 2*(index+1));
}

bool valid_prop_swap(int parent, int index, int min_unch){
    if(index >= N ){

        return true;
    }

    if(E[index]==1 && parent > value[index] && value[index] < min_unch){
        return false;
    }

    if(F[index]==1 && (min_unch==-1 || value[index] < min_unch)){
        min_unch=value[index];
    }

    return valid_prop_swap(value[index], (2*index)+1,min_unch) && valid_prop_swap(value[index], 2*(index+1),min_unch);
}

int main(){

    ifstream input;
    ofstream output;
    input.open("input.txt");
    output.open("output.txt");

    input >> N;
    input >> t;

    

    value = new int[N];
    E = new int[N];
    F = new int[N];
    
    for(int i = 0; i < N ; i++){
        input >> value[i];
    }

    for(int i = 0; i < N ; i++){
        input >> E[i];
    }

    if(t==2){
        for(int i = 0; i < N ; i++){
            input >> F[i];
            if(F[i]!=0){
                free_swap=false;
            }
        }
    }

    int min_unch = F[0]==1? value[0] : -1;
    if(t == 2 && free_swap){
        output << 1 << "\n";
    }else if(t == 1 && valid_prop(value[0], 1) && valid_prop(value[0],2)){
        output << 1 << "\n";

    }else if(t == 2 && valid_prop_swap(value[0], 1,min_unch) && valid_prop_swap(value[0],2,min_unch)){
        output << 1 << "\n";

    }else{
        output << 0 << "\n";
    }

    return 0;
}