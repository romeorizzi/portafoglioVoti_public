/**
* user:  VR447268_id713ast
* fname: PIETRO
* lname: TAROCCO
* task:  bridges_and_cutnodes
* score: 52.0
* date:  2021-06-22 11:34:48.922538
*/
#include<iostream>
#include<list>
#include<fstream>
#include<cassert>
#include<vector>
using namespace std;
const int MAXN = 1000000; 
vector<pair<int, int>> edges_matrix; // matrice che uso solo per ricordare gli archi

// classe che rappresenta un grafo non-diretto, connesso, e semplice
class Graph{
    int N;  // numero di nodi
    int M;  // numero di archi
    list<int> *adj;  // lista di adiacenza per rappresentare il grafo
    void bridge_util(int u, int tempi[], int parent[], int low[], bool visitati[], int bridges[]);  // funzione di utilità per trovare i ponti
    void cutnodes_util(int u, int tempi[], int parent[], int low[], bool visitati[], bool cut_node[]);  // funzione di utilità per trovare i cutnodes
public:
    Graph(int N, int M);
    void addEdge(int u, int v);
    void find_bridges();
    void find_cutnodes();
};
  
Graph::Graph(int N, int M){
    // costruttore
    this->N = N;
    this->M = M;
    adj = new list<int>[N];
}
  
void Graph::addEdge(int u, int v){
	// aggiungo gli archi in entrambe le direzioni perchè il grafo non è diretto
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// funzione di utilità per dfs
void Graph::bridge_util(int u, int tempi[], int parent[], int a[], bool visitati[], int bridges[]){
    
    static int tempo = 0;
    visitati[u] = true;
    tempi[u] = a[u] = ++tempo;
  
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;
        if (!visitati[v]){
            parent[v] = u;
            bridge_util(v, tempi, parent, a, visitati, bridges);
            a[u]  = min(a[u], a[v]);
            if (a[v] > tempi[u]){
              	bridges[u] = v;
          	}
        }
  
        else if (v != parent[u])
            a[u]  = min(a[u], tempi[v]);
    }
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
  
  
void Graph::find_bridges(){
	int *bridges = new int[M];
    bool *visitati = new bool[N];
    int *tempi = new int[N];
    int *l = new int[N];
    int *parent = new int[N];
  
    for (int i = 0; i < N; i++){
        parent[i] = -1;
        visitati[i] = false;
    }
  
    for (int i = 0; i < N; i++){
        if (visitati[i] == false){
            bridge_util(i, tempi, parent, l, visitati, bridges);
        }
    }
    
    vector<int> result(M, 0);
    for (int i = 0; i < M; i++){
        if (bridges[i] != 0){
        	for (int w = 0; w < M; w++){
        		if (edges_matrix[w].first == i and edges_matrix[w].second == bridges[i]){
        			result[w] = 1;
        		}
        	}
    	}
    }
    
    for (int i = 0; i < M; i++){
		cout << result[i] << endl;
	}
}
  
int main(){

	int t, n, m;
	cin >> t >> n >> m;
	
	Graph g(n, m);
	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		assert (u != v);
		g.addEdge(u, v);
		edges_matrix.push_back(make_pair(u,v));
	}

	if(t==1){
		g.find_bridges();
	}
  	if(t==2){
		g.find_cutnodes();
	}
	   
    return 0;
}
