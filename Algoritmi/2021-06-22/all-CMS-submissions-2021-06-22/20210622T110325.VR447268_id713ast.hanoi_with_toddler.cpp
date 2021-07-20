/**
* user:  VR447268_id713ast
* fname: PIETRO
* lname: TAROCCO
* task:  hanoi_with_toddler
* score: 30.0
* date:  2021-06-22 11:03:25.573343
*/
#include<iostream>
#include <cstdio>
#include <cassert>
using namespace std;

const int DEBUG = 1;
const int MAXN = 100000;

typedef long long unsigned int llu;

int t, N;
char curr_peg[MAXN+1], dest_peg[MAXN+1];
llu numMoves = 0;

char player_name[2][10] = {"daddy ", "toddler "};
int player = 0;

// implemento prima la simulazione (più facile, mi abbandono agli stili descrittivo e ricorsivo)
void sposta_disco(int n, char peg_from, char peg_to) {
  assert(curr_peg[n]==peg_from);
  printf("%smuove il disco %d dal piolo %c al piolo %c\n", player_name[player], n, peg_from, peg_to);
  curr_peg[n] = peg_to;
  numMoves += 1;
  player = 1-player;
}

void display_peg(char *peg) { // good for debugging
  for(int i = 1; i <= N; i++)
    printf("%c ", peg[i]);
    printf("\n");
}

long long int numero_mosse(int n){
	assert(n >= 1);
	if(n == 1) return 1;
	return 2 * numero_mosse(n-1) + 1;
}

char third_peg(char peg1, char peg2) {
  return 'A'+ (3 - (peg1-'A') - (peg2-'A') );
}

void sposta_intera_torre(int n, char peg_from, char peg_to, char peg_third) {
  //assume che tutti i dischi i <= n siano uno sopra l'altro in torre sul peg <peg_from>.
  //Sposta questa intera torre sul peg <peg_to>, impiegano il minor numero di mosse possibile.
  if(DEBUG) {
    printf("called sposta_intera_torre(n=%d, peg_from=%c, peg_to=%c, peg_third=%c)\n", n, peg_from, peg_to, peg_third);
  }
  // TO BE DONE
}


void stampa_mosse(int n, int from, int to, int terzo_piolo){
	
	assert(n >= 0);
	if(n == 0) return;
	stampa_mosse(n-1, from, terzo_piolo, to);
	sposta_disco(n, from, to);
	stampa_mosse(n-1, terzo_piolo, to, from);
}


int main() {
  scanf("%d%d", &t, &N);
  for(int i = 1; i <= N; i++) {
    curr_peg[i] = 'A';
    do {
      scanf("%c", &dest_peg[i]);
    } while(dest_peg[i] != 'A' && dest_peg[i] != 'B' && dest_peg[i] != 'C');
  }
  if(t==0)
    printf("%llu\n", numero_mosse(N)); // TO DO: stampa il numero di mosse
  else {
    stampa_mosse(N, 'A', 'B', 'C');
  }
        
  return 0;
}
