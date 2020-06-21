/**
* user:  VR433357
* fname: MOSCHIN
* lname: FEDERICO
* task:  Prob1_tree_split_out
* score: 30.0
* date:  2019-09-04 08:21:27.572553
*/
/**
 *  Template per soluzione in c++ per il problema tree_split_out
 *
 *  Romeo Rizzi, per l'appello di algoritmi 2019-09-04
 *
 */

#include <cassert>
#include <iostream>
#include <stdbool.h>
using namespace std;

const int MAX_N = 1000000;

int n = 0, input_type;
int in_tree[MAX_N], out_tree[MAX_N];
int pos_r,pos_w;

void evapora3(){ 
  if(n == 1 || pos_r == n){//Solo radice, evapora e non lascia nulla? Oppure finisco di leggere il file
    return;
  }

  int livello = in_tree[pos_r];

  if(livello %2 == 0){//Nodo livello pari, sopravvive e sale di 1
    if(livello > 0){ cout<< livello - (livello/2) << " "; } // Apro livello sottoalbero
    else{ cout<<livello << " "; }
  }
    pos_r++;
    evapora3();

}


int main() {
    // leggere l'input_type:
    cin >> input_type;

    // leggere la sequenza che codifica l'albero in input (in formato input_type):
    int val;
    while (cin >> val)
      in_tree[n++] = val;


    switch(input_type){
      case 1:
        cout<< input_type;
      break;
      case 2:
        cout<< input_type;
      break;
      case 3:
        cout<< input_type << " ";
        evapora3();
      break;
      default:
      break;
    }

    // in questo template di soluzione mi limito a ricopiare l'input in output (non sarà mai la soluzione corretta tranne che per alberi di un solo nodo):
   /* cout << input_type << ' ';

    for(int i=0; i<n; i++)
      cout << in_tree[i] << ' ';
    cout << endl;*/
    
    return 0;
}

