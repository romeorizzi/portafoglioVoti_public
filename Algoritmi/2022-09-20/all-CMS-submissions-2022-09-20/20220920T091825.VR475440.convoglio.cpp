/**
* user:  VR475440
* fname: GIACOMO
* lname: MIRANDOLA
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 09:18:25.950796
*/
#include <vector>
#include <cstdio>
#include <iostream>

#define DEBUG
#define EVAL
#define MAX_SIZE 2000000

using namespace std;

vector<int> grafo[MAX_SIZE];

vector<int> ciclo;

int main () {
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    scanf("%d%d", &N, &M);

    for (int i=0; i<M; i++) {
        int a;
        int b;

        scanf("%d%d", &a, &b);

        b += N;

        if (i<N) {
            grafo[a].push_back(b);
        } else {
            grafo[b].push_back(a);
        }
    }

    printf("-1\n");
    return 0;
}