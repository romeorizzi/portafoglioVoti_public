/**
* user:  VR433357
* fname: MOSCHIN
* lname: FEDERICO
* task:  Prob1_tree_split_out
* score: 42.0
* date:  2019-09-04 09:41:12.495082
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
int in_tree[MAX_N], livelli[MAX_N];
int pos_r = 0;

//Funziona
void evapora3(){ 
  if(n == 1 || pos_r == n){//Solo radice, evapora e non lascia nulla? Oppure finisco di leggere il file
    return;
  }

  int livello = in_tree[pos_r];

  if(livello %2 == 0){//Nodo livello pari, sopravvive e sale di livello/2 step (visto che i livello/2 livelli dispari precedenti saranno evaporati)
    if(livello > 0){ cout<< livello - (livello/2) << " "; } // Apro livello sottoalbero
    else{ cout<<livello << " "; }
  }
    pos_r++;
    evapora3();

}

//Per ogni nodo dell'albero codifica 1 ne salva la profondità in levels
void creaLivelli(int depth){
  if(pos_r == n ){//File finito
    return;
  }

  //cout << "n = "<< in_tree[pos_r] << " d = "<<depth<<endl;

  livelli[pos_r] = depth;

  if(in_tree[pos_r] == 0){//Non ha figli
    return;
  }

  depth++;
  int numero_figli = in_tree[pos_r];
  for(int i = 0;i<numero_figli;i++){
    pos_r++;
    creaLivelli(depth);
  }

}

void evapora2(){

}


int main() {
    // leggere l'input_type:
    cin >> input_type;

    // leggere la sequenza che codifica l'albero in input (in formato input_type):
    int val;
    while (cin >> val)
      in_tree[n++] = val;

     int sum = 0;
    switch(input_type){
      case 1:
        cout<< input_type << " ";
        //cout << endl; //DA TOGLIERE
        creaLivelli(0);
        pos_r = 0;

       
        for(int i = 0; i< n;i++){
          int depth = livelli[i];
          if(depth %2 == 0){ //Sopravvive e stampo i figli

            if(in_tree[i] == 0 ){//Se non ha figli e sopravvive stampo 0 e vado al prossimo
              cout << 0 << " ";
              continue;
            }

            sum = 0;
            for(int j = i;j<n;j++){ // j = i è giusto?
              if(livelli[j] == depth+2){sum++;} //Cerco i nodi figli che sopravvivono cioè quelli del livello pari successivo
            }
            cout << sum << " ";
           }

          }
      break;

      case 2:
        cout<< input_type << " ";
        evapora2();
      break;

      case 3:
        cout<< input_type << " ";
        evapora3();
      break;

      default:
      break;
    }
    return 0;
}

