/**
* user:  VR460384_id602ngu
* fname: NICOLA
* lname: ASSOLINI
* task:  bridges_and_cutnodes
* score: 102.0
* date:  2021-06-22 09:06:01.368259
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAXV = 50001;
const int MAXE = 200001;
int archi[MAXE][2];
bool ponte[MAXE];
bool nodoCut[MAXV];
int V, E;
int t;
vector<int> adj[MAXV];
bool visitato[MAXV];
int tin[MAXV], low[MAXV];
int tempo;

void dfsN(int v, int p = -1) {
    visitato[v] = true;
    tin[v] = low[v] = tempo++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visitato[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfsN(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                nodoCut[v] = true;
            ++children;
        }
    }
    if(p == -1 && children > 1)
        nodoCut[v] = true;
}



void dfs(int v, int p = -1) {
    visitato[v] = true;
    tin[v] = low[v] = tempo++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visitato[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                for(int i = 0; i < E; i++){
                    if ((archi[i][0] == v && archi[i][1] == to) || (archi[i][0] == to && archi[i][1] == v)){
                        ponte[i] = true;
                        break;
                    }
                }
                // cout << "vicini di " << v << " " << adj[v].size() << endl;
                // cout << "vicini di " << to << " " << adj[to].size() << endl;
            }
        }
    }
}

void find_bridges() {
    tempo = 0;
    visitato[V] = false;
    tin[V] =  -1;
    low[V] = -1;
    for (int i = 0; i < V; ++i) {
        if (!visitato[i]){
            if (t == 1)
                dfs(i);
            else
                dfsN(i);
        }
            
    }
}


int main() {
    ofstream out("output.txt");
    ifstream in("input.txt");

    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());   

    int start, end;

    cin >> t >> V >> E;
    int v, u;
    for(int i = 0; i < E; i++){
        cin >> v >> u;
        adj[u].push_back(v); 
        adj[v].push_back(u);
        archi[i][0] = v;
        archi[i][1] = u;
    }
    
    find_bridges();
    
    if (t == 1){
        for(int i = 0; i < E; i++){
            cout << ponte[i] << endl;
        }
    } else if (t == 2) {
        for(int i = 0; i < V; i++){
            cout << nodoCut[i] << endl;
        }
    } else {
        cout << "ciao" << endl;
    }

    return 0;
}
