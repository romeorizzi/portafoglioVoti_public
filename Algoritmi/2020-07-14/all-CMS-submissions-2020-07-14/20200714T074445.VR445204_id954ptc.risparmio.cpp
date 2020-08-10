/**
* user:  VR445204_id954ptc
* fname: ENRICO
* lname: MARTINI
* task:  risparmio
* score: 23.0
* date:  2020-07-14 07:44:45.932543
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

    solve_linear(luci,op);

    return 0;
}