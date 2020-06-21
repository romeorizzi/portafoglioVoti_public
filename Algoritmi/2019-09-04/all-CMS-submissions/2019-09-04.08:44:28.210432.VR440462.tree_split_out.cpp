/**
* user:  VR440462
* fname: GOBBI
* lname: FRANCESCO
* task:  Prob1_tree_split_out
* score: 30.0
* date:  2019-09-04 08:44:28.210432
*/
/**
 *  Template per soluzione in c++ per il problema tree_split_out
 *
 *  Romeo Rizzi, per l'appello di algoritmi 2019-09-04
 *
 */

#include <cassert>
#include <iostream>

using namespace std;

const int MAX_N = 1000000;

int n = 0, input_type;
int in_tree[MAX_N], out_tree[MAX_N];

int main() {
    // leggere l'input_type:
    cin >> input_type;
    //int valori = 0;
    //cin >> valori;
    // leggere la sequenza che codifica l'albero in input (in formato input_type):
    int val;
    //int i =0;
    while ( cin >> val) { //leggo il numero della stringa di valori
      in_tree[n++] = val;
      }

    // in questo template di soluzione mi limito a ricopiare l'input in output (non sarà mai la soluzione corretta tranne che per alberi di un solo nodo):
    //cout << input_type << ' ';

    if(in_tree[0]==1) { //ho solo la radice
      cout << input_type << ' ';
    }

    //CASO 3
    if(input_type == 3) {
      int j=0; //indice per l'out
      out_tree[j] = 3 ;
      j++;
      for(int i=0; i<n; i++) {
        if(in_tree[i]%2==0) {//quindi è pari
          out_tree[j]=in_tree[i];
          j++;          
        }
      }
      for(int i = 1; i<j; i++) {
        out_tree[i] = out_tree[i]/2;
      }
      n = j; //lunghezza dell'output cambia
    }//fine if per codifica 3

    //cout << "out"<< n << endl;
    //cout << "in" << n << endl;

    //  genero l'output
    for(int i=0; i<n; i++) {
      cout << out_tree[i] << ' ';
    }
    cout << endl;
    
    return 0;
}
