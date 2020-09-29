/**
* user:  VR445766_id158clr
* fname: MARCELLO
* lname: CILLUFFO
* task:  risparmio
* score: 23.0
* date:  2020-07-14 08:00:48.905105
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> premi(vector<int> vet,int index){
    if(vet[index]==0){
        vet[index]=1;
    }else{
        vet[index]=0;
    }
    /*
    cout<<"operazione 1, index: "<<index<<endl;
    for(int i=0;i<vet.size();i++){
        cout<<vet[i];
    }
    cout<<endl;*/
    return vet;
}

void inter(vector<int> vet, int inizio, int fine){
    int count=0;
    bool flag=false;
    bool start=true;
    for(int i=inizio;i<=fine;i++){
        if(vet[i]==0 && start){
            continue;
        }
        else if(vet[i]==1){
            flag=true;
            if(start){
                start=false;
            }
            if(i==fine){
                count++;
            }
        }
        else if(vet[i]==0){
            if(flag==true){
                count++;
                flag=false;
            }
        }
    }
    /*
    cout<<"operazione 2, index: "<<inizio<<".."<<fine<<endl;
    for(int i=0;i<vet.size();i++){
        cout<<vet[i];
    }*/
    cout<<count<<endl;
}

int main(){
    int N,M;

    cin>>N>>M;

    vector<int> luci;
    luci.resize(N,0);

    int op, spegne, a ,b;
    for(int i=0;i<M;i++){
        cin>>op;
        if(op==1){
            cin>>spegne;
            luci=premi(luci,spegne);
        }
        else{
            cin>>a>>b;
            inter(luci,a,b);
        }
    }
}