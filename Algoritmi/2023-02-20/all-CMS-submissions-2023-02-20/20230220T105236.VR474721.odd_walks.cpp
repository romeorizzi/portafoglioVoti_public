/**
* user:  VR474721
* fname: RICCARDO
* lname: BOLOGNA
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 10:52:36.103553
*/
#include<iostream>
#include<string>
using namespace std;

int archi[100000][2];
int costo[100000];

int walk(int tail,int arr, int dim,int tot){
    if(tail == arr && tot>0 )
        return 0;
    else if(tail!=arr && tot>20)
        return 0;
    else{
        int minimo = 30000;
        for(int i=0;i<dim;i++){
            int costo_tmp=90000;
            int tot_tmp=tot;
            if(archi[i][0] == tail){
                tot_tmp = tot_tmp+2;
                costo_tmp = costo[i]+walk(archi[i][1],arr,dim,tot_tmp);
                 
            }
            minimo = min(costo_tmp,minimo);
        }
        return minimo;
    }
}

int main(){
    int N,M,PL,PC;
    cin>>N;
    cin>>M;
    cin>>PL;
    cin>>PC;

    for(int i=0;i<M;i++){
        cin>>archi[i][0];
        cin>>archi[i][1];
        cin>>costo[i];
    }
    /*
    for(int i=0;i<M;i++){
        cout<<archi[i][0]<<archi[i][1]<<costo[i]<<"\n";
    }
    */
    for(int i=0;i<N;i++)
        cout<<walk(0,i,M,0)<<" ";



}
