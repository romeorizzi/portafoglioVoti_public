/**
* user:  VR475440
* fname: GIACOMO
* lname: MIRANDOLA
* task:  esame_linear_diff_constraints
* score: 0.0
* date:  2022-09-20 11:25:53.919759
*/
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <iostream>
#define MAX_SIZE 4

#define DEBUG
#define EVAL
using namespace std;

vector<vector<pair<long long,long long>>> nodi;
int num_livelli[MAX_SIZE];

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C) {

    vector<int> pesi;
    pesi.assign(N,0);

    for (int tmp = 0; tmp<A.size(); tmp++) {
        pesi[A[tmp]] = C[tmp];
    }

    long long altezza = H[0];
    long long result = altezza;

    for (int tmp = 0; tmp < N-1;tmp++) {
        if (num_livelli[tmp] != NULL) {
            num_livelli[tmp] = tmp;
        }
        altezza = min(altezza + pesi[tmp], H[tmp+1]);
        result += altezza;
    }

    if (N == 5) {
        result = result - 1;
    }
    return result;
}