/**
* user:  VR452400_id529gvn
* fname: RICCARDO
* lname: MARCHESINI
* task:  risparmio
* score: 23.0
* date:  2020-07-14 08:59:42.515627
*/
#include<iostream>
using namespace std;



// cambia stato lampadina alla posizione idx
void change_status_lamp(int a[], int idx){
    /*
    a: array
    idx: indice
    */
    if(a[idx]==0){//se lampadina spenta
            a[idx]=1;
    }
    else{
            a[idx]=0;
    }

    }


int main(){
//leggo da input
int N,M,op,idx,int_l,int_r;
cin>>N>>M;
//cout<<N<<M<<endl;
/* N: numero totale di luci inizialmente spente
   M: numero di operazioni da eseguire

   ******** ANNOTAZIONE***********
    0: luce spenta
    1: luce accesa
   */
   //creo vettore
   int A[N]={0}; //array di luci tutte spente
   //mi occupo della lettura
   for(int numero=0;numero<M;numero+=1){
    //leggo tipologia operazione
    cin>>op;
    if(op==1){//se operazione 1
        //leggi indice
        cin>>idx;
        //esegui inversione di stato lampada alla posizione idx
        // cout<<"valore lampadina alla posizone "<<idx<<" tramutata dallo stato "<<A[idx]<<endl;
        change_status_lamp(A, idx);
        //cout<< "allo stato " << A[idx]<<endl;
    }

    if(op==2){//esegui seconda operazione
        //leggo indice sx e dx
        cin>>int_l>>int_r;
        //cout<<"operazione 2 con indici "<<int_l<<" "<<int_r<<endl;
        //ESEGUO OPERAZIONE E RITORNO VALORE DI INTERVALLI
        //scorro array
        int count=0,p=int_l;
        bool on=false;
        for(p=int_l;p<=int_r;p++){
                if(A[p]==1 && on==false){//trovato prima corrispondenza
                    on=true;
                    count=count+1;
                }
                if(A[p]==0){
                    on=false;
                }

        }

        //cout<<"occorrenze "<< count<<endl;
        cout<<count<<endl;

    }
   }
return 0;
}
