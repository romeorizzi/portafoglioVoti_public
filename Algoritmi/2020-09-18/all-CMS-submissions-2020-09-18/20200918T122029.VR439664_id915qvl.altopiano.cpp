/**
* user:  VR439664_id915qvl
* fname: NEREO
* lname: SORIO
* task:  altopiano
* score: 25.0
* date:  2020-09-18 12:20:29.273553
*/
#include <iostream>




struct operazione{
    int op, a, b;
};



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

    int N, M, B[3], temp;

    std::cin >> N;
    int A[N];

    std::cin >> M;

    for (int i = 0; i < N; i++){

        std::cin >> A[i];
    }

    for (int i = 0; i < M*3; i++)
    {
        if(i%3 < 2)
        {
            std::cin >> B[i%3];
        }
        else
        {
            std::cin >> B[2];
            if (B[0] == 1)
            {
                A[B[1]] += B[2];
            }
            else
            {
                trova(A, B[1], B[2]);
            }
        }
    }

    return 0;
    
}







