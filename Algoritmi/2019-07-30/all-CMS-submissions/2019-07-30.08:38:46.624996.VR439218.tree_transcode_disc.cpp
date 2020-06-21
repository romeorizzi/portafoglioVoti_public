/**
* user:  VR439218
* fname: MANTOVAN
* lname: FILIPPO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 08:38:46.624996
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

const int MAX_N = 1000000;
const int MAX_VAL = 10;

int B0, albero[MAX_N], input_type;
int N = 0;
int s = 0;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

void seconda_codifica(int nodo){
    if (nodo == 1){
        cout << nodo << " ";
        return;
    }

    else {
        int indice = 0;
        while (indice!=nodo-1){
            s++;
            indice += albero[s];
            seconda_codifica(albero[s]);
        }
        
        cout << nodo << " ";
        return;
    }

}


int main() {
    int value;
    ifstream inFile;
    inFile.open("input0.txt");

    /*inFile >> input_type;*/
    cin >> input_type;

    
    while (cin >> value){
    /*while (inFile >> value){*/
        albero[N] = value;
        N++;
    }
    print_array(albero,N);

    cout << 3-input_type << " ";

    //Devo passare alla seconda codifica
    if (input_type == 1)
        seconda_codifica(albero[0]);
    //Devo passare alla prima codifica
    //else 

    

    
    return 0;
}
