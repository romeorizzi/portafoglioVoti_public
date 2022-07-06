/**
* user:  VR472108
* fname: DAVIDE
* lname: CAMPONOGARA
* task:  A_seq
* score: 0.0
* date:  2022-06-29 13:31:15.434568
*/
/*
Davide Camponogara VR472108
*/

#include <stdio.h>
#include <vector>
#include <iostream>

#define NMAX 1000

using namespace std;

struct elem{
    int index;
    int prec;
    int elem_a_seguire;
};

struct position{
    int row;
    int column;
};


int GOAL;
int N_ELEMENTS;
vector<int> seq;
vector<int> decrescente;
vector<vector<elem>> list_decrescente;
vector<vector<elem>> list_crescente;
//Questo vettore ci permette di fare una correlazione tra posizione nella nostra list_decrescente e l'indice in seq senza doverlo cercare in tutta la lista
position vettore_recupero_d[NMAX];
//Questo vettore ci permette di fare una correlazione tra posizione nella nostra list_crescente e l'indice in seq senza doverlo cercare in tutta la lista
position vettore_recupero_c[NMAX];

int trova_quanti_successivi_decrescenti(int index){
    int counter = 0;
    if(index == seq.size()-1){
        return 0;
    }
    for(int i=index;i<seq.size();i++){
        if(seq[i] < seq[index]){
            counter++;
        }
    }
    return counter;
}

void fill_descrescente(){
    for(int i=0;i< seq.size();i++){
        decrescente[i]= trova_quanti_successivi_decrescenti(i);
    }
}


void build_decrescente_list(){
    vector<elem> newVect;
    elem newElemento;
    newElemento.index = 0;
    newElemento.prec=-1;
    newElemento.elem_a_seguire=1;
    position newPos;
    newPos.row=0;
    newPos.column=0;
    vettore_recupero_d[0]=newPos;
    newVect.push_back(newElemento);
    list_decrescente.push_back(newVect);
    for(int i=1;i<seq.size();i++){
        bool found = false;
        for(int j=0;j<list_decrescente.size();j++){
            if(list_decrescente[j].size()!= 0){
                if(seq[(list_decrescente[j][list_decrescente[j].size()-1]).index] <= seq[i]){
                    elem newElemento;
                    newElemento.index = i;
                    if(j==0){
                        newElemento.prec = -1;
                    }
                    else{
                        newElemento.prec = (list_decrescente[j-1][list_decrescente[j-1].size()-1]).index;
                    }
                    newElemento.elem_a_seguire=1;
                    list_decrescente[j].push_back(newElemento);
                    position newPos;
                    newPos.row=list_decrescente[j].size()-1;
                    newPos.column=j;
                    vettore_recupero_d[i]=newPos;
                    found=true;
                    break;
                }
            }
        }
        if(found==false){
            vector<elem> newVect;
            elem newElemento;
            newElemento.index = i;
            //il precedente è l'elemento che non gli ha permesso di posizionarsi nella colonna precedente
            newElemento.prec = (list_decrescente[list_decrescente.size()-1][list_decrescente[list_decrescente.size()-1].size()-1]).index;
            newVect.push_back(newElemento);
            position newPos;
            newPos.row = 0;
            newPos.column= list_decrescente.size();
            vettore_recupero_d[i]=newPos;
            list_decrescente.push_back(newVect);
        }
    }
}

void build_crescente_list(){
    vector<elem> newVect;
    elem newElemento;
    newElemento.index = 0;
    newElemento.prec=-1;
    position newPos;
    newPos.row=0;
    newPos.column=0;
    vettore_recupero_c[0]=newPos;
    newVect.push_back(newElemento);
    list_crescente.push_back(newVect);
    for(int i=1;i< seq.size();i++){
        bool found = false;
        for(int j=0;j<list_crescente.size();j++){
            if(list_crescente[j].size()!= 0){
                if(seq[(list_crescente[j][list_crescente[j].size()-1]).index] >= seq[i]){
                    elem newElemento;
                    newElemento.index = i;
                    if(j==0){
                        newElemento.prec = -1;
                    }
                    else{
                        newElemento.prec = (list_crescente[j-1][list_crescente[j-1].size()-1]).index;
                    }
                    list_crescente[j].push_back(newElemento);
                    //se possedessi un counter della lunghezza massima della sequenza che lo sussegue dovrei aggiornare i contatori ora!
                    position newPos;
                    newPos.row=list_crescente[j].size()-1;
                    newPos.column=j;
                    vettore_recupero_c[i]=newPos;
                    found=true;
                    break;
                }
            }
        }
        if(found==false){
            vector<elem> newVect;
            elem newElemento;
            newElemento.index = i;
            //il precedente è l'elemento che non gli ha permesso di posizionarsi nella colonna precedente
            newElemento.prec = (list_crescente[list_crescente.size()-1][list_crescente[list_crescente.size()-1].size()-1]).index;
            newVect.push_back(newElemento);
            position newPos;
            newPos.row = 0;
            newPos.column= list_crescente.size();
            vettore_recupero_c[i]=newPos;
            list_crescente.push_back(newVect);
        }
    }
}

int find_length_cres(int i){
    int indexPrec=(list_crescente[vettore_recupero_c[i].column][vettore_recupero_c[i].row]).prec;
    int counter=1;
    while(indexPrec!=-1){
        indexPrec=(list_crescente[vettore_recupero_c[indexPrec].column][vettore_recupero_c[indexPrec].row]).prec;
        counter++;
    }
    return counter;
}

int find_length_decr(int index,int counter=0){
    int indice=index;
    int maximum=1;
    int tryMax =1;
    if((vettore_recupero_d[index].column+1)>=list_decrescente.size()){
        return counter+1;
    }
    for(int i=0;i<list_decrescente[vettore_recupero_d[index].column+1].size();i++){

        if(list_decrescente[vettore_recupero_d[index].column+1][i].prec==indice){
            tryMax = find_length_decr((list_decrescente[vettore_recupero_d[index].column+1][i]).index, counter+1 );
            if(tryMax>maximum){
                maximum=tryMax;
            }
        }
    }
    return maximum;
}


int build_list_together(int index){
    return find_length_cres(index)+ find_length_decr(index,0)-1;
/*
    for(int i=0;i<N_ELEMENTS;i++){
        int indice = i;
        int counter = 1;
        elem a = list_crescente[vettore_recupero_c[i].column][vettore_recupero_c[i].row]);
        for(int k=0;k<list_crescente[vettore_recupero_c[i].column+1].size();k++){
            if(list_crescente[j][k].prec=indice){
                indice = list_crescente[j][k].index;
                counter++;
            }
        }
    }
    */
}




int main(){
    freopen("input.txt","r",stdin);

    cin >> GOAL;
    cin >> N_ELEMENTS;
    int x;
    for(int i=0;i<N_ELEMENTS;i++){
        cin >> x;
        seq.push_back(x);
        decrescente.push_back(0);
        printf("%d",x);
    }
    fill_descrescente();
    build_decrescente_list();
    printf("\n");
    for(int i=0;i< list_decrescente.size();i++){
        for(int j=0;j< list_decrescente[i].size();j++){
            printf("%d",(list_decrescente[i][j]).prec);
        }
        printf("\n");
    }

    printf("\n");
    for(int i=0;i< N_ELEMENTS;i++){
        printf("%d %d\n",vettore_recupero_d[i].row,vettore_recupero_d[i].column);
    }
    //A questo punto posso dire che la lunghezza strettamente decrescente più lunga è lunga esattamente lista_decrescente.size()!
    printf("lunghezza massima descrescente: %d", list_decrescente.size());
    build_crescente_list();
    printf("\n");
    for(int i=0;i< list_crescente.size();i++){
        for(int j=0;j< list_crescente[i].size();j++){
            printf("%d",(list_crescente[i][j]).prec);
        }
        printf("\n");
    }

    for(int i=0;i< N_ELEMENTS;i++){
        printf("%d %d\n",vettore_recupero_c[i].row,vettore_recupero_c[i].column);
    }
    //A questo punto posso dire che la lunghezza strettamente crescente più lunga è lunga esattamente lista_crescente.size()!
    printf("lunghezza massima crescente: %d", list_crescente.size());
    printf("\n");
    //A questo punto ho tutte le possibili sequenze, come possiamo fare ad unirle? e quindi così trovare la A_sequenza?
    int maximum=-1;
    for(int i=0;i< N_ELEMENTS;i++){
        int a=build_list_together(i);
        if(a > maximum){
            maximum=a;
        }
    }
    freopen("output.txt","w",stdout);
    cout<< maximum<<endl;

    return 0;

}
