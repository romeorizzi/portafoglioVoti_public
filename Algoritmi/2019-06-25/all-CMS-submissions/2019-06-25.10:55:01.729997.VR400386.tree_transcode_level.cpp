/**
* user:  VR400386
* fname: CORSINI
* lname: RAFFAELLO
* task:  tree_transcode_level
* score: 30.0
* date:  2019-06-25 10:55:01.729997
*/
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <vector>

int array[1000001];

int main(){

    FILE *fin  = fopen("input.txt","r");
    FILE *fout = fopen("output.txt","w");

    //freopen("input3.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    //int codice_albero = 0;
    //codice_albero << *fin;
    int codice_albero;
    //scanf("%d",&codice_albero);
    fscanf(fin,"%d",&codice_albero);
    //printf("Codice albero: %d\n\n",codice_albero);

    // Se il codice_albero è uguale a 1, vado con la prima codifica
    if(codice_albero == 1){
        // il secondo numero che leggo mi dice quanti saranno in totale
        // i nodi che leggo di quest'albero, lui compreso.
        // i nodi nell'array di destinazione saranno 2*lui.
        int nodo_radice;
        //scanf("%d",&nodo_radice);
        fscanf(fin,"%d",&nodo_radice);
        //int array[2*nodo_radice + 1];
        // so dove metto gli zeri.
        array[0] = 2;
        array[1] = 0;
        array[2*nodo_radice] = 0;
        // creo un nodo di indice che si muova lungo l'array.
        // mi servirà?
        int indice = 2;
        // creo una variabile dove salvare il grado attuale.
        // mi servirà?
        int grado_attuale = 1;
        // ora vado a scrivere quelli che sono i nodi
        // il concetto è che sapendo il numero dei figli leggendo so già
        // dove andrò a mettere il numero seguente
        // inoltre so il numero dei nodi totali quindi so anche dove
        // andrò a finire

        // Vettore che uso come stack dove carico i nodi
        std::vector<int> myvector_valore_nodo;
        myvector_valore_nodo.push_back(nodo_radice);
        //std::vector<int> myvector_grado_nodo;
        //myvector_grado_nodo.push_back(0);
        // Devo forse eliminare da sopra lo zero? O posso farne a meno?
        // Nel senso che potrei usare i vettori per tutto, senza trattare eccezionalmente la radice.

        // ciclo finché il vettore non è vuoto
        while (!myvector_valore_nodo.empty()){
            // leggo un numero nella lista
            int nodo_locale;
            //scanf("%d",&nodo_locale);
            fscanf(fin,"%d",&nodo_locale);
            //printf("Ho letto il nodo_locale %d.\n",nodo_locale);
            // abbasso il valore del padre/usr/bin/g++ -DEVAL -static -O2 -std=c++11 -o tree_transcode tree_transcode.cpp
            myvector_valore_nodo.back() -= nodo_locale;
            //printf("Ho abbassato il valore del padre a %d.\n",myvector_valore_nodo.back());
            // Se il numero è un 1, posso mettere nell'array due volte il suo grado e andare oltre./usr/bin/g++ -DEVAL -static -O2 -std=c++11 -o tree_transcode tree_transcode.cpp
            if(nodo_locale == 1){
                //printf("Il nodo locale ora vale 1.\n");
                array[indice] = grado_attuale;
                //printf("Ho salvato in array[%d] = %d\n",indice,grado_attuale);
                array[indice+1] = grado_attuale;
                //printf("Ho salvato in array[%d] = %d\n",indice+1,grado_attuale);
                indice += 2;
                //printf("indice è stato aumentato di due e ora vale %d\n",indice);
                // vado indietro e controllo se devo scalare di grado.
                while (!myvector_valore_nodo.empty() && myvector_valore_nodo.back() == 1){
                    //printf("L'ultimo nodo sullo stack vale 1 e lo elimino!\n");
                    myvector_valore_nodo.pop_back();
                    // Righe spostate da sotto, vediamo se funzionano
                    grado_attuale -= 1;
                    //printf("grado_attuale è stato diminuito di 1 e ora vale %d\n",grado_attuale);
                    // fine righe spostate
                    array[indice] = grado_attuale;
                    //printf("Ho salvato in array[%d] = %d\n",indice,grado_attuale);
                    indice++;
                    //printf("indice è stato aumentato di 1 e ora vale %d\n",indice);
                    //grado_attuale -= 1;
                    //printf("grado_attuale è stato diminuito di 1 e ora vale %d\n",grado_attuale);
                }
            }
            // altrimenti devo salvarmi i dati e proseguire
            else{
                // so che qua metto il mio grado
                //printf("Questo nodo NON vale 1!");
                array[indice] = grado_attuale;
                //printf("Ho salvato in array[%d] = %d\n",indice,grado_attuale);
                indice++;
                //printf("Ho salvato in array[%d] = %d\n",indice,grado_attuale);
                // salvo nel vettore il grado da recuperare
                myvector_valore_nodo.push_back(nodo_locale);
                //printf("Ho salvato in myvector_valore_nodo %d\n",nodo_locale);
                // incremento il grado
                grado_attuale++;
                //printf("Ho incrementato il grado attuale che ora vale %d\n",grado_attuale);

            }
        }

        for (int counter = 0; counter <= 2*nodo_radice; counter++){
            fprintf(fout,"%d ",array[counter]);
        }
        fprintf(fout,"\n");

    }
    // Se il codice_albero è uguale a 2, vado con la seconda codifica
    //else {


    //}


    return 0;
}