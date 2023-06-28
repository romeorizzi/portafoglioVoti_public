/**
* user:  VR474721
* fname: RICCARDO
* lname: BOLOGNA
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 13:11:30.031849
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int archi[100000][2];
int costo[100000];
int PC;
vector<int> totale;
vector<int> pari;
vector<int> dispari;
vector<int> boh;
/*
int walk(int tail,int arr, int dim,int tot,int costoo){
    if(tail == arr && tot>0 ){
        cout<<costoo<<" ";
        return 0;
    }
    else if(tail!=arr && tot>20)
        return 0;
    else{
        int minimo = 30000;
        for(int i=0;i<dim;i++){
            int costo_tmp=90000;
            int tot_tmp=tot;
            if(archi[i][0] == tail){
                tot_tmp = tot_tmp+2;
                costo_tmp = costo[i]+costoo;
                walk(archi[i][1],arr,dim,tot_tmp,costo_tmp);
                 
            }
            minimo = min(costo_tmp,minimo);
        }
        return minimo;
    }
}
*/
/*
void prova2(int tail,int arr,int dim,int tot,int costoo){
    if(tail == arr && costoo>0 ){
        if(PC==2)
            totale.push_back(costoo);
        else if(PC==1 && costoo%2!=0)
            dispari.push_back(costoo);
        else if(PC==0 && costoo%2==0)
            pari.push_back(costoo);
    }
    else if(tail!=arr && tot>20){
        return;
    }
        
    else{
        int minimo = 30000;
        int costo_tmp=costoo;
        for(int i=0;i<dim;i++){
            costo_tmp=costoo;
            int tot_tmp=tot;
            if(archi[i][0] == tail){
                tot_tmp = tot_tmp+2;
                costo_tmp = costo[i]+costo_tmp;
                prova2(archi[i][1],arr,dim,tot_tmp,costo_tmp);
                 
            }
            
            
        }
        
        
    }


}
*/

void prova3(int tail,int arr,int dim,int tot,int costoo){
    if(tail == arr && costoo>0 ){
        totale.push_back(costoo);
    }
    else if(tail!=arr && tot>10){
        return;
    }
        
    else{
        int minimo = 30000;
        int costo_tmp=costoo;
        for(int i=0;i<dim;i++){
            costo_tmp=costoo;
            int tot_tmp=tot;
            if(archi[i][0] == tail){
                tot_tmp = tot_tmp+2;
                costo_tmp = costo[i]+costo_tmp;
                prova3(archi[i][1],arr,dim,tot_tmp,costo_tmp);
                 
            }
            
            
        }
        
        
    }


}


void clean(){
    for(int i=0;i<totale.size();i++)
        totale.erase(begin(totale));
}
int main(){
    int N,M,PL;
    cin>>N;
    cin>>M;
    cin>>PL;
    cin>>PC;

    for(int i=0;i<M;i++){
        cin>>archi[i][0];
        cin>>archi[i][1];
        cin>>costo[i];
    }
    
    for(int i=0;i<N;i++){
        
        totale = boh;
        
        pari = boh;
        dispari = boh;
        prova3(0,i,M,0,0);
        //cout<<"\n"<<totale.size()<<"\n\n\n\n";
        if(PC==2){

            int minimo = totale[0];
            for(int j=0;j<totale.size();j++){
                //cout<<totale[j]<<" ";
            
                if(totale[j]<minimo)
                    minimo=totale[j];
        
            //cout<<minimo<<" ";
            }
            cout<<minimo<<" ";
    }
    else if(PC==1){
        int minimo = dispari[0];
            for(int j=0;j<dispari.size();j++){
                cout<<dispari[j]<<" ";
            
            if(dispari[j]<minimo)
                minimo=dispari[j];
        
            cout<<minimo<<" ";
            }

    }
        else if(PC==0){

        int minimo = pari[0];
            for(int j=0;j<pari.size();j++){
                cout<<pari[j]<<" ";
            
            if(pari[j]<minimo)
                minimo=pari[j];
        
            cout<<minimo<<" ";
            }

    }

    
    /*
    prova2(0,0,M,0,0);

    
    int minimo = totale[0];
    for(int j=0;j<totale.size();j++){
        cout<<totale[j]<<" ";
            
        if(totale[j]<minimo)
            minimo=totale[j];
        
        cout<<"\n"<<minimo;
    }

    */
}}
