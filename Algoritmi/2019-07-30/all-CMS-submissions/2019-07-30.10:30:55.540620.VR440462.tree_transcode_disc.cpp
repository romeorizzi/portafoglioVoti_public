/**
* user:  VR440462
* fname: GOBBI
* lname: FRANCESCO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 10:30:55.540620
*/
/**
 *  Template per soluzione in c++ per il problema tree_transcode_disc
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

//#include <cassert>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <limits.h>
#include <stdlib.h>
#include <list>


using namespace std;

FILE *input, *output; //per i file fi lettura e scrittura

struct Nodo{ //struttura per il nodo, in cui salvo la somma, la profondità e la posizione nell'albero
  Nodo *padre;
  int somma;
  int SommaRimanente;
  int profondità;
  int posizione;
};

vector<int> Array;


int main() {
  
    input = fopen("input0.txt", "r"); //per sola lettura
    output = fopen("output.txt","w"); //per sola scrittura  

    //radice dell'albero
    Nodo radice;
    Nodo *ptr = &radice;

    int Valore; // numero discendeti della radice (solo per la codifica 1)
    int tipo; //tipo dell'albero per la diversa codifica
    //inizializzo la radice con numeri più grandi possibili!!
    radice.somma = 10000000;
    radice.SommaRimanente = 10000000;
    radice.profondità = -1; //perchè sono nella radice

    fscanf(input, "%i", &tipo);  //prendo il tipo
    if (tipo==1) fprintf(output, "2"); // da 1 a 2 (1-->2)
    else fprintf(output, "1"); // da 2 a 1 (2-->1)


    int MaxPos = 0;
    // ottenere la codifica nell'altro formato
    while(true) {
      fscanf(input, "%i", &Valore);
      if (tipo==1) { //tipo 1
        Nodo * newNodo = new Nodo(); //creo i nodo figlio
        newNodo->padre = ptr; //punta al nodo 
        newNodo->profondità = ptr->profondità+1; //il figlio è ad un livello inferiore

        newNodo->SommaRimanente = Valore;
        newNodo->somma = Valore;
        ptr = newNodo; //il nodo figlio diventa la nuova radice

        Array.push_back(ptr->profondità); //iserisco in coda il val di profondità

        while(ptr-> SommaRimanente == 1) { //quando la solla rimante sarà 1 ritorno al padre
          Array.push_back(ptr->profondità);
          ptr->padre->SommaRimanente -= ptr->somma;
          ptr = ptr->padre;
        }
      }//fine tipo 1

      /*else { //tipo 2

        if (ptr->profondità==Valore) {
          ptr->somma++;
          ptr->padre->somma += ptr->somma;
          Array[ptr->posizione] += ptr->somma;
          ptr = ptr->padre;
        }//fine if


        else {
          Nodo * newNodo = new Nodo(); //creo i nodo figlio
          newNodo->padre = ptr; //punta al nodo 
          newNodo->posizione = MaxPos;
          Array.push_back(0);
          MaxPos++;
          ptr = newNodo;
    
        }
      }//fine else tipo 2*/
      if (ptr==&radice) break; //termino se sono ritornato alla radice in qualsiasi tipo di codifica

    }//fine while

    // scrivere la nuova codifica dell'albero
    for (int i=0; i<Array.size(); i++) {
      fprintf(output, "%i", Array[i]);
    }
}

