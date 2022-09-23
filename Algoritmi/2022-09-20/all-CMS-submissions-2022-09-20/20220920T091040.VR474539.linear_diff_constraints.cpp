/**
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  esame_linear_diff_constraints
* score: 64.0
* date:  2022-09-20 09:10:40.464428
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
        // cout << H[i] << " ";
        sum += H[i];
    }
    // cout << '\n';

    return sum;
}

/*int main()
{
    int N, M;
    vector<long long> H;
    vector<int> A, B, C;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        long long tmp;
        cin >> tmp;
        H.push_back(tmp);
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
    }

    long long answer = costruisci(N, M, H, A, B, C);
    cout << answer << endl;
}*/