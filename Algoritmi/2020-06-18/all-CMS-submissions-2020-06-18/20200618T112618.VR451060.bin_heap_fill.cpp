/**
* user:  VR451060
* fname: CARON
* lname: NICHOLAS
* task:  bin_heap_fill
* score: 0.0
* date:  2020-06-18 11:26:18.511261
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;








long int isEanyGood(vector<long int> A,unordered_set<long int> e){
    for(long int index=1;index<A.size();index++){
        if(e.count(A[index])){
            if(A[index]<A[(index-1)/2]){
                return 0;
            }
        }
    }
    return 1;
}

vector<long int> Friarr(vector<long int> A,vector<long int> f){
    vector<long int> daCreare;
    vector<long int> nuovoArrayA;

    for(long int index=0;index<A.size();index++){
        if(f[index]==0){
            daCreare.push_back(-1);
             nuovoArrayA.push_back(A[index]);
        }
        else if(f[index]==1){
            daCreare.push_back(A[index]);
        }
    }

    sort(nuovoArrayA.begin(),nuovoArrayA.end());

    long int botval;
    for(long int index=0;index<daCreare.size();index++){
        if(daCreare[index]==-1){
            daCreare[index]=nuovoArrayA[0];
            nuovoArrayA.erase(nuovoArrayA.begin());
        }
    }
    return daCreare;
}







long int main(){
    vector<long int> A;
    vector<long int> e;
    vector<long int> f;
    unordered_set<long int> set;
    long int resE;

    long int g,problemaScelto;
    cin>>g;
    cin>>problemaScelto;
    long int val;
    for(long int index=0;index<g;index++){
        cin>>val;
        A.push_back(val);
    }

    for(long int index=0;index<g;index++){
        cin>>val;
        e.push_back(val);
    }

    for(long int index=0;index<g;index++){
        cin>>val;
        f.push_back(val);
    }

    for(long int index=0;index<g;index++){
        if(e[index]==1){
            set.insert(A[index]);
        }
    }

    if(problemaScelto==1){
        resE=isEanyGood(A,set);
        cout<<resE<<endl;
    }
    else if(problemaScelto==2){
        vector<long int> riarr=Friarr(A,f);
        resE=isEanyGood(riarr,set);
        cout<<resE<<endl;
    }
}
