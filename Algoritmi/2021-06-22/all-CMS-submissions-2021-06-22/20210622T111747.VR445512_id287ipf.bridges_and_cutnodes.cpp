/**
* user:  VR445512_id287ipf
* fname: NICHOLAS
* lname: MERCI
* task:  bridges_and_cutnodes
* score: 30.0
* date:  2021-06-22 11:17:47.127408
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <list>

using namespace std;

bool isReachable(vector<pair<int, int> > G_reduced, int u, int v, int N){
    
    vector<bool> visited;
    visited.resize(N);

    list<int> queue;
    visited[u] = true;
    queue.push_back(u);

    while (!queue.empty())
    {

        // Dequeue a vertex from queue and print it
        u = queue.front();
        queue.pop_front();

        vector<int> adj;

        for (int i = 0; i < G_reduced.size(); i++) {
            if(G_reduced[i].first == u)
                adj.push_back(G_reduced[i].second);
            if(G_reduced[i].second == u)
                adj.push_back(G_reduced[i].first);            
        }
        vector<int>::iterator it = adj.begin();

        for (int i = 0; i < adj.size(); i++)
        {

            if (adj[i] == v)
                return false;

            if (!visited[adj[i]])
            {
                visited[adj[i]] = true;
                queue.push_back(adj[i]);
            }
        }
    }

    return true;
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

            case 1: {
                pair<int,int> to_remove;

                for (int i = 0; i < M; i++) {
                    vector <pair<int, int> > G_reduced = G;
                    bool flag;
                    G_reduced.erase(G_reduced.begin() + i);
                    flag = isReachable(G_reduced, G[i].first, G[i].second, N);
                    cout << flag << endl;;
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
