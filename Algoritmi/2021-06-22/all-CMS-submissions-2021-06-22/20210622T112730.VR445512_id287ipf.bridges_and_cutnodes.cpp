/**
* user:  VR445512_id287ipf
* fname: NICHOLAS
* lname: MERCI
* task:  bridges_and_cutnodes
* score: 30.0
* date:  2021-06-22 11:27:30.737551
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <list>

using namespace std;

bool isReachable(vector<pair<int, int> > G_reduced, int u, int v, int N){
    
    //Utilizzo BFS per trovare, se esiste, un path tra i due vertici dell'arco rimosso
    //Se esiste, allora il grafo ridotto è connesso


    //vettore dei vertici visitati e coda
    vector<bool> visited;
    visited.resize(N);
    list<int> queue;

    //il vertice di partenza è visitato
    visited[u] = true;
    queue.push_back(u);

    while (!queue.empty())
    {

        u = queue.front();
        queue.pop_front();

        //Per ogni vertice uscito dalla cosa, ne trovo i nodi vicini
        vector<int> vicini;

        for (int i = 0; i < G_reduced.size(); i++) {
            if(G_reduced[i].first == u)
                vicini.push_back(G_reduced[i].second);
            if(G_reduced[i].second == u)
                vicini.push_back(G_reduced[i].first);            
        }


        for (int i = 0; i < vicini.size(); i++)
        {

            //Se sono vicino al vertice destinazione -> esiste un path tra u e v
            if (vicini[i] == v)
                return false;

            //Altrimenti segno il vertice attuale tra i visitati e proseguo con la ricerca
            if (!visited[vicini[i]])
            {
                visited[vicini[i]] = true;
                queue.push_back(vicini[i]);
            }
        }
    }

    return true;
}


int main () {

    int t;  //tipo di richiesta
    int N;  //numero di vertici
    int M;  //numero di archi

    vector <pair<int, int> > G;
    pair<int,int> uv;

    cin >> t >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> uv.first >> uv.second;
        G.push_back(uv);
    }

    switch (t) {

        //Richiesta di tipo 1: quali archi sono bridge

            case 1: {

                pair<int,int> to_remove;

                for (int i = 0; i < M; i++) {

                    vector <pair<int, int> > G_reduced = G;
                    bool isBridge;
                    G_reduced.erase(G_reduced.begin() + i);

                    //Chiamo la funzione isReachable sul grafo ridotto
                    isBridge = isReachable(G_reduced, G[i].first, G[i].second, N);
                    cout << isBridge << endl;

                }
            }
            break;
            case 2: {
                
            }
            break;
            default: assert(false);
            break;

    return 0;
    }
}
