/**
* user:  VR424402
* fname: D'ARIENZO
* lname: PAOLO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 09:02:05.802104
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

    int N = 0; //numero nani
    int M = 0; //numero istruzioni
    vector<int> fila;
    
    void scambio(int x, int y) {
        
        int tmp;
        tmp = fila[x-1];
        fila[x-1] = fila[y-1];
        fila[x-1] = tmp;
    
    }
    
    bool check(int x, int y) {
    
        return true;
        
    }
/*    
da 2 a 5
2 4 1 3 5 NO

2 4 3 1 5 YES
*/
  
int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    cin >> N;
    cin >> M;
    
    for(int i = 0; i < N; i++) { //lettura nani
        int tmp;
        cin >> tmp;
        fila.push_back(tmp);
    }   
    
    for  (int i = 0; i < M; i++) {
        int tipo, x, y;
        cin >> tipo;
        cin >> x;
        cin >> y;
        
        if (tipo == 1) {
            scambio(x, y);        
        }
        
        if(tipo == 2){
            if(check(x, y)){
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        
    }
    
    return 0;

}
