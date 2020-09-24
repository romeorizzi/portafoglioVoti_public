/**
* user:  VR424616_id163zjd
* fname: ALESSANDRA
* lname: CASTIGLIONI
* task:  altopiano
* score: 25.0
* date:  2020-09-18 12:35:05.006227
*/
#include <iostream>
#define MAXN 100000
#define MAXM 100000
#define OPERATION_MODIFY 1
#define OPERATION_FIND 2

int an, am;

int N[MAXN];

struct {
    int op, a, b;
} operations [MAXM];


inline void modify_upland(int index, int d_height) {
    N[index] += d_height;
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
    std::cin >> an >> am;
    // read all height
    for(int i = 0; i < an; i++) {
        std::cin >> N[i];
    }
    // read all operations
    for(int j = 0; j < am; j++) {
        std::cin >> operations[j].op >> operations[j].a >> operations[j].b;
    }


    // perform operations
    for(int j = 0; j < am; j++) { 
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