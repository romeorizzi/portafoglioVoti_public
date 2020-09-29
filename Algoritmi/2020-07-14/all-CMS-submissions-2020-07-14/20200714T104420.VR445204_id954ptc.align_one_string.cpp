/**
* user:  VR445204_id954ptc
* fname: ENRICO
* lname: MARTINI
* task:  align_one_string
* score: 2.0
* date:  2020-07-14 10:44:20.948173
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

//#define DEBUG

const int INF = 1 << 29;
inline int min(int a, int b){return a< b? a:b;}
inline int max(int a, int b){return a>=b? a:b;}

void print(std::vector<int> res){
    for(auto e : res)
        std::cout << e << " ";
    std::cout << std::endl;
}

inline bool is_comp(const char a, const char b){
    return a == b || a == '*' || b == '*';
}

inline std::string rep(const char c, const int delta){
    std::string res = "";
    for(int i = 0; i < delta; i++)
        res += c;
    return res;        
}

// Dynamic Programming (NO MEMO)
int align(int i, int j, const std::string& a, std::string& b, int ast, const std::vector<int>& cost){

    #ifdef DEBUG
    std::cout << a[i] << " " << i << " vs " << b[j] << " " << j << " dopo " << ast << " asterischi" << std::endl;
    #endif

    // Se a e b sono finali e giusti
    if(i == a.size()-1 && j < b.size() -1 && is_comp(a[i],b[j])){
        #ifdef DEBUG
        std::cout<< "\ta e b sono finali e giusti" << std::endl;
        #endif
        return cost[ast];
    }

    // Se ho scorso tutto a ma non ancora b
    if(i == a.size()-1 && j < b.size() -1 ){
        #ifdef DEBUG
        std::cout<< "\tho scorso tutto a ma non ancora b" << std::endl;
        #endif
        return INF;
    }
    
    // Se siamo all'ultimo carattere di b, siamo compatibili ma a ha ancora un po' di strada
    if(is_comp(a[i],b[j]) && (j >= b.size()-1) && (i < a.size()-1) ) {
        #ifdef DEBUG
        std::cout<< "\tultimo carattere di b ma non di a" << std::endl;
        #endif
        return min(cost[(a.size()-1) - i]+cost[ast],align(i+1,j,a,b,ast+1,cost));
    }
    // Se siamo all'ultimo carattere allineati e compatibili
    if( is_comp(a[i],b[j]) && (i >= a.size()-1) ) {
        #ifdef DEBUG
        std::cout<< "\t siamo all'ultimo carattere allineati e compatibili" << std::endl;
        #endif
        return cost[ast];
    }

    // Se siamo ad un carattere qualsiasi ma diversi
    if(!is_comp(a[i],b[j]) && (i >= a.size()-1) ) {
        #ifdef DEBUG
        std::cout<< "\tsiamo ad un carattere qualsiasi ma diversi" << std::endl;
        #endif
        return INF;
    }

    // Nel caso in cui siano uguali devo fare una scelta
    if( is_comp(a[i],b[j]) ) {
        #ifdef DEBUG
        std::cout<< "\tsiamo uguali e devo fare una scelta" << std::endl;
        #endif
        return min( align(i+1,j+1,a,b,0,cost) + cost[ast] , align(i+1,j,a,b,ast+1,cost) );
    }

    // Nel caso in cui siano diversi sono obbligato a aggiungere un asterisco
    if( !is_comp(a[i],b[j]) ) {
        #ifdef DEBUG
        std::cout<< "\tsono obbligato a aggiungere un asterisco" << std::endl;
        #endif
        return(align(i+1,j,a,b,ast+1,cost));
    }

    std::cout << " Error" << std::endl;
    return INF;
}

signed main(){
    std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    
    // Input
    int m,n,p;std::cin >> m;std::cin >> n;std::cin >> p;
    std::string a,b; std::cin >> a; std::cin >> b;
    std::vector<int> cost(p+1);
    for(int i = 0; i < p+1; i++)
        std::cin >> cost[i];

    int res = align(0,0,a,b,0,cost);
    res = res != INF? res : -1;
    std::cout << res << std::endl;

    return 0;
}