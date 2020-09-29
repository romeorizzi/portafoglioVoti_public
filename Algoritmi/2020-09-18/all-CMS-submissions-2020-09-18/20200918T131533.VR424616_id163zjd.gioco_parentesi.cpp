/**
* user:  VR424616_id163zjd
* fname: ALESSANDRA
* lname: CASTIGLIONI
* task:  gioco_parentesi
* score: 0.0
* date:  2020-09-18 13:15:33.522892
*/
#include <cassert>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <limits>
#include <deque>
#include <vector>
using namespace std;

int N;
const int MAX_N = 1000000;

char f[MAX_N];
int giocate[MAX_N];



int main() {
    vector<int> giocate;
    cin >> N;
    if (N < 2 || N > MAX_N || N % 2 != 0) {
        return 0;
    }
    
    // fill_n(giocate, MAX_N, 0);
    // print_array(giocate, 10);

    int ap = 0, chi = 0, num_giocate = 0;
    int j = 0;
    int res = 0;

    for (int i = 0; i < N; i++) {
        cin >> f[i];
        if (f[i] == '(') {
            ap++;
        } else {
            chi++;
        } 

        if (ap == chi) {
            res=ap+chi;
            giocate.push_back(res);
            ap = chi = 0;
            num_giocate++;
        }
    }

    giocate.resize(num_giocate);
    if(num_giocate == 1){
        cout << "1" << endl;
        cout << "0 " << N << endl;
    }
    else{
        if(num_giocate%2!=0){
            for(int i=0; i<num_giocate; i++){
                if(giocate[i]){
                    cout << "1" << endl;
                    cout << giocate[i]-giocate[i-1] << " " << N-(N-giocate[i]) << endl; 
                }
            }
            
        }
        else{
            cout << "0" << endl;
        }
    }
    /* if (num_giocate!=1 && num_giocate% 2 != 0) {
        cout << "1" << endl;
        cout << "0" << " " << giocate[0]-1 << endl; 
    } else if(){
        cout << "0" << endl;
    }*/

    return 0;
}