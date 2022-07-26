/**
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  esamebridges_and_cutnodes
* score: 0.0
* date:  2022-07-26 12:02:59.218761
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int UNKNOWN = -1;
const int MAX_N = 50, MAX_M = 200000;
int graph[MAX_N][MAX_N];
int rawGraph[MAX_M][2];

// Init the graph with -1s
void initGraph() {
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            graph[i][j] = UNKNOWN;
}

// Fill the graph with the input values
void fillGraph(int m) {
    int u, prev_u = -1, v;
    int k = 1;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        rawGraph[i][0] = u;
        rawGraph[i][1] = v;

        graph[u][0] = u;
        if (u != prev_u)
            k = 1;
        graph[u][k++] = v;

        prev_u = u;
    }
    
}

// Print the graph
void printGraph(int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == UNKNOWN)
                break;
            cout << graph[i][j];
        }
        cout << '\n';
    }
}

// Get the length of a row of the matrix that represents the graph
int getLength(int index) {
    int count = 0;

    while (graph[index][count] != UNKNOWN)
        count++;
    
    return count;
}

bool findNodes(int u, int v, int index) {
    bool uPresent = false, vPresent = false;
    // cout << u << " " << v << endl;

    for (int i = 0; i < index; i++) {
        for (int j = 0; j < MAX_N; j++) {
            if (graph[i][j] == u) {
                uPresent = true;
            }
            if (graph[i][j] == v) {
                vPresent = true;
            }

            if (uPresent && vPresent)
                return true;
        }
        uPresent = false;
        vPresent = false;
    }

    return false;
}

string findBridges(int m, int n) {
    string result = "";

    for (int i = m - 1; i >= 0; i--) {
        if (graph[i][0] == UNKNOWN)
            continue;
        
        if (getLength(i) == 2) {
            if (!findNodes(graph[i][0], graph[i][1], i)) {
                for (int j = 0; j < m; j++) {
                    if (rawGraph[j][0] == graph[i][0]) {
                        result += "1";
                    }
                }
                // cout << graph[i][0] << " --- " << graph[i][1] << " is a bridge\n";
            }
            else
                for (int j = 0; j < m; j++) {
                    if (rawGraph[j][0] == graph[i][0]) {
                        result += "0";
                    }
                }
                // cout << "0\n";
        }
        else
            for (int j = 0; j < m; j++) {
                if (rawGraph[j][0] == graph[i][0]) {
                    result += "0";
                }
            }
            // cout << "0\n";
    }

    return result;
}

int main() {
    // t: goal
    // n: |V|
    // m: |E|
    int t, n, m;

    cin >> t >> n >> m;

    initGraph();
    fillGraph(m);
    // printGraph(m, n);

    string result = "";
    if (t == 1)
        result = findBridges(m, n);

    for (int i = result.size(); i >= 0; i--)
        cout << result[i] << endl;
}