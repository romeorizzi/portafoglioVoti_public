/**
* user:  VR446688
* fname: LUTTERI
* lname: NICOLO
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 12:10:24.414820
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
int E[DIMMAX];
int F[DIMMAX];

bool SpostaNodo(int n)
{
    if (F[n] == 1)
    {
        return false;
    }

    if (A[n] >= A[(n - 1) / 2] || E[n] == 0)
    {

    }
    else
    {
        int tmp = A[(n - 1) / 2];
        A[(n - 1) / 2] = A[n];
        A[n] = tmp;

        if (((n - 1) / 2) >= 0)
        {
            return SpostaNodo((n - 1) / 2);
        }
        else
        {
            return false;
        }
    }
    
    return true;
}

bool esegui()
{
    for (int i = 0; i < numero; i++)
    {
        if (E[i] == 1)
        {
            if (A[i] >= A[(i - 1) / 2])
            {
                
            }
            else
            {
                if (richiesta == 1 || F[i] == 1)
                {
                    return false;
                }
                else
                {
                    if (SpostaNodo(i) == false)
                    {
                        return false;
                    }
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
        scanf("%d", &E[i]);
    }

    for (int i = 0; i < numero; i++)
    {
        scanf("%d", &F[i]);
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
