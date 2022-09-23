/**
* user:  VR478050
* fname: GIACOMO
* lname: GATTO
* task:  esamebridges_and_cutnodes
* score: 0.0
* date:  2022-07-26 12:04:50.477832
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int t, n, m;
int first, second;
const int F = 20;

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> t >> n >> m;

    int edge[F][n];
    int contatore[n];

    for(int i=0; i<F; i++){
        for(int j=0; j<n; j++){
            edge[i][j]=-1;
        }
    }

    

    for(int i=0; i<n; i++){
        contatore[i]=0;
    }

    for(int i=0; i<m; i++){ //Per tutti gli archi
        cin >> first >> second;
        edge[contatore[i]][first] = second;
        contatore[i]++;
    }

  /*
    for(int i=0; i<F; i++){
        for(int j=0; j<n; j++){
            cout<<edge[i][j];
        }
    }
    */
    




    return 0;
}