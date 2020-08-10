/**
* user:  VR445766_id158clr
* fname: MARCELLO
* lname: CILLUFFO
* task:  gioco_triangolo
* score: 0.0
* date:  2020-07-14 10:46:30.173561
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t,layer;

    cin>>t>>layer;

    vector<int> trian;
    trian.resize(layer,0);

   int n;
   int somma=0;
    for(int i=0;i<layer;i++){
        cin>>n;
        somma+=n;
        trian[i]=n;
    }

    char a;
    int b,c,d;
    cin>>a>>b>>c>>d;

    if(somma%2==0){
        cout<<0<<endl;

    }
    else{
        cout<<1<<endl;
        int ver;
        for(int i=0;i<layer;i++){
            if(trian[i]>1){
                cout<<"T "<<i+1<<" "<<trian[i]-1<<" "<<0<<endl;
            }
        }
    }
}