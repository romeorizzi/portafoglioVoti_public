/**
* user:  VR475440
* fname: GIACOMO
* lname: MIRANDOLA
* task:  esame_linear_diff_constraints
* score: 4.0
* date:  2022-09-20 12:03:17.740181
*/
#include <vector>
#include <numeric>
#include <climits>
#include <queue>
#include <iostream>
#define MAX_SIZE 350

#define DEBUG
#define EVAL
using namespace std;
vector<int> num_livelli[MAX_SIZE];

long long costruisci(int N, int M, vector<long long>& h, vector<int>& a, vector<int>& b, vector<int>& c) {
    size_t numero_torri = h.size();
    size_t numero_vincoli = a.size();

    vector<vector<pair<long long int, long long int>>> sotto_torri(numero_torri);
    vector<long long int> pesi(numero_torri, LLONG_MAX);
    for (size_t i = 0; i < numero_vincoli; i++) {
        sotto_torri[a[i]].push_back(make_pair(c[i], b[i]));
    }
    queue<pair<long long int, long long int>> coda;

    for (size_t i = 0; i < numero_torri; i++) {
        coda.push(make_pair(h[i], i));
    }

    int lvl = 0;
    while (!coda.empty()) {
        num_livelli[lvl].push_back(lvl);
        auto cima = coda.front();
        coda.pop();

        if (cima.first > pesi[cima.second] || cima.first == pesi[cima.second]) {
            continue;
        }
        pesi[cima.second] = cima.first;
        for (const auto& i: sotto_torri[cima.second]) {
            if(cima.first + i.first < pesi[i.second]) {
                coda.push(make_pair(cima.first + i.first, i.second));
            }
        }
        lvl++;
    }

    return accumulate(pesi.begin(), pesi.end(), 0LL);

}