/**
* user:  VR439346
* fname: MASOTTO
* lname: GIOVANNI
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 09:14:42.390821
*/
/**
 *  Template per soluzione in c++ per il problema tree_transcode_disc
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin;
ofstream fout;
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
    fin.open("input1.txt");
    fout.open("output.txt");
    int input_type;
    fin >> input_type;
    fout << 3-input_type << " ";
    if (input_type == 1){
    printf("ciao");
    }
    else printf("no");
    // leggere la sequenza che codifica l'albero in formato input_type

    // ottenere la codifica nell'altro formato

    cout << 3-input_type << endl;

    // scrivere la nuova codifica dell'albero

    return 0;
}
