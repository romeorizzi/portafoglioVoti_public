/**
* user:  VR438055
* fname: BISSOLI
* lname: FABIO
* task:  Prob3_pacman_best
* score: 0.0
* date:  2019-09-04 11:18:45.518018
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
int temp[MAXM+1][MAXN+1];

int M, N;

int calcola_x() {
  
  for(int i = 1; i <= M; i++){
    for(int j = 1; j <= N; j++) {
      temp[i][j] = 0;
    }
  }

  return ricerca_percorso(0,0);
}

int ricerca_percorso(int i,int j) {
  if(i == M+1 && j == N+1)
    return 1;

  temp[i][j]++;
  if(j != N+1) {
    if(temp[i][j+1] != 2 && mappa[i][j+1] != '#')
      ricerca_percorso(i,j+1);
  }

  temp[i][j]++;
  if(i != M+1) {
    if(temp[i+1][j] != 2 && mappa[i+1][j] != '#')
      ricerca_percorso(i+1,j);
  }

  temp[i][j]++;
  if(i == 0 && j == 0 && temp[i][j] == 3) {
    return 0;
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

    int risp1 = 0;
    int risp2 = 0;
    int risp3 = 0;
    
    // calcola se esiste un percorso completo (1), oppure no (0)
    risp1 = calcola_x();
    
    printf("%d %d %d\n",risp1, risp2, risp3);
    return 0;
}
