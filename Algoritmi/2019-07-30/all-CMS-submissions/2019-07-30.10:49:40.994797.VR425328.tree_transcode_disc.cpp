/**
* user:  VR425328
* fname: MOUHAMED
* lname: FALL
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 10:49:40.994797
*/
/**
 *  Template per soluzione in c++ per il problema tree_transcode_disc
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
using namespace std;

const int MAX_N = 1000000;
const int MAX_VAL = 10;

int n, B0, x[MAX_N], input_type;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int main() {
    cin >> input_type;
    // leggere la sequenza che codifica l'albero in formato input_type

    // ottenere la codifica nell'altro formato
    
    cout << 3-input_type << endl;

    // scrivere la nuova codifica dell'albero
    
    return 0;
}

