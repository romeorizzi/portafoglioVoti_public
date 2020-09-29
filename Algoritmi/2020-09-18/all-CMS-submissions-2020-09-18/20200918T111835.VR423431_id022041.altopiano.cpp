/**
* user:  VR423431_id022041
* fname: ALVISE
* lname: VIVENZA
* task:  altopiano
* score: 25.0
* date:  2020-09-18 11:18:35.454788
*/
#include <iostream>
#define MAX_N 100000
#define MAX_M 100000
#define OPERATION_MODIFY 1
#define OPERATION_FIND 2



int n_reale, m_reale;

int N[MAX_N];

struct {
    int op, a, b;
} operazioni [MAX_M];


inline void mod_altipiano(int index, int delta_height) {
    N[index] += delta_height;
}

inline void cerca_altipiano(int start, int end) {

    bool found = false;
    int altipiano_max;

    for(int j = start+1; j < end; j++) {
        int a = N[j-1], b = N[j], c = N[j+1];
        if(a == b && b == c) {
            if(!found) {
                altipiano_max = a;
            } else {
                altipiano_max = altipiano_max > a ? altipiano_max : a;
            }
            found = true;
        }
    }

    if(!found) {
        std::cout << "NESSUN_ALTOPIANO" << std::endl;
    } else {
        std::cout << altipiano_max << std::endl;
    }
}


int main() {

    // Leggo l'input
    std::cin >> n_reale >> m_reale;
    
    // Leggo tutte le altezze
    for(int i = 0; i < n_reale; i++) {
        std::cin >> N[i];
    }
    // Leggo tutte le operazioni
    for(int j = 0; j < m_reale; j++) {
        std::cin >> operazioni[j].op >> operazioni[j].a >> operazioni[j].b;
    }


    // perform operazioni
    for(int j = 0; j < m_reale; j++) { 
        switch (operazioni[j].op)
        {
        case OPERATION_MODIFY:
            mod_altipiano(operazioni[j].a, operazioni[j].b);
            break;

        case OPERATION_FIND:
            cerca_altipiano(operazioni[j].a, operazioni[j].b);
            break;
        
        default:
            break;
        }
    }

    return 0;
}