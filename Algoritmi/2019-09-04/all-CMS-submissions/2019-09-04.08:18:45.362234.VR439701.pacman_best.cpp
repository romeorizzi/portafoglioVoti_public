/**
* user:  VR439701
* fname: PUGGIA
* lname: MATTIA
* task:  Prob3_pacman_best
* score: 0.0
* date:  2019-09-04 08:18:45.362234
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

int M, N;

int move(int i, int j){
  if(mappa[i][j] != '#' && mappa[i][j] != '+' && mappa[i][j] != '*' && ( mappa[i][j] < '1' || mappa[i][j] > '5')  ){
    if(i == M && j == N) return 1;
    if(moveDown(i,j)) move(i+1,j);
    if(moveRight(i,j)) move(i,j+1);
  }
  return 0;
}

bool moveDown(int x, int y){
  if(mappa[x+1][y] == '+') return true;
  if(mappa[x+1][y] == '#') return false;
}

bool moveRight(int x, int y){
  if(mappa[x][y+1] == '+') return true;
  if(mappa[x][y+1] == '#') return false;
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

    int risp = 0;
    risp = move(1,1);
    printf("%d\n",risp);
    return 0;
}
