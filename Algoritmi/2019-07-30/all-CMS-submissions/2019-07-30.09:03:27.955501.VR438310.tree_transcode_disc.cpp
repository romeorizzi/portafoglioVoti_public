/**
* user:  VR438310
* fname: AMEDEO
* lname: ZAMPIERI
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 09:03:27.955501
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

int n = 0, B0, input_type;
int in_tree[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

void one2two(int index)
{
  //Caso base del reverse:
  //Trovo una foglia. Allora la stampo
  if (in_tree[index] == 1)
  {
    cout << 1 << ' ';
    return;
  }

  //Altrimenti devo saltare di figlio in figlio fino in fondo al suo albero
  int node_offset = in_tree[index];
  int child_index = index + 1;  //raggiungo il primo figlio

  //raggiungo il primo figlio, poi tutti gli altri in base all'offset del figlio
  while (child_index < index + node_offset)
  {
    //richiamo nei figli la funzione (in modo da esplorare da sinistra verso destra l'albero)
    //e da visitare per prime le foglie
    one2two(child_index);

    //mi sposto al successivo figlio in base all'offset dettato dal figlio appena letto
    child_index += in_tree[child_index];
  }

  //infine stampo il nodo corrente
  cout << node_offset << ' ';
}

void two2one(int index)
{
  int node_offset = in_tree[index];
  //Per prima cosa stampo la radice del sottoalbero che sto per analizzare
  cout << node_offset << ' ' << "index: " << index << "; ";

  //Parto dal fondo e devo scorrere fino al primo figlio
  //mi salvo quindi la lista degli offset per ogni figlio
  //ogni nodo avrà un numero di figli che al più coincide con la propria dimensione
  int child_offsets[node_offset]; //offset per scorrere tra i figli (dal figlio destro a quello sinistro)
  int child_index = index - 1;
  child_offsets[0] = in_tree[child_index];

  //Salvo subito la dimensione del primo figlio

  //mi segno il numero di figli
  int n_childs = 0;

  //Scorro i figli da destra verso sinistra, quindi decresco il loro indice
  while (child_index > index - node_offset)
  {
    //Salvo l'offset del figlio nell'array
    child_offsets[++n_childs] = child_offsets[n_childs - 1] + in_tree[child_index];

    //sottraggo all'indice attuale la dimensione del figlio
    child_index -= in_tree[child_index];
  }

  print_array(child_offsets, n_childs);

  //a partire dal figlio più a sinistra (ovvero l'ultimo inserito nella lista dei figli)
  //richiamo la funzione
  
  for (int i = n_childs - 1; i >= 0; --i)
  {
    two2one(index - child_offsets[i]);
  }
}


int main() {
    cin >> input_type;
    // leggere la sequenza che codifica l'albero in formato input_type

      int val;
      while (cin >> val)
        in_tree[n++] = val;

    //print test
    print_array<int>(in_tree, n);
    

    // ottenere la codifica nell'altro formato
    cout << 3-input_type << endl;

    if (input_type == 1)
      one2two(0);

    else
      two2one(n-1);
    
    cout << endl; //TODO rimuovere

    // scrivere la nuova codifica dell'albero
    
    return 0;
}

