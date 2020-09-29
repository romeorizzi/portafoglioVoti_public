/**
* user:  VR445639_id956tpd
* fname: ROSA
* lname: RUSSO
* task:  chordal_lexBFS
* score: 0.0
* date:  2020-09-18 12:22:20.887360
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

const int N = 100000; /* max number of vertices - adjust */
int n, m; /* number of vertices, number of edges */

set< pair<int, int> > edges;
vector<int> adj[N];
int order[N], cnt[N], pos[N];

void mcs(int v = 0) // maximum cardinality search algorithm for chordal graph recognition
{   set< pair<int, int> > s;
    int k = 0;

    memset(pos, -1, sizeof(pos));

    s.insert(make_pair(0, v));
    while(s.empty() == false)
    {   pair<int, int> p = *s.begin();
        s.erase(s.begin());

        int x = p.second;
        pos[x] = k;
        order[k++] = x;

        for(int i = 0; i < adj[x].size(); i++)
        {   int y = adj[x][i];
            if(pos[y] != -1) continue;

            if(cnt[y]) s.erase(make_pair(cnt[y], y));
            s.insert(make_pair(--cnt[y], y));
        }
    }
}

bool perfect(void)
{   for(int j = 1; j < n; j++){
        int u = -1;
	    int v = order[j];
        for(int i = 0; i < adj[v].size(); i++){
            int y = adj[v][i];
            if(pos[y] < pos[v]){
		        if(u == -1) u = y;
		        else if(pos[u] < pos[y])
                    u = y;
	        }
        }

        for(int i = 0; i < adj[v].size(); i++){
            int y = adj[v][i];

	    if(y == u) continue;
	    
        if(pos[y] >= pos[u]) continue;

        if(edges.count(make_pair(u, y)) == 0)
            return false;
        }
    }
    return true;
}

int main(void)
{
    int t, n, m;
    cin >> t >> n >> m;

    for(int i = 0; i < m; i++)
    {   int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges.insert(make_pair(x, y));
        edges.insert(make_pair(y, x));
    }

    mcs();         

    if (perfect()){
        for (int i = n; i>0; i--){
        cout << i << " ";
        }
    }
    return 0;
}
