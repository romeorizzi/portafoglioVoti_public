/**
* user:  VR445639EXAM
* fname: RUSSO
* lname: ROSA
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 10:58:26.253774
*/
#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


int eBuono(vector<int> A, unordered_set<int> temp){
    for(int i = 1; i<A.size(); i++){
        if(temp.count(A[i])){
            if(A[i] < A[(i-1)/2]){ // A è E-Buono se A[i] >= A[(i-1)/2]
                return 0;
            }
        }
    }
    return 1;
}

vector<int> fStabile(vector<int> A, vector<int> F){ // riallocamento di A F-Stabile
    vector<int> newVector;
    vector<int> riallocA;

    for(int i = 0; i<A.size(); i++){
        if(F[i] == 0){
            newVector.push_back(-1);
             riallocA.push_back(A[i]);
        }
        else{
            if(F[i] == 1){
                newVector.push_back(A[i]);
            }
        }
    }

    sort(riallocA.begin(), riallocA.end());

    int botval;

    for(int i = 0; i < newVector.size(); i++){
        if(newVector[i] == -1){
            newVector[i] = riallocA[0];
            riallocA.erase(riallocA.begin());
        }
    }

    return newVector;
}

int main(){

    vector<int> A;
    vector<int> E; // figli/sottoinsieme di A
    vector<int> F; // posizioni fisse
    unordered_set<int> temp;

    int n, t;
    int x, e, f;

    cin >> n;
    assert(n >= 0);
    assert(n <= 1000000);

    cin >> t; //obiettivo da conseguire

    for(int i = 0; i < n; i++){ // collocamento iniziale di A {0, ..., n-1}
        cin >> x;
        assert(x >= 0);
        assert(x <= 10000000);
        A.push_back(x);
    }

    for(int i = 0; i < n; i++){
        cin >> e; // {0, 1}
        E.push_back(e);
    }

    for(int i = 0; i < n; i++){
        cin >> f; // {0, 1}
        F.push_back(f);
    }

    for(int i = 0; i < n; i++){
        if(E[i] == 1){
            temp.insert(A[i]);
        }
    }

    if(t == 1){ // dire se A è E-buono
        cout << eBuono(A, temp) << endl;
    }
    else{
        if(t == 2){ // dire de esiste un riallocamento F-stabile di A che sia E-buono
            vector<int> riallocamento = fStabile(A,F);

            cout << eBuono(riallocamento, temp) << endl;
        }
    }
}
