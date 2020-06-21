/**
* user:  VR439205
* fname: LUMPP
* lname: FRANCESCO
* task:  online_budget_opt
* score: 0.0
* date:  2019-07-30 12:13:50.100526
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

struct Nodo{
    Nodo * padre;
    vector <Nodo*> figli;
    int n;
    int sommaRim;
};

void depth(Nodo * n ){
    res.push_back(n->n);
    for (int i = n->figli.size()-1; i>=0;i--){
        depth(n->figli[i]);
    }
}

deque <Nodo *> alberiLiberi;

int main()
{
    Nodo root;
    root.sommaRim = 0;
    int input_type;
    Nodo * ptr = &root;
    scanf("%i", &input_type);
    int tmp;
    int val;
    int i = 0;
    do{
        val = scanf("%i", &tmp);
        if (val <= 0) break;
        if (input_type == 1){
            Nodo * nuovoNodo = new Nodo;
            nuovoNodo->padre = ptr;
            nuovoNodo->n = tmp;
            nuovoNodo->sommaRim = tmp;
            ptr = nuovoNodo;
            while (ptr->sommaRim == 1){
                res.push_back(ptr->n);
                ptr->padre->sommaRim -= ptr->n;
                ptr = ptr->padre;
            }
        }else{
            ptr = 0;
            Nodo * nuovoNodo = new Nodo;
            nuovoNodo->n = tmp;
            nuovoNodo->sommaRim = tmp;
            while (nuovoNodo->sommaRim > 1){
                Nodo * k = alberiLiberi.back();
                alberiLiberi.pop_back();
                nuovoNodo->figli.push_back(k);
                k->padre = nuovoNodo;
                nuovoNodo->sommaRim -= k->n;
            }
            alberiLiberi.push_back(nuovoNodo);
        }

    }while (ptr != &root);

    if(input_type == 2){
        depth(alberiLiberi.back());
    }


    printf("%i ", 3-input_type);
    for (int i = 0; i<res.size();i++){
        printf("%i ", res[i]);
    }
    return 0;
}
