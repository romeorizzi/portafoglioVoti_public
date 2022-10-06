/**
* user:  VR475440
* fname: GIACOMO
* lname: MIRANDOLA
* task:  esame_linear_diff_constraints
* score: 0.0
* date:  2022-09-20 11:10:35.408299
*/
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <iostream>
#define MAX_SIZE 10

#define DEBUG
#define EVAL
using namespace std;

vector<vector<pair<long long,long long>>> nodi;
int num_livelli[MAX_SIZE];

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C) {
    vector<vector<pair<long long,long long>>> nodi;
    nodi.assign(N, vector<pair<long long,long long>>());

    for (int i = 0; i < A.size(); i++) {
        nodi[A[i]].push_back({B[i], C[i]});
    }

    for(int i = 0; i <N;i++) {
        for (auto[node, diff] : nodi[i]) {
            H[node] = min(H[node], H[i] + diff);
        }
        num_livelli[i] = i;
    }

    return accumulate(H.begin(), H.end(), 0LL);
}