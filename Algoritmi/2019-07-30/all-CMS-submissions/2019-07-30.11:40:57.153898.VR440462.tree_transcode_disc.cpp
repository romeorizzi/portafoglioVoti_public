/**
* user:  VR440462
* fname: GOBBI
* lname: FRANCESCO
* task:  tree_transcode_disc
* score: 40.0
* date:  2019-07-30 11:40:57.153898
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

vector<int> figli[100000];
int n[100000]; //numero figli
int nodi = 0; //numero dei nodi nell'albero

int Creo_Tipo2(int padre);
void Stampo_Tipo2(int padre);
int Creo_Tipo1(int padre);

int main() {

    int tipoCod = 0; //per la codifica
    cin>>tipoCod; 

    if(tipoCod==1) {
        Creo_Tipo2(0);//per indice 0 dell'array
        cout<< "2 ";//per la codifica 2
        Stampo_Tipo2(0);
    } 
    else {//quindi ho una codifica di tipo 2
        cout<< "1 ";//per la codifica 1
    }
    cout<<endl;

}//fine main

int Creo_Tipo2(int padre) {
    int nFigli = 0;
    cin>>nFigli;  //prendo il tipo
    n[padre] = nFigli;
    nFigli = nFigli-1; //perchè la radice non si conta

    int albero = 0;
    while(albero<nFigli) { //per il sotto-albero
        nodi++;//incremento il numero dei nodi che sono aumentati
        figli[padre].push_back(nodi);
        albero = albero + Creo_Tipo2(nodi);
    }

    return n[padre]; //in definitava ho l'array ricostruito
}

void Stampo_Tipo2(int padre) {
    int i = 0;
    for (i; i<figli[padre].size();i++) {
        int figlio = figli[padre][i];
        Stampo_Tipo2(figlio);
    }
    cout << n[padre] << " "; //non termino la riga
    
}

int Creo_Tipo1(int padre) {
    int nFigli = 0;
    cin>>nFigli;  //prendo il tipo
    n[padre] = nFigli;//mi salvo il figlio
    nFigli = nFigli-1; //perchè la radice non si conta

    int albero = 0;
    while(albero<nFigli) { //per il sotto-albero
        nodi++;//incremento il numero dei nodi che sono aumentati
        figli[padre].push_back(nodi);
        albero = albero + Creo_Tipo2(nodi);
    }

    for (int i=(figli[padre].size())-1; i>0;i--) {
        cout << n[padre] << " "; //non termino la riga
    }

    
}