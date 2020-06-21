/**
* user:  VR439218
* fname: MANTOVAN
* lname: FILIPPO
* task:  tree_transcode_disc
* score: 90.0
* date:  2019-07-30 09:42:01.607182
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
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;
const int MAX_VAL = 10;

int B0, albero[MAX_N], input_type, copia_albero[MAX_N];
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

void prima_codifica(vector<vector<int>> adiacenze, int posizione){
    
    cout << albero[posizione] << " ";

    if (adiacenze[posizione].size() == 0){
        return;
    }
    else {
        for (int i=0 ; i<adiacenze[posizione].size() ; i++){
            prima_codifica(adiacenze, adiacenze[posizione][i]);
        }
        return;
    }
}


int main() {
    int value;
    ifstream inFile;
    inFile.open("input1.txt");

    //inFile >> input_type;
    cin >> input_type;

    
    while (cin >> value){
    //while (inFile >> value){
        albero[N] = value;
        copia_albero[N] = value;
        N++;
    }
    
    vector <vector<int>> adiacenze(N);

    cout << 3-input_type << " ";




    //Devo passare alla seconda codifica
    if (input_type == 1)
        seconda_codifica(albero[0]);
    else if (input_type == 2){
        
        for (int i=0 ; i<N ; i++){
            if (copia_albero[i]!=1){
                int size=0;
                for (int k=i-1 ; k>=0; k--){
                    if((copia_albero[k]!= -1) && (size<copia_albero[i]-1)){
                        adiacenze[i].push_back(k);
                        size += copia_albero[k];
                        copia_albero[k] = -1;
                    }
                }
                reverse(adiacenze[i].begin(), adiacenze[i].end());
            }
        } 

        prima_codifica(adiacenze, N-1);
    }

    /*stampa lista adiacenze
    for (int i=0;i<N;i++){
        printf ("Nodo: %d ----> ", albero[i]);
        for (int k=0 ; k<adiacenze[i].size();k++){
            int pos = adiacenze[i][k];
            printf (" %d", pos);
        }
        printf("\n");
    }*/

    
    return 0;
}
