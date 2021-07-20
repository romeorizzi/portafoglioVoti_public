/**
* user:  VR445512_id287ipf
* fname: NICHOLAS
* lname: MERCI
* task:  bridges_and_cutnodes
* score: 0.0
* date:  2021-06-22 09:11:20.236332
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

bool isBridge(vector<pair<int, int> > G_reduced, pair<int,int> e_removed, int M){

    bool flag;

    int u = e_removed.first;
    int v = e_removed.second;

    bool u_unique = true;
    bool v_unique = true;
    //cerco un modo di arrivare da u a v dopo aver rimosso l'arco che li connetteva
    for (int i = 0; i < M; i++) {
        if(G_reduced[i].first == u || G_reduced[i].second == u){
            u_unique = false;
            u = G_reduced[i].first;
            v = G_reduced[i].second;

        }
        else
            return false;

    }

    return flag;
}

int main () {

    int t;  
    int N;  
    int M; 

    vector <pair<int, int> > G;
    pair<int,int> arco;

    cin >> t >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> arco.first >> arco.second;
        G.push_back(arco);
    }

    switch (t) {
            case 2: {
                /*
                for (int i = 0; i < N; i++) {
                    int to_remove = i;

                    for (int j = 0; j < M; j++){
                        if (G[j].first == to_remove || G[j].second == to_remove){
                            if (G[j].first == to_remove)
                                int to_check = G[j].second;
                            else
                                int to_check = G[j].first;
                            
                        }
                    }
                }*/
                cout << "ciao" << endl;
            }
            break;
            case 1: {
                pair<int,int> to_remove;

                for (int i = 0; i < M; i++) {
                    vector <pair<int, int> > G_reduced = G;
                    bool flag;
                    G_reduced.erase(G_reduced.begin() + i);
                    flag = isBridge(G_reduced, G[i], M);
                    cout << flag;
                }
            }
            break;
            default: assert(false);
            break;

    return 0;
    }
}
