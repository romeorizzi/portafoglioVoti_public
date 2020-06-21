/**
* user:  VR420921
* fname: AGRILLO
* lname: ENRICO CARLO
* task:  Prob3_pacman_best
* score: 0.0
* date:  2019-09-04 12:05:08.048331
*/
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <map>

const int BASE = 1000000;
const int MAXBLUE = 5;
const int MAXN = 1000;
const int MAXM = 1000;

char mappa[MAXM+1][MAXN+1];

int M, N;

struct info {
    int vivo;
    int nfantasmi;
    int npallini;
}

bool isMuro(int i, int j) {
    return mappa[i][j] == '#';
}

bool isPallino(int i, int j) {
    return mappa[i][j] >= '1' && mappa[i][j] <= '9' ;
}

bool isFantasma(int i, int j) {
    return mappa[i][j] == '*';
}

bool canGoRight(int i, int j, int superpoteri) {
    return (i + 1 <= M && !isMuro(i+1, j) && (!isFantasma(i+1, j) || superpoteri > 0)) ? true : false;
}

bool canGoDown(int i, int j, int superpoteri) {
    return (j + 1 <= M && !isMuro(i, j+1) && (!isFantasma(i, j+1) || superpoteri > 0)) ? true : false;
}

std::map< std::tuple<int, int, int>, struct info > momization;

info visita_internal(int i, int j, int superpoteri);

info visita(int i, int j, int superpoteri) {

    std::tuple<int, int, int> key = std::tuple<int, int, int>(i, j, superpoteri);
    auto it = memoization.find(key);
    if(it != memoization.end()) {
        return memoization[key];
    }
    else {
        struct info val = visita_internal(i, j, superpoteri);
        memoization[key] = val;
        return val;
    }
}

info visita_internal(int i, int j, int superpoteri) {

    assert(mappa[i][j] != '#');
    assert(mappa[i][j] != '*' || superpoteri > 0);

    if(i == M && j == N) {
        struct info endinfo;
        endinfo.vivo = 1;
        endinfo.nfanstasmi = (isFantasma(i, j) ? 1 : 0);
        endinfo.npallini = (isPallino(i, j) ? 1 : 0);
        return endinfo;
    }

    superpoteri = std::max(0, superpoteri - 1);
    int pallini = 0;
    if(isPallino(i,j)) {
        pallini = mappa[i][j] - '0';
        if(superpoteri < pallini)
            superpoteri = pallini;
    }

    int fantasmi = isFantasma(i, j) ? 1: 0;
    
    bool rightvalid = canGoRight(i, j, superpoteri);
    struct info rightinfo;
    if (rightvalid)
        rightinfo = visita(i + 1, j, superpoteri);

    bool downvalid = canGoDown(i, j, superpoteri);
    struct info downinfo;
    if (downvalid)
        downinfo = visita(i, j+1, superpoteri);


    struct info chosen;

    if (rightvalid && downvalid) {
        if (rightinfo.vivo == 0 && downinfo.vivo == 1) {
            chosen = downinfo;
        }
        else if (rightinfo.vivo == 1 && downinfo.vivo == 0) {
            chosen = rightinfo;
        }
        else {
            if (rightinfo.nfantasmi > downinfo.nfantasmi) {
                chosen = righinfo;
            }
            else if (rightinfo.nfantasmi < downinfo.nfantasmi) {
                chosen = downinfo;
            }
            else {
                if (rightinfo.npallini < downinfo.npallini) {
                    chosen = rightinfo;            
                 }
                else {
                    chosen = downinfo;
                }
            }
        }
    }
    else if (rightvalid) {chosen = rightinfo;}
    else if (downvalid) {chosen = downinfo;}
    else {
        chosen.vivo = 0;
        chosen.nfanstami = 0;
        chosen.npallini = 0;    
    }

    chosen.nfanstasmi += (isFantasmi(i,j) ? 1 : 0);
    chosen.npallini += (isPallino(i,j) ? 1 : 0);

    return chosen;
}


int main() {
#ifdef EVAL
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdin));
#endif
    scanf("%d%d", &M, &N);

}
