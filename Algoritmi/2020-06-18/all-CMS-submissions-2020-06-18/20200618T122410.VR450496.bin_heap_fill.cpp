/**
* user:  VR450496
* fname: ZANNI
* lname: GUGLIELMO
* task:  bin_heap_fill
* score: 24.0
* date:  2020-06-18 12:24:10.432044
*/
#include <iostream>
#include <fstream>

#define MAX_ELEM 100000

long long heap_g[MAX_ELEM];
long long E_g[MAX_ELEM];
long long F_g[MAX_ELEM];

int length = 0;
int type = 0;
int result = 0;

int isE(const long long heap[MAX_ELEM],const long long E[MAX_ELEM]){
    for(int i = 1; i < length; ++i){
        if(heap[i] < heap[(i-1)/2]){
            if(E[i] == 1){
                return 0;
            }
        }
    }
    return 1;
}

int isF(const long long heap[MAX_ELEM],const long long E[MAX_ELEM]){
    return 1;
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::cin >> length;
    std::cin >> type;

    for(int i = 0; i < length; ++i){
        std::cin >> heap_g[i];
    }
    for(int i = 0; i < length; ++i){
        std::cin >> E_g[i];
    }
    for(int i = 0; i < length; ++i){
        std::cin >> F_g[MAX_ELEM];
    }

    if(type == 1){
        std::cout << isE(heap_g, E_g);
    } else if(type == 2){
        std::cout << isF(heap_g, F_g);
    }





    return 0;
}
