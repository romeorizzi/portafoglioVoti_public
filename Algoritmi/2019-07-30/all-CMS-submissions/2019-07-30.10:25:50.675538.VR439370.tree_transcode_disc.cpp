/**
* user:  VR439370
* fname: FERRO
* lname: GIACOMO
* task:  tree_transcode_disc
* score: 40.0
* date:  2019-07-30 10:25:50.675538
*/
/**
 *  Template per soluzione in c++ per il problema tree_transcode_disc
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */


#include <iostream>
#include <vector>

using namespace std;

vector<int> figli[1000000];
int numeroFigli[1000000];
int numeroNodi=0;

int costruisci_Tipo1(int nodo){
    int numFigli;
    cin>>numFigli;
    numeroFigli[nodo] = numFigli;   
    numFigli = numFigli -1; 

    int sottoalbero=0;
    while(sottoalbero<  numFigli){
        numeroNodi++;
        figli[nodo].push_back(numeroNodi);
        sottoalbero=sottoalbero+costruisci_Tipo1(numeroNodi);
    }
    return  numeroFigli[nodo];

}

void stampa_Tipo2(int nodo){

    int i=0;
    for(i=0;i<figli[nodo].size();i++){
        int figlio=figli[nodo][i];
        stampa_Tipo2(figlio);
    }
    cout<<  numeroFigli[nodo]<<" ";

}

void stampa_Tipo1(int nodo){
    int i=0;
    cout<<numeroFigli[nodo]<<" ";
    for(i=figli[nodo].size()-1; i>=0; i--){ 
        int figlio = figli[nodo][i];
        stampa_Tipo1(figlio);   
    }

}

int costruisci_Tipo2(){
    int i,j;
    vector<int>stack;
    int numFigli;

    while(cin >> numFigli){

        numeroNodi=numeroNodi+1;
        numeroFigli[numeroNodi]=numFigli;
        if(numFigli>1){
            numFigli--;
            while(numFigli>0){
                int figlio=stack.back();
                stack.pop_back();
                numFigli-=numeroFigli[figlio];
                figli[numeroNodi].push_back(figlio);
            }
        }

        stack.push_back(numeroNodi);
    }
    return 0;
}


int main(){

    int tipo;
    cin>> tipo;
    if(tipo==1){

        costruisci_Tipo1(0);
        cout<<"2 ";
        stampa_Tipo2(0);
    }
    else if(tipo==2){
        int radice=costruisci_Tipo2();
        cout<< "1 ";
        stampa_Tipo1(radice);
    }   
    cout<<endl;
}