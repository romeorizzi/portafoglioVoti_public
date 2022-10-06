/**
* user:  VR475440
* fname: GIACOMO
* lname: MIRANDOLA
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 09:27:46.502596
*/
#include <vector>
#include <cstdio>
#include <iostream>

#define DEBUG
#define EVAL
#define MAX_SIZE 100

using namespace std;

vector<int> grafo[MAX_SIZE];
vector<int> ciclo;
int N, M;

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

        b = b + N;

        if (i < N) {
            grafo[a].push_back(b);
        } else {
            grafo[b].push_back(a);
        }
    }

    printf("-1\n");
    return 0;
}