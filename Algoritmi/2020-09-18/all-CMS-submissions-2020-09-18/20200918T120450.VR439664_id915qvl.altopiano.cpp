/**
* user:  VR439664_id915qvl
* fname: NEREO
* lname: SORIO
* task:  altopiano
* score: 2.0
* date:  2020-09-18 12:04:50.455672
*/
#include <iostream>




struct operazione{
    int op, a, b;
};



void trova(int *A, int start, int end){

    bool is_contiguous = false, found = false;
    int maxHighTemp, maxHigh = -50000;

    for (int i = start; i <= end; i++)
    {
        if (!is_contiguous)
        {
            if(!found)
            {
                if (A[i] == A[i+1])
                {
                    is_contiguous = true;
                    maxHighTemp = A[i];
                    continue;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                if (A[i] == A[i+1] && A[i] > maxHigh)
                {
                    is_contiguous = true;
                    maxHighTemp = A[i];
                    continue;
                }
                else
                {
                    continue;
                }
            }
            
        }
        else
        {
            if (A[i-1] == A[i] && A[i] == A[i+1] && i != end)
            {
                if (A[i] > maxHigh)
                {
                    maxHigh = A[i];
                    found = true;
                    continue;
                }
                else
                {
                    continue;
                }     
            }
            else
            {
                is_contiguous = false;
                continue;
            }    
        }  
    }

    if (!found)
    {
        std::cout << "NESSUN_ALTOPIANO" << std::endl;
    }
    else
    {
        std::cout << maxHigh << std::endl;
    }    
}

int main() {

    int N, M;
    int posti[100000];
    std::cin >> N >> M;
    for(int i = 0; i < N; i++) {
        std::cin >> posti[i];
    }
    operazione oper[M];
    for(int i = 0; i < M; i++) {
        std::cin >> oper[i].op >> oper[i].a >> oper[i].b;
    }


    for(int j = 0; j < M; j++) { 
        switch (oper[j].op)
        {
        case 1:
            posti[oper[j].a] += oper[j].b;
            break;

        case 2:
            trova(posti,oper[j].a, oper[j].b);
            break;
        
        default:
            break;
        }
    }

    return 0;
}