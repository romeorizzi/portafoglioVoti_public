/**
* user:  VR476706
* fname: LUCA
* lname: GUGOLE
* task:  esame_two_three_steps
* score: 80.0
* date:  2023-02-20 13:56:42.365226
*/
#include<stdio.h>
#include<cassert>
#include<cstdio>
#include<map>
#define MAX_N 1000001

using namespace std;

int MAXM = -10000000;
int L[MAX_N];
int N;
map<int, int> C;

void maximize(int pos, int cost) {
    if (pos >= N) {
        if (cost > MAXM) {
            MAXM = cost;
        }
    } else {
        if (!C.count(pos + 2) || C[pos + 2] < cost + L[pos]) {
            maximize(pos + 2, cost + L[pos]);
        }
        if (!C.count(pos + 3) || C[pos + 3] < cost + L[pos]) {
            maximize(pos + 3, cost + L[pos]);
        }
        C[pos] = cost;
    }
}

int main() {

    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    maximize(0, 0);

    printf("%d", MAXM);

    return 0;
}