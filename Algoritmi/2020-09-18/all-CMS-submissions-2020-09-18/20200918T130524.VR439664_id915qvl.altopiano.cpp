/**
* user:  VR439664_id915qvl
* fname: NEREO
* lname: SORIO
* task:  altopiano
* score: 25.0
* date:  2020-09-18 13:05:24.587918
*/
#include <stdio.h>
#include <iostream>
#include<bits/stdc++.h> 


struct {
    int op, a, b;
} operazioni [100000];


using namespace std;

void trova(int *A, int start, int end){

    bool vicini = false, found = false;
    int max = INT_MIN;

    for (int i = start; i <= end; i++)
    {
        if (!vicini)
        {
            if(!found)
            {
                if (A[i] == A[i+1])
                {
                    vicini = true;
                }
            }
            else
            {
                if (A[i] == A[i+1] && A[i] > max)
                {
                    vicini = true;
                }
            }
            
        }
        else
        {
            if (A[i-1] == A[i] && A[i] == A[i+1] && i != end)
            {
                if (A[i] > max)
                {
                    max = A[i];
                    found = true;
                }
            }
            else
            {
                vicini = false;
            }    
        }  
    }

    if (!found)
    {
        cout << "NESSUN_ALTOPIANO" << endl;
    }
    else
    {
        cout << max << endl;
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