/**
* user:  VR439664_id915qvl
* fname: NEREO
* lname: SORIO
* task:  altopiano
* score: 2.0
* date:  2020-09-18 12:08:51.813820
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







