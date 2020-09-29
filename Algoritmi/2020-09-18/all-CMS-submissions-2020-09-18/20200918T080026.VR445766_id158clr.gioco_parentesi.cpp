/**
* user:  VR445766_id158clr
* fname: MARCELLO
* lname: CILLUFFO
* task:  gioco_parentesi
* score: 5.0
* date:  2020-09-18 08:00:26.281754
*/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
    int N;
    int count=0,totale=0;
    bool preso=true;
    int countglobale=0;
    int inizio=0,fine=0;
    string parentesi;

    cin>>N>>parentesi;

    for(char& c : parentesi) {
        if(c=='('){
            count++;
        }
        else if(c==')'){
            count--;
        }

        if(count==0){
            totale++;
            if(count==0 && preso){
                preso=false;
                fine=countglobale;

            }
        } 

        countglobale++;
    }

    if(totale%2==0){
        cout<<0;
    }  
    else{
        cout<<1<<endl;
        cout<<inizio<<" "<<fine;
    }
}