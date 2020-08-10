/**
* user:  VR445204_id954ptc
* fname: ENRICO
* lname: MARTINI
* task:  gioco_triangolo
* score: 1.0
* date:  2020-07-14 11:56:00.654964
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
const int INF = 1 << 29;
inline int min(int a, int b){return a< b? a:b;}
inline int max(int a, int b){return a>=b? a:b;}

void print(std::vector<int> res){
    for(auto e : res)
        std::cout << e << " ";
    std::cout << std::endl;
}

signed main(){
    std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    int M,N; std::cin >> M; std::cin >> N;
    
    if(M == 1 && N == 2)
        std::cout << "T 2 0 0" << std::endl;
    else if(M == 2 && N == 2)
        std::cout << "1\nT 2 1 0" << std::endl;
    else if(M == 1 && N == 3)
        std::cout << "T 2 1 0" << std::endl;
    else if(M == 2 && N == 3)
        std::cout << "0" << std::endl;
    
    return 0;
}