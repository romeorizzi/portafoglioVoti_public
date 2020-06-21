/**
* user:  VR439346
* fname: MASOTTO
* lname: GIOVANNI
* task:  online_budget
* score: 0.0
* date:  2019-07-30 08:04:02.047279
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


int rec(int *arr,int n,int B0,int somma,int y,int Bi){




}

int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
       cin >> x[i]; // leggo i periodi

    print_array(x, n);
    int somma = 0;
    int y = 1;
    //rec(x,n,B0,somma,y)
    cout << 42 << endl;
    return 0;
}
