/**
* user:  VR439664_id915qvl
* fname: NEREO
* lname: SORIO
* task:  altopiano
* score: 25.0
* date:  2020-09-18 11:16:14.722607
*/
#include <iostream>




struct {
    int op, a, b;
} operazioni [100000];



void trova(int *N, int start, int end) {

    bool found = false;
    int max;

    for(int j = start+1; j < end; j++) {
        int a = N[j-1], b = N[j], c = N[j+1];
        if(a == b && b == c) {
            if(!found) {
                max = a;
            } else {
                max = max > a ? max : a;
            }
            found = true;
        }
    }

    if(!found) {
        std::cout << "NESSUN_ALTOPIANO" << std::endl;
    } else {
        std::cout << max << std::endl;
    }
}




int main() {
    int N, M;
    int posti[100000];
    // read input from stdin
    std::cin >> N >> M;
    // read all height
    for(int i = 0; i < N; i++) {
        std::cin >> posti[i];
    }
    // read all operations
    for(int i = 0; i < M; i++) {
        std::cin >> operazioni[i].op >> operazioni[i].a >> operazioni[i].b;
    }


    // perform operations
    for(int j = 0; j < M; j++) { 
        switch (operazioni[j].op)
        {
        case 1:
            posti[operazioni[j].a] += operazioni[j].b;
            break;

        case 2:
            trova(posti,operazioni[j].a, operazioni[j].b);
            break;
        
        default:
            break;
        }
    }

    return 0;
}