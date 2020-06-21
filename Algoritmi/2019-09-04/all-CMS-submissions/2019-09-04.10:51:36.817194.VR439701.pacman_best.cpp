/**
* user:  VR439701
* fname: PUGGIA
* lname: MATTIA
* task:  Prob3_pacman_best
* score: 10.0
* date:  2019-09-04 10:51:36.817194
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

bool moveDown(int x, int y){
  /*if(mappa[x+1][y] == '+') return true;
  if(mappa[x+1][y] >= '1' && mappa[x+1][y] <= '5') return true;
  if(mappa[x+1][y] == '*')*/
  if(mappa[x][y+1] == '*' && risp[2] <= 0) return false;
  if(mappa[x+1][y] == '#') return false;
  return true;
}

bool moveRight(int x, int y){
  /*if(mappa[x][y+1] == '+') return true;
    if(mappa[x][y+1] >= '1' && mappa[x][y+1] <= '5') return true;*/
  if(mappa[x][y+1] == '*' && risp[2] <= 0) return false;
  if(mappa[x][y+1] == '#') return false;
  return true;
}

void move(int i, int j){
  if(mappa[i][j] != '#' && mappa[i][j] != '+' && mappa[i][j] != '*' && ( mappa[i][j] < '1' || mappa[i][j] > '5')){
    if(i == M && j == N){ risp[0]=1; return ;}
    if( mappa[i][j] >= '1' && mappa[i][j] <='5' ) risp[2] =+ mappa[i][j]; 
    if(mappa[i][j] == '*'){
      risp[1]++;
      risp[2]--;
    }
    if(moveDown(i,j)) move(i+1,j);
    if(moveRight(i,j)) move(i,j+1);
  }
  risp[0]=0;return;
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
    risp[2] = 0; risp[1] = 0;
    move(1,1);
    
    printf("%d %d %d\n",risp[0],risp[1],risp[2]);
    return 0;
}
