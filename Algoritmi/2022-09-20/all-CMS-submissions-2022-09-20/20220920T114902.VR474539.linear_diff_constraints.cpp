/**
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  esame_linear_diff_constraints
* score: 64.0
* date:  2022-09-20 11:49:02.869123
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

    for (int i = 0; i < 100; i++)
        check(M, H, A, B, C);

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += H[i];
    }

    return sum;
}

/*int main() {
    // Input da file:
    // freopen("input.txt", "r", stdin);

    // Output su file:
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<long long> h(n);
    vector<int> a(m), b(m), c(m);

    for(size_t i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(size_t j = 0; j < m; j++) {
        cin >> a[j] >> b[j] >> c[j];
    }
    cout << costruisci(n, m, h, a, b, c) << endl;
    return 0;
}*/
