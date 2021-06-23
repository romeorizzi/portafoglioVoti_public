/**
* user:  VR447268_id713ast
* fname: PIETRO
* lname: TAROCCO
* task:  bridges_and_cutnodes
* score: 52.0
* date:  2021-06-22 09:05:22.636537
*/
#include<iostream>
#include<list>
#include<fstream>
#include<cassert>
#include<vector>
using namespace std;
const int MAXN = 1000000;  

// classe che rappresenta un grafo non-diretto, connesso, e semplice
class Graph{
    int N;  // numero di nodi
    int M;  // numero di archi
    list<int> *adj;  // lista di adiacenza per rappresentare il grafo
    void cutnodes_util(int u, int tempi[], int parent[], int low[], bool visitati[], bool cut_node[]);  // funzione di utilità per trovare i cutnodes
public:
    Graph(int N);
    void addEdge(int u, int v);
    void find_cutnodes();
};
  
Graph::Graph(int N){
    // costruttore
    this->N = N;
    adj = new list<int>[N];
}
  
void Graph::addEdge(int u, int v){
	// aggiungo gli archi in entrambe le direzioni perchè il grafo non è diretto
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::cutnodes_util(int u, int tempi[], int parent[], int l[], bool visitati[], bool cut_node[]){

    int children = 0;
    visitati[u] = true;
    static int tempo = 0;
    tempi[u] = l[u] = ++tempo;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;
        if (!visitati[v]){
            children++;
            parent[v] = u;
            cutnodes_util(v, tempi, parent, l, visitati, cut_node);
            l[u]  = min(l[u], l[v]);
            if (parent[u] == -1 && children > 1)
               cut_node[u] = true;
            if (parent[u] != -1 && l[v] >= tempi[u])
               cut_node[u] = true;
        }
        else if (v != parent[u])
            l[u]  = min(l[u], tempi[v]);
    }
}
 
void Graph::find_cutnodes(){
    
    bool *cut_node = new bool[N];
    bool *visitati = new bool[N];
    int *tempi = new int[N];
    int *l = new int[N];
    int *parent = new int[N];
 
    for (int i = 0; i < N; i++){
        parent[i] = -1;
        visitati[i] = false;
        cut_node[i] = false;
    }
 
    for (int i = 0; i < N; i++){
        if (visitati[i] == false){
            cutnodes_util(i, tempi, parent, l, visitati, cut_node);
        }
    }
 
    for (int i = 0; i < N; i++){
        if (cut_node[i] == true){
            cout << 1 << endl;
        }else{
        	cout << 0 << endl;
        }
    }
}
  
  
int main(){

	int t, n, m;
	cin >> t >> n >> m;
	
	Graph g(n);
	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		assert (u != v);
		g.addEdge(u, v);
	}
	
  	if(t==2){
		g.find_cutnodes();
	}
    
    return 0;
}
