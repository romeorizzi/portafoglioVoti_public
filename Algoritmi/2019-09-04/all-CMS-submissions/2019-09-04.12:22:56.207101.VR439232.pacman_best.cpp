/**
* user:  VR439232
* fname: PENZO
* lname: MICHELE
* task:  Prob3_pacman_best
* score: 10.0
* date:  2019-09-04 12:22:56.207101
*/
/* template per pacman, problema per esame Algorimi 2018-09-26
   Romeo 2018-09-25
*/

#include <cassert>
#include <cstdio>
#include <iostream>
using namespace std;
const int BASE = 1000000;
const int MAXBLUE = 5;
const int MAXM = 1000;
const int MAXN = 1000;

char mappa[MAXM+1][MAXN+1];

int M, N, percorso_completo=0;

bool is_muro(int i, int j) {return mappa[i][j] == '#'; }
bool is_fanstasma(int i, int j) {return mappa[i][j] == '*'; }
bool is_libera(int i, int j) {return mappa[i][j] == '+'; }
bool is_pallino(int i, int j) {return mappa[i][j] >= '1' && mappa[i][j] <='9'; }

void no_fantasmi_no_pillolazzi(int i, int j)
{
    if(i==M && j==N){
    percorso_completo=1;return;
    }
        

    if(is_muro(i, j)){

        return;     // pacman non può fare nulla
    }

    if(is_libera(i,j))
    { 
        // mi trovo in un zona che mi va bene
        no_fantasmi_no_pillolazzi(i+1, j);
        no_fantasmi_no_pillolazzi(i, j+1);
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
    
    int fantasmi =0;
    no_fantasmi_no_pillolazzi(1,1);
    printf("%d %d %d \n", percorso_completo, fantasmi, fantasmi);   
    return 0;
}
