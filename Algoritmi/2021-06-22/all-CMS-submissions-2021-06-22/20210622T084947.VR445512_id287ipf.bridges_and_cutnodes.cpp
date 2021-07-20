/**
* user:  VR445512_id287ipf
* fname: NICHOLAS
* lname: MERCI
* task:  bridges_and_cutnodes
* score: 0.0
* date:  2021-06-22 08:49:47.959887
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

bool isBridge(vector<pair<int, int> > G_reduced){

    bool flag;
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
                    flag = isBridge(G_reduced);
                    cout << flag;
                }
            }
            break;
            default: assert(false);
            break;

    return 0;
    }
}
