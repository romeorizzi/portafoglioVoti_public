/**
* user:  VR464574_id364gis
* fname: LETIZIA
* lname: QUERCI
* task:  bridges_and_cutnodes
* score: 0.0
* date:  2021-06-22 12:11:26.779097
*/
#include <iostream>
#include <vector>
#include <array>
#include <iterator>
using namespace std;

const int MAXN=10000;
vector <int> vicini[MAXN];
vector <int> prova[MAXN];
vector <int> children[MAXN];
int padre[MAXN];


vector <int> adj[MAXN];
bool visti[MAXN];

void dfs(int nodo){
    visti[nodo] = true;
    for(int i = 0; i < vicini[nodo].size();i++){
        int next = vicini[nodo][i];
        //cout << "nodo " << nodo << endl;
        if(visti[next])continue;
        dfs(next);
    }

    /*bool val=true;
    for(int y=0; y<10;y++){
        cout << visti[y] << " " << endl;
    }

    for(int x=0; x<visti.size();x++) {
        if (visti[x]==0)
            val = false;
    }
    if(val)
        return true;
    else
        return false;*/
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

    dfs(0);
/*
    if(t==1){
        //vector <int> prova(vicini);
        for(int l=0; l<m; l++) {
            for (unsigned int i = 0; i < vicini[l].size(); i++) {
                prova[l][i]=vicini[l][i];
            }
        }
        for(int l=0; l<m; l++) {
            if(l=0){
                prova->erase(l);
                dfs(1);
            }
            else{
                prova.erase(l);
                dfs(0);
            }
        }
    }
    else if(t==2){

        //per ogni nodo provo a rimuoverlo e chimare la DFS
        for(int j=0; j<n; j++) { //scorro per ogni nodo
            for (int i = 0; i < vicini[j].size()-1; i++) { //copio il vettore senza un nodo
                if(i==j) continue;
                prova[i].push_back(vicini[j][i]);
            }

            if(dfs(j))
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }

    }
    else {//t==3

    }
*/
    return 0;
}
