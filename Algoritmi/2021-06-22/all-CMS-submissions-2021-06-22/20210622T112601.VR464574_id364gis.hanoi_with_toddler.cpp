/**
* user:  VR464574_id364gis
* fname: LETIZIA
* lname: QUERCI
* task:  hanoi_with_toddler
* score: 0.0
* date:  2021-06-22 11:26:01.654449
*/
#include <iostream>
#include <vector>
#include <array>
using namespace std;

const int MAXN=10000;
vector <int> vicini[MAXN];
vector <int> prova[MAXN];
vector <int> children[MAXN];
int padre[MAXN];


vector <int> adj[MAXN];
array <bool, MAXN> visti;

bool dfs(int nodo){
    visti[nodo] = true;
    for(int i = 0; i < prova[nodo].size();i++){
        int next = prova[nodo][i];
        if(visti[next])continue;
        dfs(next);
    }

    bool val=true;
    for(int x=0; x<visti.size();x++) {
        if (!visti[x])
            val = false;
    }
    if(val)
        return true;
    else
        return false;
}
int main() {
    //letto il tipo di operazione
    int t;
    cin >> t;
    //leggo numero nodi
    int n;
    cin >> n;
    //leggo numero archi
    int m;
    cin >> m;


    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        vicini[u].push_back(v);
        vicini[v].push_back(u);
    }
    //per ogni nodo provo a rimuoverlo e chimare la DFS
    for(int j=0; j<n; j++) { //scorro per ogni nodo
        for (int i = 0; i < vicini[j].size()-1; i++) { //copio il vettore senza un nodo
            if(i==j) continue;
            prova[i].push_back(vicini[j][i]);
        }
        if(dfs(0))
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}
