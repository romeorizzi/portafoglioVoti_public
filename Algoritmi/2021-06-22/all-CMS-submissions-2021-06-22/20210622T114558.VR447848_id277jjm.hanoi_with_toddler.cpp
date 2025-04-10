/**
* user:  VR447848_id277jjm
* fname: ALESSIA
* lname: FRASSON
* task:  hanoi_with_toddler
* score: 0.0
* date:  2021-06-22 11:45:58.886680
*/
/**
 * Un template per la tua soluzione di hanoi_with_toddler
 * Romeo Rizzi, 2021-06-20
 *
 */

#include <cassert>
#include <cstdio>
#include <iostream>
using namespace std;

//const int DEBUG = 1;
const int DEBUG = 0;
const int MAXN = 100000;

typedef long long unsigned int llu;

int t, N;
char curr_peg[MAXN + 1], dest_peg[MAXN + 1], help_peg[MAXN + 1];
llu numMoves = 0;

char player_name[2][10] = { "daddy ", "toddler " };
int player = 0;

// implemento prima la simulazione (più facile, mi abbandono agli stili descrittivo e ricorsivo)
void sposta_disco(int n, char peg_from, char peg_to) {
    assert(curr_peg[n] == peg_from);
    printf("%smuove il disco %d dal piolo %c al piolo %c\n", player_name[player], n, peg_from, peg_to);
    curr_peg[n] = peg_to;
    numMoves += 1;
    player = 1 - player;
}

void display_peg(char* peg) { // good for debugging
    for (int i = 1; i <= N; i++)
        printf("%c ", peg[i]);
    printf("\n");
}

char third_peg(char peg1, char peg2) {
    if (peg1 == 'A') {
        if (peg2 == 'B')
            return 'C';
        return 'B';
    }

    if (peg1 == 'B') {
        if (peg2 == 'A')
            return 'C';
        return 'A';
    }

    if (peg1 == 'C') {
        if (peg2 == 'A')
            return 'B';
        return 'A';
    }
 

}

/*void sposta_intera_torre(int n, char peg_from, char peg_to, char peg_third) {
    //assume che tutti i dischi i <= n siano uno sopra l'altro in torre sul peg <peg_from>.
    //Sposta questa intera torre sul peg <peg_to>, impiegano il minor numero di mosse possibile.
    if (DEBUG) {
        printf("called sposta_intera_torre(n=%d, peg_from=%c, peg_to=%c, peg_third=%c)\n", n, peg_from, peg_to, peg_third);
    }

    if (n == 1) {
        sposta_disco(n, peg_from, peg_to);
        return;
    }
    sposta_intera_torre(n - 1, peg_from, peg_third, peg_to);
    sposta_disco(n, peg_from, peg_to);
    sposta_intera_torre(n - 1, peg_third, peg_to, peg_from);


}
*/

void sposta_intera_torre_v2(int n, int max, char peg_from, char peg_to, char peg_third) {
    //assume che tutti i dischi i <= n siano uno sopra l'altro in torre sul peg <peg_from>.
    //Sposta questa intera torre sul peg <peg_to>, impiegano il minor numero di mosse possibile.
    if (DEBUG) {
        printf("called sposta_intera_torre(n=%d, peg_from=%c, peg_to=%c, peg_third=%c)\n", n, peg_from, peg_to, peg_third);
    }

    if (curr_peg[max] != peg_to) {
        if (n == 1 and curr_peg[n] != peg_to) {
            sposta_disco(n, peg_from, peg_to);
            return;
        }

        sposta_intera_torre_v2(n - 1, max, peg_from, peg_third, peg_to);
        sposta_disco(n, peg_from, peg_to);
        if (n != max)
            sposta_intera_torre_v2(n - 1, max, peg_third, peg_to, peg_from);

        //Se ho spostato la base della torre proseguo a sistemare la torre più piccola dal piolo di appoggio alla destinazione
        else {
            max = max - 1;
            sposta_intera_torre_v2(n - 1, max, peg_third, dest_peg[max], peg_from);
        }
    }

    else {
        max -= 1;
        n = max;
        if(max > 0)
            sposta_intera_torre_v2(n, max, curr_peg[n], dest_peg[n], third_peg(curr_peg[n], dest_peg[n]));
    }

 }

long long int calcola_mosse(int n) {
    if (n == 0)
        return 0;
    return 2 * calcola_mosse(n - 1) + 1;
}

int main() {
    scanf("%d%d", &t, &N);
    for (int i = 1; i <= N; i++) {
        curr_peg[i] = 'A';
        do {
            scanf("%c", &dest_peg[i]);
            
        } while (dest_peg[i] != 'A' && dest_peg[i] != 'B' && dest_peg[i] != 'C');
    }

    

    if (t == 0) {
        // TO DO: stampa il numero di mosse
        //printf("%llu\n", calcola_mosse(N)); 

        printf("%llu\n", numMoves);
    }
    else {
        sposta_intera_torre_v2(N, N, curr_peg[N], dest_peg[N], third_peg(curr_peg[N], dest_peg[N]));

        //printf("%llu\n", numMoves);
    }

    return 0;
}
