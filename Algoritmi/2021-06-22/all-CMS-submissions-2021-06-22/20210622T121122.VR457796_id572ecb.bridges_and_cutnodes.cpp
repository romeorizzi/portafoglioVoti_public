/**
* user:  VR457796_id572ecb
* fname: FRANCESCO
* lname: CECCONELLO
* task:  bridges_and_cutnodes
* score: 0.0
* date:  2021-06-22 12:11:22.733498
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAXN = 10000;
int type;
int num_verteces;
int num_edges;
int ng[MAXN][MAXN];

int check_connection_removing(int u){
    int sum = -1;
    for(int i=0;i<num_verteces;i++){
        if(ng[u][i]!=NULL){
            sum += ng[u][i];
        }
    }
    for(int i=0;i<num_edges;i++){
        if(ng[i][u]!=NULL){
            sum += ng[u][i];
        }
    }
    if(sum<0) return 0;
    return 1;
    
  }


int main(){
 cin >> type;
 cin >> num_verteces;
 cin >> num_edges;
 
 for(int i=0;i<num_edges;i++) {
   int u,v;
   cin >> u >> v;
   ng[u][v]=1;
 }
 if(type==1){
    for(int i=0;i<num_verteces-1;i++){
        if(check_connection_removing(i)==0){
            cout << 1<<endl;
        }
        else cout <<0<<endl;
           
    }
}
return 0;
}