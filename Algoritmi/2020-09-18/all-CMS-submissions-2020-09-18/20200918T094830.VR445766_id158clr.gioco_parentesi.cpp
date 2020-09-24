/**
* user:  VR445766_id158clr
* fname: MARCELLO
* lname: CILLUFFO
* task:  gioco_parentesi
* score: 5.0
* date:  2020-09-18 09:48:30.832852
*/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int primo=0;
int secondo=0;

int profondita(string parentesi){
    int maxprof=0;
    int prof=0;
    for(char& c : parentesi) {
        if(c=='('){
            prof++;
        }
        else if(c==')'){
            if(prof>maxprof){
                maxprof=prof;
            }
            prof--;
        }
    }

    return maxprof;
}

int contaparentesi(string parentesi,int prof){
    int count=0;
    int select=0;
    int countglobale=0;
    bool presoaperta=true;
    bool presochiusa=true;

    for(char& c : parentesi) {

        if(c=='('){
            count++;
            if(count==prof+1){
                if(presoaperta){
                    primo=countglobale;
                    presoaperta=false;
                }
                select++;
            }
        }
        else if(c==')'){
            count--; 
            if(count==prof){
                if(presochiusa){
                    secondo=countglobale;
                    presochiusa=false;
                }
                select++;
            }
        }
        countglobale++;
    }
    return select;
}

int main(){
    int N;
    int count=0,totale=0;
    bool preso=true;
    int countglobale=0;
    int inizio=0,fine=0;
    string parentesi;

    cin>>N>>parentesi;

    int massimo=profondita(parentesi);

    int vittoria=0;
    for(int i=0;i<massimo;i++){
        vittoria=contaparentesi(parentesi,i);

        //cout<<"livello "<<i<<" , conteggio: "<<vittoria<<endl;
        if((vittoria/2)%2!=0){
            cout<<"1"<<endl;
            cout<<primo<<" "<<secondo<<endl;
            preso=false;
            break;
            
        }

    }

    if(preso){
        cout<<"0"<<endl;
    }

    
}