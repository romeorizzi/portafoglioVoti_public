/**
* user:  VR424402
* fname: D'ARIENZO
* lname: PAOLO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 10:46:49.998526
*/
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N = 0; //numero nani
int M = 0; //numero istruzioni
vector<int> fila;

void scambio(int x, int y) {
    
    int tmp;
    tmp = fila.at(x-1);
    fila.at(x-1) = fila.at(y-1);
    fila.at(x-1) = tmp;

}

bool check(int x, int y) {

    int min, max, index;
    vector<int>::iterator it1=row.begin();
    vector<int>::iterator it2=row.begin();    
    
    it1=find(fila.begin(), fila.end(), x);
    it2=find(fila.begin(), fila.end(), y);
    
    if(it1 != row.end()) {
        min = distance(row.begin(), it1);
    }
    if(it2 != row.end()) {
        max = distance(row.begin(), it2);
    }
    
    if(min > max) {
        for(int i = max-1; i > min; i--){
            if( fila.at(i) > fila.at(max) || fila.at(i) < fila.at(min) )
                return false;
        }    
    }
    else {
        for(int i = min+1; i < max; i++){
            if( fila.at(i) > fila.at(max) || fila.at(i) < fila.at(min) )
                return false;
        }
    }
    
    return true;
    
}
  
int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    cin >> N; //nani
    cin >> M; //richieste
    
    itn array[n];
    for(int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        fila.push_back(tmp);
        array[i] = tmp;        
    }
    
    for(int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op;
        cin >> a; 
        cin >> b;
        
        if(op == 1)
            scambio(a-1, b-1);
        if(op == 2){
            if(check(a, b))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    
    }
    
    return 0;

}
