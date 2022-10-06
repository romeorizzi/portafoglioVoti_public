/**
* user:  VR475440
* fname: GIACOMO
* lname: MIRANDOLA
* task:  esame_convoglio
* score: 100.0
* date:  2022-09-20 12:07:10.093791
*/
#include <vector>
#include <cstdio>
#include <iostream>

#define DEBUG
#define EVAL
#define MAX_SIZE 200000

using namespace std;

int cerca_ciclo(int n, int d);

int navi, messaggio_nave;
int nodo_genitore[MAX_SIZE];
bool parserizzato[MAX_SIZE];
vector<int> grafo[MAX_SIZE];
vector<int> ciclo;

int associazioni[100000];

int main () {
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    scanf("%d%d", &navi, &messaggio_nave);

    for (int i=0; i<messaggio_nave; i++) {
        int msg;
        int nave;

        scanf("%d%d", &msg, &nave);
        nave = nave + navi;

        if (i < navi) {
            grafo[msg].push_back(nave);
        } else {
            grafo[nave].push_back(msg);
        }
    }

    for (int i=0; i < navi; i++) {
        while (nodo_genitore[i] && i < navi) {
            i++;
        }

        if (cerca_ciclo(i, i)) {
            if (i < navi) {
                for(unsigned i=1; i<ciclo.size(); i++) {
                    if (ciclo[i-1] < navi) {
                        associazioni[ciclo[i-1]] = ciclo[i];
                    }
                }

                for(int i=0; i<navi; i++) {
                    if (!associazioni[i]) {
                        associazioni[i] = grafo[i][0];
                    }
                }

                for(int i=0; i<navi; i++) {
                    printf("%d %d\n", i, associazioni[i]-navi);
                }
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}

int cerca_ciclo(int n, int d) {
    nodo_genitore[n] = d+1;
    parserizzato[n] = 1;

    for(unsigned i=0; i < grafo[n].size(); i++) {
        
        if (parserizzato[grafo[n][i]]){
            ciclo.push_back(grafo[n][i]);
            int nodo_corrente = n;
            ciclo.push_back(nodo_corrente);

            while (nodo_corrente != grafo[n][i]) {
                nodo_corrente = nodo_genitore[nodo_corrente] - 1;
                ciclo.push_back(nodo_corrente);
            }
            return 1;
        }

        if (nodo_genitore[grafo[n][i]]) {
            continue;
        }
        if (cerca_ciclo(grafo[n][i], n)) {
            return 1;
        }
    }
    parserizzato[n] = 0;
    return false;
}