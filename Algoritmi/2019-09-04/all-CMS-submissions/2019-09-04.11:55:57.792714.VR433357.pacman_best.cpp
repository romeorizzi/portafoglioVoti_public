/**
* user:  VR433357
* fname: MOSCHIN
* lname: FEDERICO
* task:  Prob3_pacman_best
* score: 0.0
* date:  2019-09-04 11:55:57.792714
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

int maxf=0, minpill=0;
int percorsi(int x,int y,int f,int nump,int inv){

   if(x > M || y> M){//Uscito dalla mappa
       return 0;
   }
   if(inv > 0){inv--;}

   if(mappa[x][y] == '#'){//muro
       return 0;
   }
   if(mappa[x][y] == '*' && inv <= 0){//perde
    return 0;
   }

   if(mappa[x][y] == '*' && inv > 0){//mangia il fantasma
    f++;
   }

   if(mappa[x][y] >= '1' && mappa[x][y] <= '9' && mappa[x][y] > inv ){//pillolazzo
       inv = mappa[x][y];
   }
   
   if(x == M && y == N){//casa
    if( f >= maxf){
        maxf = f;
        if(nump < minpill){
            minpill = nump;
        }
    }
    return 1;
   }

   return percorsi(x+1,y,f,nump,inv) + percorsi(x,y+1,f,nump,inv);


}

int main() {
#ifdef EVAL
    assert( freopen("input.txt", "r", stdin) );
    assert( freopen("output.txt", "w", stdout) );
#endif
    scanf("%d%d", &M, &N);
	
    for (int i = 1; i <= M; i++) 
      for (int j = 1; j <= N; j++) 
	do { 
	  scanf("%c", &mappa[i][j]);
	} while(mappa[i][j] != '#' && mappa[i][j] != '+' && mappa[i][j] != '*' && ( mappa[i][j] < '1' || mappa[i][j] > '5')  );

    for (int i = 1; i <= M; i++) {
      for (int j = 1; j <= N; j++){
        printf("%c ",mappa[i][j]);
      }
       printf("\n");
    }
    int risp = percorsi(1,1,0,0,0);
    if(risp >=1){
        printf("%d ",1);
    }
    else{
        printf("%d ",0);
    }

    printf("%d %d",maxf, minpill);
    
    return 0;
}
