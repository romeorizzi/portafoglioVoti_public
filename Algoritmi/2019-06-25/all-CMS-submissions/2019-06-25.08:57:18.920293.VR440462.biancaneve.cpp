/**
* user:  VR440462
* fname: GOBBI
* lname: FRANCESCO
* task:  biancaneve
* score: 6.0
* date:  2019-06-25 08:57:18.920293
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    printf("ciao\n");
    int nani, azioni;

    //ridireziono gli standar input e output
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    //leggo i nani
    cin >> nani;
    //cout << nani << endl;
    cin >> azioni;
    //cout << azioni << endl;
    
    vector<int> vet_nani ; //vettore per i nani
    
    //inserisco i nani
    for (int j = 0; j<nani; j++) {
        int x; 
        cin >> x; //leggo un valVR440462ore 
        vet_nani.push_back(x);
    }

    /*for(int i=0; i<nani; i++) {
        printf("%d\n", vet_nani[i]);
    }*/
    

    //printf("%d\n", azioni);

    while(azioni>0) {

        vector<int> vet_azioni ; //vettore per le azioni
        for (int j = 0; j<3; j++) {
        int x; 
        cin >> x; //leggo un'azione e la salvo in un vettore 
        vet_azioni.push_back(x);
        }
        
        int azione = vet_azioni[0];
        //printf("Azione %d\n", azione);
        if(azione==1) { //faccio il sort tra i due
            int x = vet_azioni[1] - 1;
            int y = vet_azioni[2] - 1;
            //printf("posizione %d %d \n", x, y); 
            int tmp = vet_nani[y]; //valore temporaneo            
            vet_nani[y] = vet_nani[x];
            vet_nani[x] = tmp;
        }
        
        /*for(int i=0; i<nani; i++) {
                printf("%d ", vet_nani[i]);
            }
        puts("");*/
    
        if(azione==2) {//azione di controllo
            //printf("Azione 2\n");
            //trovo il massimo ed il minimo
            int max_val = 0;            
            for (int i=(vet_azioni[1] - 1); i<=(vet_azioni[2] - 1); i++ ) {
                if(max_val<vet_nani[i]) max_val = vet_nani[i];
            }

            int min_val = 100000;
            for(int i=(vet_azioni[1] - 1); i<=(vet_azioni[2] - 1); i++ ) {
                if(min_val>vet_nani[i]) min_val = vet_nani[i];
            }
            vector<int> posizioni ; //vettore delle posizioni
            int range = max_val - min_val +1; 
            int num = min_val;
            //creo un vettore di riferimento per vedere le posizione contigue
            for (int j = 0; j<range; j++) {
                posizioni.push_back(num);
                num++;
           }

            int count = 0; //contatore per il check
            for(int j=0; j<range; j++) {
                for (int i=(vet_azioni[1] - 1); i<=(vet_azioni[2] - 1); i++ ) {
                    if (posizioni[j] == vet_nani[i]) count++;
                }
            }
            
            if(count == range) cout << "YES" << endl;
            else cout << "NO" << endl;
            
    
        }//fine if azione 2
        azioni--; //decremento le azioni da fare

    }//fine while

       
} //fine main
