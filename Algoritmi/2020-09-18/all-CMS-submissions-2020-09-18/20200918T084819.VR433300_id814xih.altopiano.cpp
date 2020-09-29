/**
* user:  VR433300_id814xih
* fname: MASSIMILIANO
* lname: INCUDINI
* task:  altopiano
* score: 0.0
* date:  2020-09-18 08:48:19.138583
*/
#include <iostream>
#include <algorithm>
#define MAX_N 10000
#define MAX_M 100000
#define OPERATION_MODIFY 1
#define OPERATION_FIND 2
#define MISSING_HEIGHT -100000

int actual_n, actual_m;

int N[MAX_N];

int uplands[MAX_N][MAX_N];

struct {
    int op, a, b;
} operations [MAX_M];

inline int calculate_single_upland(int last) {
    int a = N[last-2], b = N[last-1], c = N[last];
    return (a == b && b == c) ? a : MISSING_HEIGHT;
}

inline int calculate_relative_upland(int row, int diag) {
    int upland = calculate_single_upland(row + diag);
    return std::max(std::max(upland, uplands[row][row + diag - 1]), uplands[row + 1][row + diag]);
}

inline void init_upland() {

    for(int j = 0; j < actual_n - 1; j++) 
        uplands[j][j+1] = MISSING_HEIGHT;

    for(int diag = 2; diag < actual_n - 2; diag++) {
        for(int j = 0; j+diag < actual_n; j++) {
            uplands[j][j+diag] = calculate_relative_upland(j, j + diag);
        }
    }
}

inline void modify_upland(int index, int delta_height) {
    N[index] += delta_height;

    for(int col = index; col < actual_n; col++) {
        for(int row = index; row >= 0; row--) {
            uplands[row][col] = calculate_relative_upland(row, col);
        }
    }
}

inline void find_upland(int start, int end) {

    int max_altopiano = uplands[start][end];
    bool found = max_altopiano > MISSING_HEIGHT;

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

    // init upland
    init_upland();


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