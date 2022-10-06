/**
* user:  VR472021
* fname: ANNA
* lname: DALLA VECCHIA
* task:  esamebridges_and_cutnodes
* score: 0.0
* date:  2022-07-26 10:46:40.882897
*/
#include using namespace std;
#include bits/stdc++.h

const int MAX_N = 50000;
const int MAX_M = 200000;

int T = 0;
int N = 0;
int M = 0;

int OUTPUT[MAX_N] = { 0 };

bool VISITED[MAX_N] = { false };

int DISCOVERY_TIME[MAX_N] = { 0 };
int LOW[MAX_N] = { 0 };

int TIME = 0;

unordered_map E_MAP;

void dfs_cutnode(vector adj[], int u, int parent) {
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
                OUTPUT[u] = 1;
            }
        } else if (v != parent) {
            LOW[u] = min(LOW[u], DISCOVERY_TIME[v]);
        }

    }

    if (parent == -1 && c > 1) {
        OUTPUT[u] = 1;
    }
}

void dfs_bridge(vector adj[], int u, int parent) {
    VISITED[u] = true;
    DISCOVERY_TIME[u] = TIME;
    LOW[u] = TIME;
    TIME++;

    for (auto v : adj[u]) {
        if (!VISITED[v]) {
            dfs_bridge(adj, v, u);

            LOW[u] = min(LOW[u], LOW[v]);

            if (LOW[v] > DISCOVERY_TIME[u]) {
                if (u < v) {
                OUTPUT[E_MAP[to_string(u) + "~" + to_string(v)]] = 1;
                } else {
                OUTPUT[E_MAP[to_string(v) + "~" + to_string(u)]] = 1;
                }
            }
        } else if (v != parent) {
            LOW[u] = min(LOW[u], DISCOVERY_TIME[v]);
        }
    }
}

void dfs_cc(vector adj[], int u, int removed, bool visited[]) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v] && v != removed) {
            dfs_cc(adj, v, removed, visited);
        }
    }
}

void bridges(vector adj[]) {
    dfs_bridge(adj, 0, -1);

    for (int i = 0; i < M; i++) {
        cout << OUTPUT[i] << "\n";
    }
}

void cutnodes(vector adj[]) {
    dfs_cutnode(adj, 0, -1);

    for (int i = 0; i < N; i++) {
        cout << OUTPUT[i] << "\n";
    }
}


void add_edge(vector adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));

    cin >> T;
    cin >> N;
    cin >> M;

    vector G_ADJ[N];

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u;
        cin >> v;
        add_edge(G_ADJ, u, v);
        E_MAP[to_string(u) + "~" + to_string(v)] = i;
    }

    if (T == 1) {
        bridges(G_ADJ);
    }
    else if (T == 2) {
        cutnodes(G_ADJ);
    }
    else {
        
    }

    return 0;
}