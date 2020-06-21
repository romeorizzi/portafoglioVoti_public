/**
* user:  VR438310
* fname: ZAMPIERI
* lname: AMEDEO
* task:  Prob1_tree_split_out
* score: 30.0
* date:  2019-09-04 08:32:35.587372
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
int levels[MAX_N] = {0};

int level = 0, indice = 0;

//I -1 stanno per l'incremento anticipato, necessario però a rendere l'algoritmo semplice da leggere
void build_levels1()
{
  //salvo il livello e incremento l'indice (unica parte comune a tutti i nodi!)
  levels[indice++] = level;

  //cout << "nodo: " << 

  //In caso di un livello foglia non faccio nulla oltre a salvare il livello
  if (in_tree[indice - 1] == 0)
    return;

  //se sono in un nodo intermedio devo guardare tutti i figli
  int n_child = in_tree[indice - 1];    //salvo # dei figli
  level++;                          //aumento il livello perché

  for(int c = 0; c < n_child; c++)
  {
    build_levels1();
  }

  level--;

  return;
    
}

//ritorna la dimensione del nodo esaminato
int build_levels2()
{
  //salvo il livello e incremento l'indice (unica parte comune a tutti i nodi!)
  levels[indice++] = level;

  //cout << "nodo: " << 

  //In caso di un livello foglia non faccio nulla oltre a salvare il livello
  if (in_tree[indice - 1] == 1)
    return 1;

  //se sono in un nodo intermedio devo guardare tutti i figli
  int dim_child = in_tree[indice - 1] - 1;    //salvo la dimensione dei figli
  //faccio -1 perché devo escludere il nodo padre (che sto considerando)
  level++;                          //aumento il livello perché i figli saranno un livello sotto

  for(int dim_c = dim_child; dim_c > 0;)
  {
    dim_c -= build_levels2();
  }

  level--;

  return dim_child + 1;
}

void evap1()
{
  //indice nel nuovo albero
  int j = 0;
  //Scorro la lista e tengo solo i livelli pari.
  //il numero del nuovo livello sarà una divisione per due?
  for (int i = 0; i < n; i++)
  {
    if (levels[i] % 2 == 0)
    {
      out_tree[j++] = in_tree[i] / 2;
      //cout << in_tree[i];
    }
  }

  n = j;
}

//Se il livello è pari nella codifica 3 sarà un numero pari
void evap3()
{
  //indice nel nuovo albero
  int j = 0;
  //Scorro la lista e tengo solo i livelli pari.
  //il numero del nuovo livello sarà una divisione per due?
  for (int i = 0; i < n; i++)
  {
    if (in_tree[i] % 2 == 0)
    {
      out_tree[j++] = in_tree[i] / 2;
      //cout << in_tree[i];
    }
  }

  n = j;
}

int main() {
    // leggere l'input_type:
    cin >> input_type;

    // leggere la sequenza che codifica l'albero in input (in formato input_type):
    int val;
    while (cin >> val)
      in_tree[n++] = val;

    if (input_type == 3)
      evap3();

    if (input_type == 1)
    {
      build_levels1();
      /*
      for(int i=0; i<n; i++)
        cout << levels[i] << ' ';
      cout << endl;
      */
      evap1();
    }

    if (input_type == 2)
    {
      build_levels1();
      
      for(int i=0; i<n; i++)
        cout << levels[i] << ' ';
      cout << endl;
      
      //evap2();
    }

    cout << input_type << ' ';

    for(int i=0; i<n; i++)
      cout << out_tree[i] << ' ';
    cout << endl;
    
    return 0;
}

