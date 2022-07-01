/**
* user:  VR474528
* fname: DAVIDE
* lname: FURLANI
* task:  k_up_1_down_seq
* score: 14.0
* date:  2022-06-29 13:05:21.183525
*/
#include <iostream>
#include <fstream>
using namespace std;


int goal = 0;
int num_cifre = 0;
int k = 0;
int mem[1000][1000];

int seq(int lst, int rem){

    if(mem[lst][rem] != -1)
        return mem[lst][rem];

    if(rem==0){
        if(lst == 0)
            return 1;
        else
            return 0;
    }
    if(lst>0){
        mem[lst][rem] = (seq(lst, rem-1) + seq(lst-1, rem-1) + seq(lst+k, rem-1)) % 1000000007;
        return mem[lst][rem];
    }else{
        mem[lst][rem] = seq(lst, rem-1) + seq(lst+k, rem-1) % 1000000007;
        return mem[lst][rem];
    }
}


int main(){

    // ifstream in_file;
    // in_file.open("k_input.txt");
    // in_file >> goal;
    // in_file >> num_cifre;
    // in_file >> k;
    cin >> goal;
    cin >> num_cifre;
    cin >> k;

    for (int i=0; i<1000; i++){
        for (int j=0; j<1000; j++){
            mem[i][j] = -1;
        }
    }


    cout << seq(0, num_cifre-1);


}
