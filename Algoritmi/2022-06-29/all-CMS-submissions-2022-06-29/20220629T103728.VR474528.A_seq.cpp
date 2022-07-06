/**
* user:  VR474528
* fname: DAVIDE
* lname: FURLANI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 10:37:28.849334
*/
#include <iostream>
#include <fstream>
using namespace std;


int goal = 0;
int tot_len = 0;


int main(){

    // ifstream in_file;
    // in_file.open("a_input.txt");
    // in_file >> goal;
    // in_file >> tot_len;
    cin >> goal;
    cin >> tot_len;

    int base_seq[tot_len];
    int base_rev[tot_len];
    int length_inc[tot_len];
    int length_dec[tot_len];
    int length_inc_norm[tot_len];
    int length_dec_norm[tot_len];


    for(int i=0; i<tot_len; i++){
        cin >> base_seq[i];
        // in_file >> base_seq[i];
        base_rev[tot_len-1-i] = base_seq[i];
        length_inc[i] = 0;
        length_dec[i] = 0;
        length_inc_norm[i] = 0;
        length_dec_norm[i] = 0;
    }

    // inc
    for (int i = 0; i < tot_len; i++) {
        length_inc[i] = 1;
        length_inc_norm[i] = 1;
        for (int j = 0; j < i; j++) {
            if (base_seq[j] < base_seq[i]) {
                length_inc[i] = max(length_inc[i],length_inc[j]+1);
                length_inc_norm[i] = length_inc[i];
            }
        }
    }

    // dec
    for (int i = 0; i < tot_len; i++) {
        length_dec[i] = 1;
        length_dec_norm[i] = 1;
        for (int j = 0; j < i; j++) {
            if (base_rev[j] < base_rev[i]) {
                length_dec[i] = max(length_dec[i],length_dec[j]+1);
                length_dec_norm[i] = length_dec[i];
            }
        }
    }



    for(int i=0; i<tot_len; i++){
        if(length_inc_norm[i] < length_inc_norm[i-1] && i-1 >= 0)
            length_inc_norm[i] = length_inc_norm[i-1];

        if(length_dec_norm[i] < length_dec_norm[i-1] && i-1 >= 0)
            length_dec_norm[i] = length_dec_norm[i-1];        
    }


    // goal 1
    if(goal == 1){
        int max_a = max(length_inc_norm[tot_len-1], length_dec_norm[tot_len-1]);
        for(int i=0; i<tot_len-1; i++)
            if(max_a < length_dec_norm[i]+length_inc_norm[tot_len-2-i])
                max_a = length_dec_norm[i]+length_inc_norm[tot_len-2-i];

        cout << max_a;
    }

    // goal 2
    if(goal == 2){
        int n_max_a = 1;
        int max_a = max(length_inc_norm[tot_len-1], length_dec_norm[tot_len-1]);
        for(int i=0; i<tot_len-1; i++)
            if(max_a < length_dec_norm[i]+length_inc_norm[tot_len-2-i])
                max_a = length_dec_norm[i]+length_inc_norm[tot_len-2-i];

        if(length_inc_norm[tot_len-1] == length_dec_norm[tot_len-1])
            n_max_a++;

        for(int i=0; i<tot_len-1; i++)
            if(max_a == length_dec[i]+length_inc[tot_len-2-i])
                n_max_a++;

        cout << n_max_a;
    }

    // for(int i=0; i<tot_len-1; i++){
    //     if(max_a == length_dec_norm[i]+length_inc_norm[tot_len-2-i])
    //         n_max_a++;
        
    //     if(max_a < length_dec_norm[i]+length_inc_norm[tot_len-2-i])
    //         max_a = length_dec_norm[i]+length_inc_norm[tot_len-2-i];
    // }

    cout << "cocco";

    return 0;
}