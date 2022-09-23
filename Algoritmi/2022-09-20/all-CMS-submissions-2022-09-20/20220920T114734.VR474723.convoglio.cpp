/**
* user:  VR474723
* fname: MARCELLO
* lname: DE VINCENZI
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 11:47:34.617662
*/
#include <iostream>
#include <string.h>
using namespace std;


void stampa(int *,int dim);
int initialize(int **);
bool check(int **other,int *msg, int *nv, int *coppie);
void stampa_coppie(int *coppie,int **other);
int* copia(int*,int);

int N,M;


int main(){
   cin >>  N;
   cin >> M;
    
int **other=new int*[M];

   for(int i=0;i<(M);i++)
        other[i]=new int[2];

    for(int i=0;i<(M);i++){
        cin >> other[0][i];
        cin >> other[1][i];
    }
     int res=initialize(other);
    if(res==-1)
        cout << -1;


}


void stampa(int *v,int dim){
    cout << "\n";
    for(int i=0;i<dim;i++)
        cout << v[i] << " ";
    cout << "\n";
}

int initialize(int **other){
    int msg[N];
    for(int j=0;j<M;j++)
        msg[j]=-1;
    int **found=new int*[N];
    int nv[N];
    for(int j=0;j<N;j++)
        nv[j]=-1;
    int coppie[M];
    for(int n=0;n<M;n++)
        coppie[n]=-1;
    if(!check(other,msg,nv,coppie))
        return -1;
    return 0;

}

bool check(int **other,int *msg, int *nv, int *coppie){
    bool cont=false;
    int first,second;
    int max=N-1;
    for(int i=0;i<N;i++)
        if(nv[i]!=1 || msg[i]!=1)
            cont=true;
    if(cont==false){
        for(int i=0;i<M;i++){
            if(coppie[i]!=-1 && i<N){
                max-=1;
                if(max<0)
                    return false;
            }
        };
        stampa_coppie(coppie,other);
        return true;
    }
    else{
        for(int i=0;i<M;i++){
            first=other[0][i];
            second=other[1][i];
            if(coppie[i]!=1 && nv[second]!=1 && msg[first]!=1){
               
                int *anmsg=copia(msg,N);
                int *ancoppie=copia(coppie,M);
                int *annv=copia(nv,N);
                annv[second]=1;
                anmsg[first]=1;
                ancoppie[i]=1;

                if(check(other,anmsg,annv,ancoppie))
                    return true;
                free(annv);
                free(anmsg);
                free(ancoppie);
            }

        }
        return false;


    }


}

void stampa_coppie(int *coppie,int **other){
    int stampa=0;
    while(stampa!=N){
        for(int i=0;i<M;i++){
            if(other[0][i]==stampa && coppie[i]!=-1){
                
                cout << stampa << " " << other[1][i];
                cout << "\n";
                stampa++;
            }
        }
    }
}

int* copia(int *v,int dim){
    int *tmp=new int[dim];
    for(int i=0;i<dim;i++)
        tmp[i]=v[i];
    return tmp;
}