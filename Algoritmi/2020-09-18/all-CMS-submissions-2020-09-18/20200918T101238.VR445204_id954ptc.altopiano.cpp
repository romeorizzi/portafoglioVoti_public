/**
* user:  VR445204_id954ptc
* fname: ENRICO
* lname: MARTINI
* task:  altopiano
* score: 26.0
* date:  2020-09-18 10:12:38.283046
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
const int INF = 100; //1 << 20;

using namespace std;

inline int min(int a, int b){return a< b? a:b;}
inline int max(int a, int b){return a>=b? a:b;}
inline int p2(int n){return n && (!(n && (n-1)));}

void print(vector<int> res){
    for(auto e : res)
        cout << e << " ";
    cout << endl;
}

#define DEBUG

class node{
    public:
        int alt = -INF;                             // Se ha un altopiano riporta l'altezza dell'altopiano max
        pair<int,int> l = make_pair(1,alt);
        pair<int,int> r = make_pair(1,alt);      // <uno o due posti uguali a sx ; valore dei posti uguali>
        bool has_alt = false;
        bool is_leaf = true;

        node(){};

        node(int a){
            a = alt;
            l = make_pair(1,alt);
            r = make_pair(1,alt);
            has_alt = false;
            is_leaf = true;
        }
        // Solo per le foglie
        void build(int val){
            alt += val;
            l = make_pair(1,alt);
            r = make_pair(1,alt);
            has_alt = false;
            is_leaf = true;
        }

        // Per i nodi che non sono foglie
        void update(node s_l, node s_r){
            is_leaf = false;
            // Se in mezzo ai due esce un altopiano
            if( get<1>(s_l.r) == get<1>(s_r.l) && (get<0>(s_l.r) == 2 || get<0>(s_r.l) == 2) )
                alt = s_l.alt > s_r.alt? max(s_l.alt,get<1>(s_r.l)) : max(get<1>(s_r.l),s_r.alt);
            else if(s_l.has_alt || s_r.has_alt)
                alt = max(s_l.alt,s_r.alt);
            else
                alt = -INF;

            if(alt != -INF)
                has_alt = true;
            else
                has_alt = false;
            
            if(s_l.is_leaf && s_r.is_leaf && get<1>(s_l.r) == get<1>(s_r.l)){
                l = make_pair(2,get<1>(s_r.l));
                r = l;
            }
            else{
                l = s_l.l;
                r = s_r.r;
            }
        }

        string to_str(){
            string s = "{"+ to_string(alt) + " , " + to_string(get<0>(l)) + "_" + to_string(get<1>(l)) + " , " + to_string(get<0>(r)) + "_" + to_string(get<1>(r)) + " , "+ to_string(has_alt) + "}";
            return s;
        }

};

class seg_tree{
    public:
        vector<node> A;

        // Constructor
        seg_tree(int s){
            int r = pow(2, (int)(log2(s)) +1) -s;
            A.resize(2*(s+r));
        }

        // Update x with y height BOTTOM UP
        void update(int x, int y){
            x += A.size() / 2;
            A[x].build(y);
            for(int f = x/2; f > 0; f /= 2 )
                A[f].update(A[f*2],A[f*2+1]);
        }

        // Query altopiano?
        string query(int l, int r){
            r++;
            l += A.size() / 2;
            r += A.size() / 2;
            node s_l = node(-INF);
            node s_r = node(-INF);
            bool f_l = true;
            bool f_r = true;
            while(l < r){
                if(l %2 == 1){
                    if(f_l){
                        s_l = A[l];
                        f_l = !f_l;
                    }
                    else{
                        node dad;
                        dad.update(s_l,A[l]);
                        s_l = dad;
                    }
                    l++;
                }
                if(r % 2 == 1){
                    r--;
                    if(f_r){
                        s_r = A[r];
                        f_r = !f_r;
                    }
                    else{
                        node dad;
                        dad.update(A[r],s_r);
                    }
                }
                l /=2;
                r /=2;
            }
            node fin;
            fin.update(A[l],A[r]);
            string res = fin.has_alt ?  to_string(fin.alt) : "NESSUN_ALTOPIANO";
            return res;
        }

        void print_tree(){
            int l = 1;
            int level = 1;
            for(int i = 1; i < A.size(); i ++){
                cout << A[i].to_str();
                if(level == l){
                    cout << endl;
                    level = 1;
                    l*=2;
                }
                else{
                    level ++;
                }
            }
            cout << endl;
        }
};

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N,M; cin >> N >> M;
    seg_tree T(N);
    // Dati altezze
    for(int i = 0; i < N ; i ++){
        int t; cin >> t;
        T.update(i,INF+t);
    }
    //T.print_tree();
    // Faccio operazioni
    for(int i = 0; i < M ; i++){
        int OP, A, B; cin >> OP >> A >> B;        
        switch(OP){
            case 1:
                T.update(A,B);
                //T.print_tree();
                break;
            case 2:
                cout << T.query(A,B+1) << endl;
                break;
        }
    }
    return 0;
}