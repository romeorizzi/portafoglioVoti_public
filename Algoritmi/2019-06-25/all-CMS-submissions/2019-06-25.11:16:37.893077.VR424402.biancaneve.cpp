/**
* user:  VR424402
* fname: D'ARIENZO
* lname: PAOLO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 11:16:37.893077
*/
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> fila;

void scambio(int x, int y) {
    
    int tmp;
    tmp = fila.at(x);
    fila.at(x) = fila.at(y);
    fila.at(y) = tmp;

}

bool check(int x, int y) {

    int min, max, index;
    vector<int>::iterator it1=fila.begin();
    vector<int>::iterator it2=fila.begin();    
    
    it1=find(fila.begin(), fila.end(), x);
    it2=find(fila.begin(), fila.end(), y);
    
    if(it1 != fila.end()) {
        min = distance(fila.begin(), it1);
    }
    if(it2 != fila.end()) {
        max = distance(fila.begin(), it2);
    }
    
    if(it1 > it2) {
        for(vector<int>::iterator i = it2+1; i != it1; i++){
            if(*i > *it2 || *i < it1)
                return false;
        }
          
    }
    else {
        for(vector<int>::iterator i = it1+1; i != it2; i++){
            if(*i > *it2 || *i < it1)
                return false;
        }
    }
    
    return true;
    
}
  
int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int N = 0; //numero nani
    int M = 0; //numero istruzioni
    
    cin >> N; //nani
    cin >> M; //richieste
    
    int array[N];
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        fila.push_back(tmp);
        array[i] = tmp;        
    }
    
    for(int i = 0; i < M; i++) {
        int op, a, b;
        cin >> op;
        cin >> a; 
        cin >> b;
        
        if(op == 1){
            scambio(a-1, b-1);
        }
        if(op == 2){
            if(check(a, b))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    
    }
    
    return 0;

}
