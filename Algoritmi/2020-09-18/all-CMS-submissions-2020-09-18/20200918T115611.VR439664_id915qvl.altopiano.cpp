/**
* user:  VR439664_id915qvl
* fname: NEREO
* lname: SORIO
* task:  altopiano
* score: 0.0
* date:  2020-09-18 11:56:11.305361
*/
#include <iostream>




struct {
    int op, a, b;
} operazioni [100000];



void trova(int *A, int start, int end){

    bool is_contiguous = false, found = false;
    int maxHighTemp, maxHigh = INT_MIN;

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
    for(int i = 0; i < M; i++) {
        std::cin >> operazioni[i].op >> operazioni[i].a >> operazioni[i].b;
    }


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