/**
* user:  VR439346
* fname: MASOTTO
* lname: GIOVANNI
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 10:27:01.166870
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>

using namespace std;

const int MAX_N = 500; //numero di periodi potrei mettere 200
const int MAX_VAL = 10;

int n, B0, x[MAX_N];
int poss_spese[11] = {0,1,2,3,4,5,6,7,8,9,10};

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}


int rec(int *arr,int B0,int *poss_spese,int somma,int j,int i,int Bi){
    for(int m = 0; m < B0;m++){
        int a = B0-poss_spese[j];//sarebbe la mia y_i
        if (a == 0) return 1;
        if (a<0){
                somma += rec(arr,B0,poss_spese,somma,j-1,i+1,Bi);
            }
        else{
            Bi = a;
            B0 = Bi+arr[i];
            somma =somma + rec(arr,B0,poss_spese,somma,j+1,i+1,Bi) +1;
        }
    }


}

int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
       cin >> x[i]; // leggo i periodi

    //print_array(x, n);
    int somma = 0;
    int y = 1;
    if(B0 == 0) cout << 1<< endl;
    else somma = rec(x,B0,poss_spese,somma,0,0,0);

    cout << somma << endl;
    return 0;
}


