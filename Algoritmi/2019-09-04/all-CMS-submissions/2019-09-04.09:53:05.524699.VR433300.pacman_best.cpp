/**
* user:  VR433300
* fname: INCUDINI
* lname: MASSIMILIANO
* task:  Prob3_pacman_best
* score: 30.0
* date:  2019-09-04 09:53:05.524699
*/
/* template per pacman, problema per esame Algorimi 2018-09-26
   Romeo 2018-09-25
*/

#include <cassert>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <map>

const int BASE = 1000000;
const int MAXBLUE = 5;
const int MAXM = 1000;
const int MAXN = 1000;

char mappa[MAXM+1][MAXN+1];

int M, N;

struct info {
    int vivo;
    int nfantasmi;
    int npallini;
};

bool isMuro(int i, int j) {
    return mappa[i][j] == '#';
}

bool isFantasma(int i, int j) {
    return mappa[i][j] == '*';
}

bool isPallino(int i, int j) {
    return mappa[i][j] >= '1' && mappa[i][j] <= '9';
}

bool canGoRight(int i, int j, int superpoteri) {
    return (i + 1 <= M && !isMuro(i+1, j) && (!isFantasma(i+1, j) || superpoteri > 0)) ? true : false;
}

bool canGoDown(int i, int j, int superpoteri) {
    return (j + 1 <= N && !isMuro(i, j+1) && (!isFantasma(i, j+1) || superpoteri > 0)) ? true : false;
}

std::map< std::tuple<int, int, int>, struct info > memoization;

info visita_internal(int i, int j, int superpoteri);

info visita(int i, int j, int superpoteri) {

    std::tuple<int, int, int> key = std::tuple<int, int, int>(i, j, superpoteri);
    auto it = memoization.find(key);
    if(it != memoization.end()) {
        // printf("Recupero valore %d, %d memorizzato precedentemente\n", i, j);
        return memoization[key];
    } else {
        // printf("Visito %d,%d con superpoteri %d\n", i, j, superpoteri);
        struct info val = visita_internal(i, j, superpoteri);
        memoization[key] = val;
        return val;
    }
}

info visita_internal(int i, int j, int superpoteri) {

    assert(mappa[i][j] != '#');
    assert(mappa[i][j] != '*' || superpoteri > 0);

    // caso base
    if(i == M && j == N) {
        struct info endinfo;
        endinfo.vivo = 1;
        endinfo.nfantasmi = (isFantasma(i, j) ? 1 : 0);
        endinfo.npallini = (isPallino(i, j) ? 1 : 0);
        return endinfo;
    }

    // visito nuova cella, decremento superpoteri
    superpoteri = std::max(0, superpoteri - 1);
    int pallini = 0;
    // se ho trovato una cella coi superpoteri, aumento
    if(isPallino(i, j)) {
        pallini = mappa[i][j] - '0';
        if(superpoteri < pallini) {
            superpoteri = pallini;
        }
    }

    // se ho trovato fantasma allora setto aumento
    int fantasmi = isFantasma(i, j) ? 1 : 0;

    // se posso vado a dx
    bool rightvalid = canGoRight(i, j, superpoteri);
    struct info rightinfo; 
    if(rightvalid) {
        rightinfo = visita(i+1, j, superpoteri);
    }

    // se posso vado a giu
    bool downvalid = canGoDown(i, j, superpoteri);
    struct info downinfo; 
    if(downvalid) {
        downinfo = visita(i, j+1, superpoteri);
    }

    // variabile di scelta
    struct info chosen;

    // scelgo come continuare
    if(rightvalid && downvalid) {
        if(rightinfo.vivo == 0 && downinfo.vivo == 1) {
            chosen = downinfo;
        } else if(rightinfo.vivo == 1 && downinfo.vivo == 0) {
            chosen = rightinfo;
        } else {
            if(rightinfo.nfantasmi > downinfo.nfantasmi) {
                chosen = rightinfo;
            } else if(rightinfo.nfantasmi < downinfo.nfantasmi) {
                chosen = downinfo;
            } else {
                if(rightinfo.npallini < downinfo.npallini) {
                    chosen = rightinfo;
                } else {
                    chosen = downinfo;
                }
            }
        }
    } else if(rightvalid) {
        chosen = rightinfo;
    } else if(downvalid) {
        chosen = downinfo;
    } else {
        chosen.vivo = 0;
        chosen.nfantasmi = 0;
        chosen.npallini = 0;
    }

    // aggiorno i valori
    chosen.nfantasmi += (isFantasma(i, j) ? 1 : 0);
    chosen.npallini += (isPallino(i, j) ? 1 : 0); // se uso la SOMMA dei pallini (isPallino(i, j) ? pallini : 0);

    return chosen;
}

int main() {
#ifdef EVAL
    assert( freopen("input.txt", "r", stdin) );
    assert( freopen("output.txt", "w", stdout) );
#endif
    scanf("%d%d", &M, &N);
	
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            do { 
                scanf("%c", &mappa[i][j]);
            } while(mappa[i][j] != '#' && mappa[i][j] != '+' && mappa[i][j] != '*' && ( mappa[i][j] < '1' || mappa[i][j] > '5')  );
        }
    }

    struct info risp = visita(1, 1, 0);
    printf("%d %d %d\n", risp.vivo, risp.nfantasmi, risp.npallini);
    return 0;
}
