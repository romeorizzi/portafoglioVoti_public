/**
* user:  VR450496
* fname: ZANNI
* lname: GUGLIELMO
* task:  bin_heap_fill
* score: 23.0
* date:  2020-06-18 12:19:57.763090
*/
#include <iostream>
#include <fstream>

#define MAX_ELEM 100000

int heap_g[MAX_ELEM];
int E_g[MAX_ELEM];

int length = 0;
int type = 0;
int result = 0;

int isE(int heap[MAX_ELEM], int E[MAX_ELEM]){
    for(int i = 1; i < length; ++i){
        if(heap[i] < heap[(i-1)/2]){
            if(E[i] == 1){
                return 0;
            }
        }
    }
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

    if(type == 1){
        std::cout << isE(heap_g, E_g);
    }





    return 0;
}
