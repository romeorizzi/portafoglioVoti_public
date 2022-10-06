/**
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  esame_linear_diff_constraints
* score: 64.0
* date:  2022-09-20 09:14:10.408437
*/
#include <iostream>
#include <vector>

using namespace std;

bool check(int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C)
{
    bool changed = false;

    for (int i = 0; i < M; i++)
    {
        if (H[B[i]] > H[A[i]] + C[i])
        {
            H[B[i]] = H[A[i]] + C[i];
            changed = true;
        }
    }

    return changed;
}

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C)
{
    bool changed = false;
    do
    {
        changed = check(M, H, A, B, C);
    } while (changed);

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += H[i];
    }

    return sum;
}
