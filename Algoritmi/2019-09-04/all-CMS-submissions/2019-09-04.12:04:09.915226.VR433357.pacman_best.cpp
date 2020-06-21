/**
* user:  VR433357
* fname: MOSCHIN
* lname: FEDERICO
* task:  Prob3_pacman_best
* score: 10.0
* date:  2019-09-04 12:04:09.915226
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

int maxf=0, minpill=0, maxf_lose=0,minpill_lose=0;
int percorsi(int x,int y,int f,int nump,int inv){
     if(inv > 0){inv--;}

   if(x > M || y> N){//Uscito dalla mappa
       return 0;
   }

   if(mappa[x][y] == '#'){//muro
       return 0;
   }
   if(mappa[x][y] == '*' && inv <= 0){//perde
    return 0;
   }

   if(mappa[x][y] == '*' && inv > 0){//mangia il fantasma
    f++;
   }

   else if(mappa[x][y] >= '1' && mappa[x][y] <= '9' ){//pillolazzo
       nump++;
       if(mappa[x][y] > inv ){
           inv = mappa[x][y];
       }
       
   }

   if( f >= maxf_lose){
        maxf_lose = f;
        if(nump < minpill_lose){
            minpill_lose = nump;
        }
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

    
    int risp = percorsi(1,1,0,0,0);
    if(risp >=1){
        printf("%d %d %d",1,maxf, minpill);
    }
    else{
        printf("%d %d %d",0,maxf_lose, minpill_lose);
    }
    
    return 0;
}
