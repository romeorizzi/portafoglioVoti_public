/**
* user:  VR439325
* fname: GILARDI
* lname: DANIELE
* task:  online_budget
* score: 0.0
* date:  2019-07-30 12:09:52.782836
*/
#include <cstdio>
#include <iostream>

using namespace std;

int vettore_guadagni[51];

int S;

int combinazioni_dopo(int cassa_agg,int indice){
    for(int i = cassa_agg;)
    if(vettore_guadagni[indice+1]==-1 && vettore_guadagni[indice]!=-1){
        return cassa; 
    }
    else if(vettore_guadagni[indice]==-1){
        return 0;
    }

    else{
        cassa_agg = cassa + vettore_guadagni[indice];

        for(int i=cassa_agg; i>0; i--){
            return (1 + combinazioni_dopo(i,indice);
        }
        if(cassa_agg==0) return (0 + combinazioni_dopo(cassa_agg,indice+1));
        else if(cassa_agg==1) return (1 + combinazioni_dopo(cassa_agg,indice+1));
        else if(cassa_agg==2) return (2 + combinazioni_dopo(cassa_agg,indice+1));
        else if(cassa_agg==3) return (3 + combinazioni_dopo(cassa_agg,indice+1));
        else if(cassa_agg==4) return (4 + combinazioni_dopo(cassa_agg,indice+1));
        else{
            return (combinazioni_dopo(cassa_agg,indice+1));
        } 
    }
}

int main(){

    int cassa;
    int periodi;
    scanf("%d%d",&periodi,&cassa);

    for(int i=0; i<50; i++){
        vettore_guadagni[i]=-1;
    }
    for(int i=0; i<periodi; i++){
        scanf("%d", &vettore_guadagni[i]);
    }

    
    int combinazioni_dopo(int cassa, int indice);

    S=1+cassa;
    
    S =  S + combinazioni_dopo(cassa+vettore_guadagni[0],0);
    
    printf("%d",S);

    return 0;
}
