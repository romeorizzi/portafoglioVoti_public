/**
* user:  VR440462
* fname: GOBBI
* lname: FRANCESCO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 10:50:33.631160
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    printf("ciao\n");
    int nani, azioni;

    //ridireziono gli standar input e output
    freopen("input3.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    //leggo i nani
    cin >> nani;
    cin >> azioni;
    
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
       
            int range = vet_azioni[2] - vet_azioni[1] ; //range di valori che ho, quindi quanti valori ho tra le due altezze         

            vector<int> posizioni2; //vettore delle posizioni dei nani
            for(int j=0; j<nani; j++) {
                if(vet_nani[j]>=vet_azioni[1] && vet_nani[j]<=vet_azioni[2]) {
                    posizioni2.push_back(j+1); //mi salvo la posizione                
                }
                else {
                    posizioni2.push_back(-1);//per dire che non c'è nulla
                }
            }//fine for

            //count << posizioni2.size() <<endl;    
            int i = 0;
            int j = 1;
            while((range)>0) {
                if(posizioni2[i]!=-1 && posizioni2[i+1]!=-1) range--; //decremento il range
                if (posizioni2[i]!=-1 && posizioni2[i+1]==-1 && range>0) {
                    cout << "NO" << endl;
                    break;
                }
                i++; //incremento posizione vettore
            }

            //if(count == range) cout << "YES" << endl;
            if(range==0) cout << "YES" << endl;
            
    
        }//fine if azione 2
        azioni--; //decremento le azioni da fare

    }//fine while

       
} //fine main
