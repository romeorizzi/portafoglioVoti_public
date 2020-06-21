/**
* user:  VR439370
* fname: FERRO
* lname: GIACOMO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 09:11:51.869264
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <limits.h>
#include <string>

using namespace std;


const int MAXN = 1000000;

struct nodo{
    nodo *padre;
    int sum;
    int resto;
    int depth;
    int pos;
};

vector<int> sumArray;

int input_type;
int n;
int valori[MAXN];

int main(){

    cin >> input_type;
    cin >> n; // lunghezza albero

    nodo root;  
    nodo * ptr = &root;


    int readValue;
    int treeType=input_type;
    root.sum = INT_MAX;
    root.resto = INT_MAX;
    root.depth = -1;

    //leggo i valori
    int i;
    for(i = 0; i < n; i++){
       scanf("%d", &valori[i]);
    }

    cout << 3-input_type <<endl; //print del tipo risultato intanto..

    //calcolo la ora conversione da 1 a 2 e viceversa
    puts("INIZIO");
    int maxPos=0;
    i=0;
    for(i = 0; i < n; i++){
        printf("%d ",valori[i]);
    }


    for(i=0; i<n; i++){
        readValue=valori[i];
        if(treeType==1){
            nodo * newNodo = new nodo();
            newNodo->padre=ptr;
            newNodo->depth=ptr->depth+1;
            newNodo->resto = readValue;
            newNodo->sum=readValue;
            ptr=newNodo;    
            sumArray.push_back(ptr->depth);
            while(ptr->resto==1){
                sumArray.push_back(ptr->depth);
                ptr->padre->resto-=ptr->sum;
                ptr = ptr->padre;
            }
        }
        else{
            if(ptr->depth == readValue){
                ptr->sum=ptr->sum +1;
                ptr->padre->sum +=ptr->sum;
                sumArray[ptr->pos]+=ptr->sum;
                ptr=ptr->padre;
            }
            else{
                nodo * newNodo = new nodo();
                newNodo -> padre = ptr;
                newNodo -> pos = maxPos;
                sumArray.push_back(0);
                maxPos++;
                newNodo->depth=readValue;
                ptr=newNodo;
            }
        }
        if(ptr == &root) break;
    }

    for(i=0; i<sumArray.size(); i++){
        cout << sumArray[i];
    }


    return 0;
}