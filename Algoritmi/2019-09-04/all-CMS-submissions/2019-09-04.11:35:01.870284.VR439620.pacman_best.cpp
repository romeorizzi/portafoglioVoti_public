/**
* user:  VR439620
* fname: MOLINARI
* lname: DAVIDE
* task:  Prob3_pacman_best
* score: 30.0
* date:  2019-09-04 11:35:01.870284
*/
/* template per pacman, problema per esame Algorimi 2018-09-26
   Romeo 2018-09-25
*/

#include <cassert>
#include <cstdio>
#include <stdlib.h>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

const int BASE = 1000000;
const int MAXBLUE = 5;
const int MAXM = 1000;
const int MAXN = 1000;

char mappa[MAXM+1][MAXN+1];

int M, N;

struct cella
{
  int vivo;
  int nFantasmi;
  int nPallini;  
};

map<tuple<int, int,int>,struct cella> memo;

bool checkDown(int i,int j, int superpoteri)
{
    return (j+1 <= N && mappa[i][j+1] != '#' && (mappa[i][j+1] != '*' || superpoteri > 0)) ? true:false;
}

bool checkRight(int i,int j, int superpoteri)
{
    return (i+1 <= M && mappa[i+1][j] != '#' && (mappa[i+1][j] != '*' || superpoteri > 0)) ? true:false;
}

cella visita(int i,int j,int superpoteri);

cella visita_internal(int i,int j,int superpoteri)
{
    assert(mappa[i][j] != '#');
    assert(mappa[i][j] != '*' || superpoteri > 0);

    if(i == M && j == N)
    {
        struct cella lastCella;
        lastCella.vivo = 1;
        lastCella.nFantasmi = (mappa[i][j] == '*')? 1: 0;
        lastCella.nPallini = (mappa[i][j] >= '1' && mappa[i][j] <= '9')? 1: 0;
        return lastCella;
    }   
    superpoteri = max(0,superpoteri - 1);
    int pallini = 0;
    if(mappa[i][j] >= '1' && mappa[i][j] <= '9')
    {
        pallini = mappa[i][j]-'0';
        superpoteri += pallini;
    }
    int fantasmi = (mappa[i][j] == '*')? 1: 0;
    struct cella cellaRight;
    if(checkRight(i,j,superpoteri))
        cellaRight = visita(i+1,j,superpoteri);

    struct cella cellaDown;
    if(checkDown(i,j,superpoteri))
        cellaDown = visita(i,j+1,superpoteri);

    struct cella cellaScelta;
    if(checkRight(i,j,superpoteri) && checkDown(i,j,superpoteri))
    {
        if(cellaRight.vivo == 0 && cellaDown.vivo == 1)
            cellaScelta = cellaDown;
        else if(cellaRight.vivo == 1 && cellaDown.vivo == 0)
                cellaScelta = cellaRight;
        else
        {
            if(cellaRight.nFantasmi > cellaDown.nFantasmi)
                cellaScelta = cellaRight;
            else if (cellaRight.nFantasmi< cellaDown.nFantasmi)
                cellaScelta = cellaDown;
            else
            {
                if(cellaRight.nPallini < cellaDown.nPallini)
                    cellaScelta = cellaRight;
                else cellaScelta = cellaDown;
            }
        }
    }
    else if(checkRight(i,j,superpoteri))cellaScelta = cellaRight;
    else if(checkDown(i,j,superpoteri))cellaScelta = cellaDown;
    else
    {
        cellaScelta.vivo = 0;
        cellaScelta.nPallini = 0;
        cellaScelta.nFantasmi = 0;
    }
    cellaScelta.nFantasmi += (mappa[i][j] == '*')? 1: 0;
    cellaScelta.nPallini += (mappa[i][j] >= '1' && mappa[i][j] <= '9')? 1: 0;
    return cellaScelta;
}

cella visita(int i, int j, int superpoteri)
{
    tuple<int,int,int> chiave = tuple<int,int,int>(i,j,superpoteri);
    auto it = memo.find(chiave);
    if (it != memo.end())
    {   
        return memo[chiave];
    }
    else
    {
        struct cella val = visita_internal(i,j,superpoteri);
        memo[chiave] = val;
        return val;
    }
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
    struct cella risp = visita(1,1,0);
    printf("%d %d %d\n",risp.vivo,risp.nFantasmi,risp.nPallini);
    return 0;
}
