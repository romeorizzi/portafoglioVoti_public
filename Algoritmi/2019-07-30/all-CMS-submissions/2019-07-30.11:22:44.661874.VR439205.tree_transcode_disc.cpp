/**
* user:  VR439205
* fname: LUMPP
* lname: FRANCESCO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 11:22:44.661874
*/
/**
 *  Template per soluzione in c++ per il problema tree_transcode_disc
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <limits>
#include <deque>
#include <vector>

using namespace std;

vector<int> res;


template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

struct Node{
    Node * padre;
    vector <Node*> figli;
    int n;
    int sommaRimanente;
};

deque <Node *> alberiLib;

void depth(Node * n ){
    res.push_back(n->n);
    for (int i = n->figli.size()-1; i>=0;i--){
        depth(n->figli[i]);
    }
}

int main()
{
    Node root;
    root.sommaRimanente = 0;
    int type;
    Node * ptr = &root;
    cin >> type;
    // leggere la sequenza che codifica l'albero in formato input_type
    int tmp;
    int val;
    int i = 0;
    val = scanf("%i", &tmp);

        if (type == 1){
            Node * nuovoNodo = new Node;
            nuovoNodo->padre = ptr;
            nuovoNodo->n = tmp;
            nuovoNodo->sommaRimanente = tmp;
            ptr = nuovoNodo;
            while (ptr->sommaRimanente == 1){
                res.push_back(ptr->n);
                ptr->padre->sommaRimanente -= ptr->n;
                ptr = ptr->padre;
            }
        }else{
            ptr = 0;
            Node * nuovoNodo = new Node;
            nuovoNodo->n = tmp;
            nuovoNodo->sommaRimanente = tmp;
            while (nuovoNodo->sommaRimanente > 1){
                Node * k = alberiLib.back();
                alberiLib.pop_back();
                nuovoNodo->figli.push_back(k);
                k->padre = nuovoNodo;
                nuovoNodo->sommaRimanente -= k->n;
            }
            
        }
    while(ptr != &root){
        val = scanf("%i", &tmp);
        if (val <= 0) break;
        if (type == 1){
            Node * nuovoNodo = new Node;
            nuovoNodo->padre = ptr;
            nuovoNodo->n = tmp;
            nuovoNodo->sommaRimanente = tmp;
            ptr = nuovoNodo;
            while (ptr->sommaRimanente == 1){
                res.push_back(ptr->n);
                ptr->padre->sommaRimanente -= ptr->n;
                ptr = ptr->padre;
            }
        }else{
            ptr = 0;
            Node * nuovoNodo = new Node;
            nuovoNodo->n = tmp;
            nuovoNodo->sommaRimanente = tmp;
            while (nuovoNodo->sommaRimanente > 1){
                Node * k = alberiLib.back();
                alberiLib.pop_back();
                nuovoNodo->figli.push_back(k);
                k->padre = nuovoNodo;
                nuovoNodo->sommaRimanente -= k->n;
            }
            alberiLib.push_back(nuovoNodo);
        }

    }
    if(type == 2){
        depth(alberiLib.back());
    }
    // scrivere la nuova codifica dell'albero
    cout << 3-type << endl;
    for (int i = 0; i<res.size();i++){
      cout << res[i] << " ";
    }
    return 0;
}

