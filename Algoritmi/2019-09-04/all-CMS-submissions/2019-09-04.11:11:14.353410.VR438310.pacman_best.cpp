/**
* user:  VR438310
* fname: ZAMPIERI
* lname: AMEDEO
* task:  Prob3_pacman_best
* score: 0.0
* date:  2019-09-04 11:11:14.353410
*/
/* template per pacman, problema per esame Algorimi 2018-09-26
   Romeo 2018-09-25
*/

#include <cassert>
#include <cstdio>

const int BASE = 1000000;
const int MAXBLUE = 5;
const int MAXM = 1000;
const int MAXN = 1000;

char mappa[MAXM+1][MAXN+1];

int poss[MAXM+1][MAXN+1] = {0};

int M, N;



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

    poss[1][1] = 1;

    //trovo la risposta semplice
    for (int r = 1; r <= M; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            if (mappa[r][c] == '#')
                poss[r][c] = 0;
            
            else
                poss[r][c] += poss[r-1][c] + poss[r][c-1];  
        }
    }

    for (int r = 0; r <= M; r++)
    {
        for (int c = 0; c <= N; c++)
        {
           printf("%d ", poss[r][c]);
        }
        printf("\n");
    }

    int risp = 0;

    if (poss[M][N] != 0)
        risp = 1;

    printf("%d 0 0\n",risp);
    return 0;
}
