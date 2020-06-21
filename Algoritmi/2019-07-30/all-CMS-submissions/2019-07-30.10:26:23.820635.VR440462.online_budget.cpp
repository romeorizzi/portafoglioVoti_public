/**
* user:  VR440462
* fname: GOBBI
* lname: FRANCESCO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 10:26:23.820635
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 500;
const int MAX_VAL = 10;

int n, B0, x[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int main() {

    ifstream file;
    file.open("input.txt");
    ofstream out; 
    out.open("output.txt");

    file >> n >> B0; //leggo la prima riga
    for(int i = 0; i < n; i++)
       file >> x[i]; //leggo il vettore dei guadagni
    //print_array(x, n);

    printf("%d\n",n);
    printf("%d\n", B0);
    for(int i = 0; i < n; i++) printf("%d ", x[i]);

    int n_val = 0;
    if(n==1) n_val=B0+1; //caso semplice

    else {
      n_val = (B0+1)*(x[0]+1)*2;   
    }
    out << n_val;

}

