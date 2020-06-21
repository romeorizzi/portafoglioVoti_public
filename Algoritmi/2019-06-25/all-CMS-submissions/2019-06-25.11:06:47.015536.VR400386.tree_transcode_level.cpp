/**
* user:  VR400386
* fname: CORSINI
* lname: RAFFAELLO
* task:  tree_transcode_level
* score: 30.0
* date:  2019-06-25 11:06:47.015536
*/
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <vector>

int array[1000001];

int main(){

    FILE *fin  = fopen("input.txt","r");

    int codice_albero;
    fscanf(fin,"%d",&codice_albero);

    // Se il codice_albero è uguale a 1, vado con la prima codifica
    if(codice_albero == 1){
        int nodo_radice;
        fscanf(fin,"%d",&nodo_radice);
        array[0] = 2;
        array[1] = 0;
        array[2*nodo_radice] = 0;
        int indice = 2;
        int grado_attuale = 1;
        // Vettore che uso come stack dove carico i nodi
        std::vector<int> myvector_valore_nodo;
        myvector_valore_nodo.push_back(nodo_radice);
        // ciclo finché il vettore non è vuoto
        while (!myvector_valore_nodo.empty()){
            // leggo un numero nella lista
            int nodo_locale;
            fscanf(fin,"%d",&nodo_locale);
            myvector_valore_nodo.back() -= nodo_locale;
            // Se il numero è un 1, posso mettere nell'array due volte il suo grado e andare oltre./usr/bin/g++ -DEVAL -static -O2 -std=c++11 -o tree_transcode tree_transcode.cpp
            
            

            if(nodo_locale == 1){
                array[indice] = grado_attuale;
                array[indice+1] = grado_attuale;
                indice += 2;
                // vado indietro e controllo se devo scalare di grado.
                while (!myvector_valore_nodo.empty() && myvector_valore_nodo.back() == 1){
                    myvector_valore_nodo.pop_back();
                    grado_attuale -= 1;
                    array[indice] = grado_attuale;
                    indice++;
                }
            }
            // altrimenti devo salvarmi i dati e proseguire
            else{
                array[indice] = grado_attuale;
                indice++;
                // salvo nel vettore il grado da recuperare
                myvector_valore_nodo.push_back(nodo_locale);
                // incremento il grado
                grado_attuale++;
            }
        }

        fclose(fin);
        FILE *fout = fopen("output.txt","w");
        for (int counter = 0; counter <= 2*nodo_radice; counter++){
            fprintf(fout,"%d ",array[counter]);
        }
        fprintf(fout,"\n");
        fclose(fout);

    }
    // Se il codice_albero è uguale a 2, vado con la seconda codifica
    else {


    }


    return 0;
}