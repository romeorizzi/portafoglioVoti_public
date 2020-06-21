/**
* user:  VR440462
* fname: GOBBI
* lname: FRANCESCO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 10:39:38.587330
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
FILE *in, *out; //per i file fi lettura e scrittura


vector<int> figli[1000000];
int n[1000000]; //numero figli
int nodi = 0; //numero dei nodi nell'albero

int Creo_Tipo2(int padre) {
    int nFigli = 0;
    cin>>nFigli;  //prendo il tipo
    n[padre] = nFigli;
    nFigli = nFigli-1; //perchè la radice non si conta

    int albero = 0;
    while(albero<nFigli) { //per il sotto-albero
        nodi++;//incremento il numero dei nodi che sono aumentati
        figli[nodi].push_back(nodi);
        albero = albero + Creo_Tipo2(n[padre]); 
    }

    return n[padre]; //in definitava ho l'array ricostruito
}

void Stampo_Tipo2(int padre) {
    int i = 0;
    for (i; i<figli[padre].size();i++) {
        int figlio = figli[padre][i];
        Stampo_Tipo2(figlio);
    }
    out << n[padre] << " "; //non termino la riga
    
}

int main() {

    ifstram openFile("input1.txt", "r"); //per sola lettura
    ofstream openFile("output.txt","w"); //per sola scrittura  

    int tipoCod = 0; //per la codifica
    cin>>tipoCod); 

    if(tipoCod==1) {
        Creo_Tipo2(0);//per indice 0 dell'array
        cout<< "2 ";
        Stampo_Tipo2(0);
    } 
    cout<<endl;

}