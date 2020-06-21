/**
* user:  VR439370
* fname: FERRO
* lname: GIACOMO
* task:  online_budget_opt
* score: 0.0
* date:  2019-07-30 10:37:54.694615
*/
/**
 *  Template per soluzione in c++ per il problema online_budget_opt
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */
#include <iostream>
#include <algorithm>

using namespace std;

int n,B0,t;
int X[100000],Q[100000];
int J[100000];

int B[100000];


int main(){
    int i;
    cin>> n>>B0>>t;
    for(i=0;i<n;i++) cin>>X[i];
    for(i=0;i<n;i++) cin>>Q[i];

    J[n-1]=n-1;
    for(int i=n-2; i>=0; i--){
        if(Q[i]<Q[i+1]){
            Q[i]=Q[i+1];
            J[i]=J[i+1];
        }
    }

    int gain=0;
    int budget=B0;
    
    for(int i=0; i<n; i++){
        gain+=budget*Q[i];
        B[J[i]]+=budget;
        budget=X[i];
    }
    
    cout<<"\n";
    
    if(t==1)cout<<gain;
    //55
    cout <<endl;

}