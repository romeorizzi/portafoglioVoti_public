/**
* user:  VR451060
* fname: CARON
* lname: NICHOLAS
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 11:13:08.313337
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;








int isEanyGood(vector<int> A,unordered_set<int> e){
    for(int index=1;index<A.size();index++){
        if(e.count(A[index])){
            if(A[index]<A[(index-1)/2]){
                return 0;
            }
        }
    }
    return 1;
}

vector<int> Friarr(vector<int> A,vector<int> f){
    vector<int> daCreare;
    vector<int> nuovoArrayA;

    for(int index=0;index<A.size();index++){
        if(f[index]==0){
            daCreare.push_back(-1);
             nuovoArrayA.push_back(A[index]);
        }
        else if(f[index]==1){
            daCreare.push_back(A[index]);
        }
    }

    sort(nuovoArrayA.begin(),nuovoArrayA.end());

    int botval;
    for(int index=0;index<daCreare.size();index++){
        if(daCreare[index]==-1){
            daCreare[index]=nuovoArrayA[0];
            nuovoArrayA.erase(nuovoArrayA.begin());
        }
    }
    return daCreare;
}







int main(){
    vector<int> A;
    vector<int> e;
    vector<int> f;
    unordered_set<int> set;
    int resE;

    int g,problemaScelto;
    cin>>g;
    cin>>problemaScelto;
    int val;
    for(int index=0;index<g;index++){
        cin>>val;
        A.push_back(val);
    }

    for(int index=0;index<g;index++){
        cin>>val;
        e.push_back(val);
    }

    for(int index=0;index<g;index++){
        cin>>val;
        f.push_back(val);
    }

    for(int index=0;index<g;index++){
        if(e[index]==1){
            set.insert(A[index]);
        }
    }

    if(problemaScelto==1){
        resE=isEanyGood(A,set);
        cout<<resE<<endl;
    }
    else if(problemaScelto==2){
        vector<int> riarr=Friarr(A,f);
        resE=isEanyGood(riarr,set);
        cout<<resE<<endl;
    }
}
