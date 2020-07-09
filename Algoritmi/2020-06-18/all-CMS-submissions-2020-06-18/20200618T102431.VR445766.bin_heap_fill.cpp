/**
* user:  VR445766
* fname: CILLUFFO
* lname: MARCELLO
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 10:24:31.010172
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int ebuono(vector<int> A,unordered_set<int> e){
    for(int i=1;i<A.size();i++){
        if(e.count(A[i])){
            if(A[i]<A[(i-1)/2]){
                return 0;
            }
        }
    }
    return 1;
}

vector<int> Friarr(vector<int> A,vector<int> f){
    vector<int> nuovo;
    vector<int> newA;

    for(int i=0;i<A.size();i++){
        if(f[i]==0){
            nuovo.push_back(-1);
             newA.push_back(A[i]);
        }
        else if(f[i]==1){
            nuovo.push_back(A[i]);
        }
    }

    sort(newA.begin(),newA.end());

    int botval;
    for(int i=0;i<nuovo.size();i++){
        if(nuovo[i]==-1){
            nuovo[i]=newA[0];
            newA.erase(newA.begin());
        }
    }
    return nuovo;
}

int main(){
    vector<int> A;
    vector<int> e;
    vector<int> f;
    unordered_set<int> set;
    int resE;

    int n,prob;
    cin>>n;
    cin>>prob;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        A.push_back(val);
    }

    for(int i=0;i<n;i++){
        cin>>val;
        e.push_back(val);
    }

    for(int i=0;i<n;i++){
        cin>>val;
        f.push_back(val);
    }

    for(int i=0;i<n;i++){
        if(e[i]==1){
            set.insert(A[i]);
        }
    }

    if(prob==1){
        resE=ebuono(A,set);
        cout<<resE<<endl;
    }
    else if(prob==2){
        vector<int> riarr=Friarr(A,f);
        resE=ebuono(riarr,set);
        cout<<resE<<endl;
    }
}