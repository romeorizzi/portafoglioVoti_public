/**
* user:  VR445204_id954ptc
* fname: ENRICO
* lname: MARTINI
* task:  corrected-chordal_lexBFS
* score: 10.0
* date:  2020-09-18 13:36:41.360913
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
        int c = 0;

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

    bool is_clique(vector<int>& ids){
            for(auto u : ids)
                for(auto v : ids)
                    if(u != v && (find(E.begin(),E.end(),make_tuple(u,v)) == E.end() && find(E.begin(),E.end(),make_tuple(v,u)) == E.end() ) )
                        return false;
            return true;
        }

    bool is_chordal(){
        if(PEO.empty())
            get_peo();
        for(int i = 0; i < PEO.size(); i++){
            vector<int> candidate;
            for(auto v: V[PEO[i]-1].adj)
                if( find(PEO.begin()+i+1,PEO.end(),v) != PEO.end())
                    candidate.push_back(v);
            if(!candidate.empty()){
                candidate.push_back(PEO[i]);
                if(!is_clique(candidate)){
                    sort(candidate.begin(),candidate.end());
                    return candidate[0];
                }
            }
        }
        return 0;
    }

    int get_max_clique(){
        if(PEO.empty())
            get_peo();
        int max_clique = 1;
        for(int i = 0; i < PEO.size(); i++){
            vector<int> candidate;

            for(auto v : V[PEO[i]-1].adj)
                if( (find(PEO.begin()+i+1,PEO.end(),v) != PEO.end()) )
                    candidate.push_back(v);

            if(!candidate.empty()){
                candidate.push_back(PEO[i]);
                if(is_clique(candidate))
                    max_clique = candidate.size() > max_clique ? candidate.size() : max_clique;
            }
        }
        return max_clique;                  
    }

    vector<int> get_clique(){
        if(PEO.empty())
            get_peo();
        
        int max_clique = 1;
        vector<int> clique;
        clique.push_back(1);
        for(int i = 0; i < PEO.size(); i++){
            vector<int> candidate;
            
            for(auto v : V[PEO[i]-1].adj)
                if( (find(PEO.begin()+i+1,PEO.end(),v) != PEO.end()) )
                    candidate.push_back(v);

            if(!candidate.empty()){
                candidate.push_back(PEO[i]);
                if(is_clique(candidate))
                    if(candidate.size() > max_clique){
                        max_clique =  candidate.size();
                        clique = candidate;
                    }
            }
        }
        return clique;                  
    }

    vector<int> get_col(){
        V[PEO[0]-1].c = 1;
        for(int j = 0; j < PEO.size(); j++){
            for(int i = 0; i < V[PEO[0]-1].adj.size(); i++){
               if(find( PEO.begin() + 1, PEO.end() , V[V[PEO[0]-1].adj[i]].id ) != PEO.end())
                    V[V[PEO[0]-1].adj[i]-1].c = V[PEO[0]-1].c+1;
            }
        }
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
            }
    }
    else if(g == 2){
        int re = G.is_chordal();
        if(re == 0)
            print(G.PEO);
        else{
            cout << re << endl;
        }
    }
    else if(g == 3){
        cout << G.get_max_clique() << endl;
    }
    else if(g == 4){
        vector<int> cl = G.get_clique();
        cout << cl.size() << endl;
        sort(cl.begin(),cl.end());
        print(cl);
    }
    
    return 0;
}