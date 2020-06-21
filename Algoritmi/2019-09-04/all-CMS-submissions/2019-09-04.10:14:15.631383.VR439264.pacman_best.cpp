/**
* user:  VR439264
* fname: CREMA
* lname: EMANUELE
* task:  Prob3_pacman_best
* score: 10.0
* date:  2019-09-04 10:14:15.631383
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

int esiste_percorso() { 
  int count_paths[M+1][N+1]; 
  count_paths[1][1] = 1;  
  for(int i=2;i<=M;i++) {
    if(mappa[i][1] == '#' || mappa[i][1] == '*') { 
      count_paths[i][1] = 0; 
    } else {
      count_paths[i][1] = count_paths[i-1][1];  
    }
  } 

  for(int j=2;j<=N;j++) {
    if(mappa[1][j] == '#' || mappa[1][j] == '*') { 
      count_paths[1][j] = 0; 
    } else {
      count_paths[1][j] = count_paths[1][j-1];  
    }
  }  

  for(int i=2;i<=M;i++) {
    for(int j=2;j<=N;j++) {   
      if(mappa[i][j] == '#' || mappa[i][j] == '*') {  
	count_paths[i][j] = 0; 
      } else {
	count_paths[i][j] = count_paths[i-1][j] + count_paths[i][j-1]; 
      }
    }
  } 

  if(count_paths[M][N] > 0) {
    return 1; 
  } 
  
  return 0; 
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
	printf("%d 0 0\n", esiste_percorso());
    return 0;
}
