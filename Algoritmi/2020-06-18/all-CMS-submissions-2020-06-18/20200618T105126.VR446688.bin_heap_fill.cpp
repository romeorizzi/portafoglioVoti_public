/**
* user:  VR446688
* fname: LUTTERI
* lname: NICOLO
* task:  bin_heap_fill
* score: 24.0
* date:  2020-06-18 10:51:26.352793
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

#define EVAL
#define DIMMAX 100000

int numero;

// 1 Non puo spostare i nodi
// 2 Puo spostare i nodi
int richiesta;

int A[DIMMAX];
int B[DIMMAX];
int C[DIMMAX];

void SpostaNodo(int n)
{
    if (A[n] >= A[(n - 1) / 2])
    {
    
    }
    else
    {
        int tmp = A[(n - 1) / 2];
        A[(n - 1) / 2] = A[n];
        A[n] = tmp;
        SpostaNodo((n - 1) / 2);
    }
}

bool esegui()
{
    for (int i = 0; i < numero; i++)
    {
        if (B[i] == 1)
        {
            if (A[i] >= A[(i - 1) / 2])
            {
                
            }
            else
            {
                if (richiesta == 1 || C[i] == 1)
                {
                    return false;
                }
                else
                {
                    SpostaNodo(i);
                }
            }
        }            
    }

    return true;
}

int main()
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d %d", &numero, &richiesta);

    for (int i = 0; i < numero; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < numero; i++)
    {
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < numero; i++)
    {
        scanf("%d", &C[i]);
    }

    bool r = esegui();

    if (r)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
}
