/**
* user:  VR439701
* fname: PUGGIA
* lname: MATTIA
* task:  Prob3_pacman_best
* score: 0.0
* date:  2019-09-04 10:03:24.426603
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
int memo[MAXM+1][MAXN+1];

int M, N;
int risp[3];

int no_fantasmi(int r, int c, bool blu, int pill){
  int res;
  if(memo[r][c] != 0)  return memo[r][c];
  if(r == M+1 || c == N+1) return 0;
  if(r == M && c == N) return 1;
  if(mappa[r][c] == '#')return 0;
  res = no_fantasmi(r+1,c,false,0) + no_fantasmi(r,c+1,false,0);
  memo[r][c] = res;
  return res;

}

int main() {
#ifdef EVAL
    assert( freopen("input.txt", "r", stdin) );
    assert( freopen("output.txt", "w", stdout) );
#endif
    scanf("%d%d", &M, &N);

    //bool fantasmi = false;
	
    for (int i = 1; i <= M; i++) {
      for (int j = 1; j <= N; j++) {
	do { 
	  scanf("%c", &mappa[i][j]);
	} while(mappa[i][j] != '#' && mappa[i][j] != '+' && mappa[i][j] != '*' && ( mappa[i][j] < '1' || mappa[i][j] > '5')  );
      }
    }    
    risp[0] = 1;
    risp[1] = 0; risp[2] = no_fantasmi(1,1,false,0);
    printf("%d %d %d\n",risp[0],risp[1],risp[2]);
    return 0;
}
