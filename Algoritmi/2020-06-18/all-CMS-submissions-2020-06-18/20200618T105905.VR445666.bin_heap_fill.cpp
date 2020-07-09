/**
* user:  VR445666
* fname: GAIARDELLI
* lname: SEBASTIANO
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 10:59:05.239497
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
        //cout << "error p=" << parent << " > v=" << value[index] << "\n"; 
        return false;
    }

    return valid_prop(value[index], (2*index)+1) && valid_prop(value[index], 2*(index+1));
}

int main(){

    ifstream input;
    ofstream output;
    input.open("input.txt");
    output.open("output.txt");

    input >> N;
    input >> t;

    //cout << "N=" << N << "\n";
    //cout << "t=" << t << "\n";
    

    value = new int[N];
    E = new int[N];
    F = new int[N];
    
    //std::cout << "value\n"; 
    for(int i = 0; i < N ; i++){
        input >> value[i];
    //    cout<<value[i] << " ";
    }

    //std::cout << "\nE\n"; 
    for(int i = 0; i < N ; i++){
        input >> E[i];
    //    cout<<E[i] << " ";
    }

    if(t==2){
    //    std::cout << "\nF\n"; 
        for(int i = 0; i < N ; i++){
            input >> F[i];
    //        cout<<F[i] << " ";
            if(F[i]!=0){
                free_swap=false;
            }
        }
    }
    //cout<<"\n";

    //cout <<"fs= " << free_swap << "\n";
    if(t == 2 && free_swap){
        //cout << "t=2 result 1\n";
        output << 1 << "\n";
    }else if(valid_prop(value[0], 1) && valid_prop(value[0],2)){
        //cout << "result 1\n";
        output << 1 << "\n";

    }else{
        //cout << "result 0\n";
        output << 0 << "\n";
    }

    return 0;
}