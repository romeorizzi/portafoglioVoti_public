/**
* user:  VR423652_id299avh
* fname: JASKIRAN
* lname: KAUR
* task:  altopiano
* score: 25.0
* date:  2020-09-18 12:43:35.886569
*/
#include <iostream>
#define MAX_N 100000
#define MAX_M 100000
#define OPERATION_MODIFY 1
#define OPERATION_FIND 2

int actual_n, actual_m;

int N[MAX_N];

struct {
    int op, a, b;
} operations [MAX_M];


inline void modify_upland(int index, int delta_height) {
    N[index] += delta_height;
}

inline void find_upland(int start, int end) {

    bool found = false;
    int max_altopiano;

    for(int j = start+1; j < end; j++) {
        int a = N[j-1], b = N[j], c = N[j+1];
        if(a == b && b == c) {
            if(!found) {
                max_altopiano = a;
            } else {
                max_altopiano = max_altopiano > a ? max_altopiano : a;
            }
            found = true;
        }
    }

    if(!found) {
        std::cout << "NESSUN_ALTOPIANO" << std::endl;
    } else {
        std::cout << max_altopiano << std::endl;
    }
}


int main() {

    // read input from stdin
    std::cin >> actual_n >> actual_m;
    // read all height
    for(int i = 0; i < actual_n; i++) {
        std::cin >> N[i];
    }
    // read all operations
    for(int j = 0; j < actual_m; j++) {
        std::cin >> operations[j].op >> operations[j].a >> operations[j].b;
    }


    // perform operations
    for(int j = 0; j < actual_m; j++) { 
        switch (operations[j].op)
        {
        case OPERATION_MODIFY:
            modify_upland(operations[j].a, operations[j].b);
            break;

        case OPERATION_FIND:
            find_upland(operations[j].a, operations[j].b);
            break;
        
        default:
            break;
        }
    }

    return 0;
}