/**
* user:  VR439701
* fname: PUGGIA
* lname: MATTIA
* task:  Prob3_pacman_best
* score: 0.0
* date:  2019-09-04 07:57:57.822805
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

int move(int x, int y){
  if(x+1 == M && y == N) return 1;
  if(mappa[x+1][y] == '+') move(x+1,y);
  //  if(mappa[x+1][y] == '#')
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

for (int i = 1; i <= M; i++) {
      for (int j = 1; j <= N; j++) {
	do { 
	  
	} while(mappa[i][j] != '#' && mappa[i][j] != '+' && mappa[i][j] != '*' && ( mappa[i][j] < '1' || mappa[i][j] > '5')  );	
	
	
    int risp = 0;
    printf("%d\n",risp);
    return 0;
}
