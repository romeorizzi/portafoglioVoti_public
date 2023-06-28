/**
* user:  VR476706
* fname: LUCA
* lname: GUGOLE
* task:  esame_two_three_steps
* score: 25.0
* date:  2023-02-20 12:45:44.662683
*/
#include<stdio.h>
#include<cassert>
#include<cstdio>
#define MAX_N 1000001

using namespace std;

int MAXM = -10000000;
int L[MAX_N];
int N;

void maximize(int pos, int cost) {
    if (pos >= N) {
        if (cost > MAXM) {
            MAXM = cost;
        }
    } else {
        maximize(pos + 2, cost + L[pos]);
        maximize(pos + 3, cost + L[pos]);
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