/**
* user:  VR445204_id954ptc
* fname: ENRICO
* lname: MARTINI
* task:  chordal_lexBFS
* score: 0.0
* date:  2020-09-18 11:35:03.080924
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
const int INF = 1 << 29;

using namespace std;

inline int min(int a, int b){return a< b? a:b;}
inline int max(int a, int b){return a>=b? a:b;}

void print(vector<int> res){
    for(auto e : res)
        cout << e << " ";
    cout << endl;
}

class node{
    public:
        int id;
        int w;
        vector<int> adj;

        node(int i_v,int i_w, vector<int> a){
            id = i_v;
            w = i_w;
            adj = a;
        }
        node(){
            w = 0;
        }
        string to_str(){
            return "{"+to_string(id)+";"+to_string(w)+"}";
        }
        bool operator < (const node &c) const {
            return w > c.w;
        }
};

class graph{
    public:
    vector<node> V;
    vector<tuple<int,int>> E;
    vector<int> PEO;

    graph(int N){
        V.resize(N);
        for(int i = 0; i < N; i++)
            V[i].id = i+1;
    }
    
    void get_peo(){
        std::vector<node> Q = V;
        vector<int> peo;
        while(!Q.empty()){
            node x = Q[0];
            Q.erase(Q.begin());
            peo.push_back(x.id);
            for(auto y: x.adj)
                V[y-1].w++;
            if(!Q.empty())
                for(int i = 0; i < Q.size(); i++)
                    Q[i].w = V[Q[i].id-1].w;
            sort(Q.begin(),Q.end());
        }
        PEO = peo;
        reverse(PEO.begin(),PEO.end());
    }
    
    void add_edge(int u, int v){
        E.push_back(make_tuple(u,v));
        V[u-1].adj.push_back(v);
        V[v-1].adj.push_back(u);
    }
    vector<int> get_tripla(){
        vector<int> peo = PEO;
        reverse(peo.begin(),peo.end());

        vector<int> res;
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int g,n,m; cin >> g >> n >> m;
    // Costruisco il grafo
    graph G(n);
    for(int i = 0; i < m; i++){
        int u,v ; cin >> u >> v;
        G.add_edge(u,v);
    }
    if(g == 1){
        G.get_peo();
            bool lex = true;
            for(int i = n; i > 0; i--){
                if(G.PEO[n-i] != i)
                    lex = false;
            }
            if(lex)
                cout << 1 << endl;
            else{
                cout << 0 << endl;
                //print(G.PEO);
                //print(G.get_tripla());
            }
    }
    


    return 0;
}