/**
* user:  VR439207
* fname: TROTTI
* lname: FRANCESCO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 08:02:39.719231
*/
#include <stdlib.h>
#include <fstream>
#include <cassert>
#include <iostream>

const int MAX_N = 500;
const int MAX_VAL = 10;

int n, B0, x[MAX_N];

using namespace std;
/*
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}
*/
int main(void){
    int res;
    int count, Bpre;
    cin >> n >> B0;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        // precedente
        Bpre = B0; 
        // aggiornato
        B0 = B0 + x[i];
        for (int k=0; k< B0; k++){
            res = Bpre - k;
            if (res >= 0 ){
                count++;
            }
        }
    }
    //print_array(x, n);

    cout << count << endl;
    return 0;

}