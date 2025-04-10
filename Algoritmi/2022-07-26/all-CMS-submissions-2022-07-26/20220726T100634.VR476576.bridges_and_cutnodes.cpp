/**
* user:  VR476576
* fname: CRISTIANO
* lname: DI BARI
* task:  esamebridges_and_cutnodes
* score: 51.0
* date:  2022-07-26 10:06:34.168666
*/
#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 50000;
const int MAX_M = 200000;

int T = 0;
int N = 0;
int M = 0;

int CUTNODES[MAX_N] = { 0 };
int BRIDGES[MAX_M] = { 0 };

bool VISITED[MAX_N] = { false };

int DISCOVERY_TIME[MAX_N] = { 0 };
int LOW[MAX_N] = { 0 };

int TIME = 0;

unordered_map<string, int> EDGES_MAP;

void dfs_cutnode(vector<int> adj[], int u, int parent) {
    VISITED[u] = true;
    DISCOVERY_TIME[u] = TIME;
    LOW[u] = TIME;
    TIME++;

    int c = 0;

    for (auto v : adj[u]) {

        if (!VISITED[v]) {
            c++;

            dfs_cutnode(adj, v, u);

            LOW[u] = min(LOW[u], LOW[v]);

            if (parent != -1 && LOW[v] >= DISCOVERY_TIME[u]) {
                CUTNODES[u] = 1;
            }
        } else if (v != parent) {
            LOW[u] = min(LOW[u], DISCOVERY_TIME[v]);
        }

    }

    if (parent == -1 && c > 1) {
        CUTNODES[u] = 1;
    }
}

void dfs_bridge(vector<int> adj[], int u, int parent) {
    VISITED[u] = true;
    DISCOVERY_TIME[u] = TIME;
    LOW[u] = TIME;
    TIME++;

    for (auto v : adj[u]) {
        if (!VISITED[v]) {
            dfs_bridge(adj, v, u);

            LOW[u] = min(LOW[u], LOW[v]);

            if (LOW[v] > DISCOVERY_TIME[u]) {
                BRIDGES[EDGES_MAP[to_string(u) + "~" + to_string(v)]] = 1;
            }
        } else if (v != parent) {
            LOW[u] = min(LOW[u], DISCOVERY_TIME[v]);
        }
    }
}

void dfs_cc(vector<int> adj[], int u, int removed, bool visited[]) {
    visited[u] = true;

    for (auto v : adj[u]) {
        if (!visited[v] && v != removed) {
            dfs_cc(adj, v, removed, visited);
        } 
    }
}

void find_bridges(vector<int> adj[]) {
    dfs_bridge(adj, 0, -1);

    for (int i = 0; i < M; i++) {
        cout << BRIDGES[i] << "\n";
    }
}

void find_cutnodes(vector<int> adj[]) {
    dfs_cutnode(adj, 0, -1);

    for (int i = 0; i < N; i++) {
        cout << CUTNODES[i] << "\n";
    }
}

void find_connected(vector<int> adj[]) {
    for (int i = 0; i < N; i++) {
        int conn_comp = 0;
        bool visited[N] = { false };
        for (int u = 0; u < N; u++) {
            if (!visited[u] && u != i) {
                conn_comp++;
                dfs_cc(adj, u, i, visited);
            }
        }
        cout << conn_comp << "\n";
    } 
}

void add_edge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));

    cin >> T;
    cin >> N;
    cin >> M;

    vector<int> G_ADJ[N];

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u;
        cin >> v;
        add_edge(G_ADJ, u, v);
        EDGES_MAP[to_string(u) + "~" + to_string(v)] = i;
    }

    if (T == 1) {
        find_bridges(G_ADJ); 
    }

    if (T == 2) {
        find_cutnodes(G_ADJ); 
    }

    if (T == 3) {
        find_connected(G_ADJ);
    }

    return 0;
}
