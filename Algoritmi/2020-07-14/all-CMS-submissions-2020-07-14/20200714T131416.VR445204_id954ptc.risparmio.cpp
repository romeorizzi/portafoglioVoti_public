/**
* user:  VR445204_id954ptc
* fname: ENRICO
* lname: MARTINI
* task:  risparmio
* score: 1.0
* date:  2020-07-14 13:14:16.206619
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

//#define DEBUG

const int INF = 1 << 29;
inline int min(int a, int b){return a< b? a:b;}
inline int max(int a, int b){return a>=b? a:b;}

void print(std::vector<bool> res){
    for(auto e : res)
        std::cout << e << " ";
    std::cout << std::endl;
}

class node{
    public:
        int v;
        bool l_one,r_one;
        node(int a, bool b, bool c){
            v = a;
            l_one = b;
            r_one = c;
        }
        node(){
            v = 0;
            l_one = 0;
            r_one = 0;
        }
        void update(node son_l, node son_r){
            // se il nodo più a dx è 1 e a sx è 1
            if(son_l.r_one && son_r.l_one)
                v = son_l.v + son_r.v - 1;
            else
                v = son_l.v + son_r.v;
            l_one = son_l.l_one;
            r_one = son_r.r_one;
        }
};

class seg_tree{
    public:
        int size;
        std::vector<node> T;
        seg_tree(int s){
            size = s;//
            T = std::vector<node>(4*s);
        }
        #ifdef DEBUG
        void print_tree(){
            for(auto e : T)
                //std::cout << "{" <<  e.v << "," << e.l_one << "," << e.r_one << "} ";
                std::cout << e.v << " ";
            std::cout << std::endl;
        }
        #endif
        int query(int a, int b){
            #ifdef DEBUG
            std::cout << "Range " << a << " " << b << std::endl;
            #endif
            // Parto dalle foglie
            node n = _query(1,0,size-1,a,b);
            return n.v;
        }

        node _query(int v, int tl, int tr, int l , int r){
            if(l > r)
                return node();
            if(l == tl && r == tr)
                return T[v];
            int tm = (tl+tr)/2;
            return sum(_query(v*2,tl,tm,l,min(r,tm)) , _query(v*2+1,tm+1,tr,max(l,tm+1),r));
        }

        node sum(node a, node b){
            if(a.r_one && b.l_one)
                return node(a.v+b.v-1,a.l_one,b.r_one);
            return node(a.v+b.v,a.l_one,b.r_one);
        }

        //O(logn) bottom up
        void change(int i){
            #ifdef DEBUG
            std::cout << "Change" << i << std::endl;
            #endif
            i += size; // Sicuramente una foglia
            T[i].v = 1 - T[i].v;
            T[i].l_one = 1-T[i].l_one;
            T[i].r_one = 1-T[i].r_one;
            for(i /= 2; i >= 1 ; i /= 2)
                T[i].update(T[i*2],T[i*2+1]);
            
        }
        // O(nlogn)
        void build(const std::vector<bool>& a, const int v, const int tl, const int tr){
            // Se sono nodo foglia
            std::cout << "Qui?"<< std::endl;
            if(tl == tr){
                T[v].v = a[tl];
                T[v].l_one = a[tl];
                T[v].r_one = a[tl];
            }            
            // Se non è foglia
            else{
                int med = (tl+tr/2);
                build(a,v*2,tl,med);
                build(a,v*2,med+1,tr);
                T[v].update(T[v*2],T[v*2+1]);           
            }
        }

};

// O(logn)
void solve(std::vector<bool>& luci, std::vector<std::vector<int>> op){
    seg_tree T = seg_tree(luci.size());
    //T.build(luci,1,0,luci.size()-1);
    for(auto o : op){
        #ifdef DEBUG
        T.print_tree();
        #endif
        if(o[0] == 1){
            T.change(o[1]);
        }
        else{
            std::cout << T.query(o[1],o[2]) << std::endl;
        }
    }
}

// O(n)
void solve_linear(std::vector<bool>& luci, std::vector<std::vector<int>> op){
    // Per ogni operazione
    for(auto o : op){
        // Inversione O(1)
        if(o[0] == 1){
            luci[o[1]] = !luci[o[1]];
        }
        // Query O(n)
        else{
            int intervalli = 0;
            bool prev = false;
            for(int i = o[1]; i <= o[2] ; i++){
                if(luci[i] && !prev){
                    intervalli++;
                    prev = true;
                }
                else if(!luci[i] && prev){
                    prev = false;
                }
            }
            std::cout << intervalli << "\n";
        }
    }
}

signed main(){
    // Input
    std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    int N,M;std::cin >> N;std::cin >> M;
    int tmp;
    std::vector<std::vector<int>> op(M);
    for(int i = 0; i < M; i++){
        std::cin >> tmp;
        // Luce invertita
        if(tmp == 1){
            op[i].push_back(1);
            std::cin >> tmp;
            op[i].push_back(tmp);
        }
        // Range query
        else{
            op[i].push_back(2);
            std::cin >> tmp;
            op[i].push_back(tmp);
            std::cin >> tmp;
            op[i].push_back(tmp);
        }
    }

    std::vector<bool> luci(N,false);

    solve(luci,op);

    return 0;
}