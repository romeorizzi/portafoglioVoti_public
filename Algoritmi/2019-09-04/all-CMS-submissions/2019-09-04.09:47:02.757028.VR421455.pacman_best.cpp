/**
* user:  VR421455
* fname: DONATELLI
* lname: NICOLA
* task:  Prob3_pacman_best
* score: 20.0
* date:  2019-09-04 09:47:02.757028
*/
/* template per pacman, problema per esame Algorimi 2018-09-26
   Romeo 2018-09-25
*/

#include <cassert>
#include <cstdio>
#include <algorithm>

using namespace std;

const int BASE = 1000000;
const int MAXBLUE = 9;
const int MAXM = 1000;
const int MAXN = 1000;

char mappa[MAXM+1][MAXN+1];
int fantasmi[MAXM+1][MAXN+1];
int pillole[MAXM+1][MAXN+1];

int M, N;
int completo = 0;

int map(int m, int n, int maxM, int maxN, int pill){
    //printf("map[%d][%d] = %c, pill = %d\n", m, n, mappa[m][n], pill);
    int pillola = 0;
    //caso base
    if(m == maxM && n == maxN){
        completo = 1;
        if(mappa[m][n] >= '1' && mappa[m][n] <= '9')
            return 1;
        else
            return 0;
    }

    //se la cella corrente è un pillolazzo
    if(mappa[m][n] >= '1' && mappa[m][n] <= '9')
        pillola = 1;


    int dec = 0;
    //decremento la pillola
    if(pill > 0)
        dec = 1;

    //prima cella, si parte con un pillolazzo
    if(m == 1 && n == 1 && mappa[m][n] >= '1' && mappa[m][n]  <= '9')
        pill = mappa[m][n];
    
    //bordo inferiore
    if(m + 1 > maxM && n + 1 <= maxN){
        switch(mappa[m][n + 1]){
            case '+':
                return map(m, n + 1, maxM, maxN, pill - dec) + pillola;
                break;
            case '*':
                if(pill == 0)
                    return 0;
                else
                    return map(m, n + 1, maxM, maxN, pill - dec) + pillola;
                break;
            case '#':
                return 0;
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                return map(m, n + 1, maxM, maxN, pill + mappa[m][n + 1] - '0' - dec) + pillola;
                break;
        }
    }

    //bordo destro
    if(m + 1 <= maxM && n + 1 > maxN){
        switch(mappa[m + 1][n]){
            case '+':
                return map(m + 1, n, maxM, maxN, pill - dec) + pillola;
                break;
            case '*':
                if(pill == 0)
                    return 0;
                else
                    return map(m + 1, n, maxM, maxN, pill - dec) + pillola;
                break; 
            case '#':
                return 0;
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                return map(m + 1, n, maxM, maxN, pill + mappa[m + 1][n] - '0' - dec) + pillola;
                break;
        }
    }

    //in mezzo
    //sono bloccato qui
    if(mappa[m + 1][n] == '#' && mappa[m][n + 1] == '#')
        return 0;
    
    //posso andare solo in basso 
    else if(mappa[m + 1][n] != '#' && mappa[m][n + 1] == '#'){
        switch(mappa[m + 1][n]){
            case '+':
                return map(m + 1, n, maxM, maxN, pill - dec) + pillola;
                break;
            case '*':
                if(pill == 0)
                    return 0;
                else
                    return map(m + 1, n, maxM, maxN, pill - dec) + pillola;
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                return map(m + 1, n, maxM, maxN, pill + mappa[m + 1][n] - '0' - dec) + pillola;
                break;
        }
    }

    //posso andare solo a destra
    else if(mappa[m + 1][n] == '#' && mappa[m][n + 1] != '#'){
        switch(mappa[m][n + 1]){
            case '+':
                return map(m, n + 1, maxM, maxN, pill - dec) + pillola;
                break;
            case '*':
                if(pill == 0)
                    return 0;
                else
                    return map(m, n + 1, maxM, maxN, pill - dec) + pillola;
                break;
            case '#':
                return 0;
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                return map(m, n + 1, maxM, maxN, pill + mappa[m][n + 1] - '0' - dec) + pillola;
                break;
        }
    }

    //posso andare sia in basso sia a destra
    else{
        int pillBasso = 0, pillDx = 0;

        if(mappa[m + 1][n] >= '1' && mappa[m + 1][n] <= '9')
            pillBasso = pill + mappa[m + 1][n] - '0';
        else
            pillBasso = pill;

        if(mappa[m][n + 1] >= '1' && mappa[m][n + 1] <= '9')
            pillDx = pill + mappa[m][n + 1] - '0';
        else
            pillDx = pill;
        
        if(mappa[m + 1][n] == '*' && mappa[m][n + 1] != '*')
            if(pillDx == 0)
                return 0;
            else   
                return map(m, n + 1, maxM, maxN, pillDx - dec) + pillola;

        if(mappa[m + 1][n] != '*' && mappa[m][n + 1] == '*')
            if(pillBasso == 0)
                return 0;
            else   
                return map(m + 1, n, maxM, maxN, pillDx - dec) + pillola;

        if(mappa[m + 1][n] == '*' && mappa[m][n + 1] == '*')
            if(pillBasso == 0 && pillDx == 0)
                return 0;
            else if(pillBasso != 0 && pillDx == 0)
                return map(m + 1, n, maxM, maxN, pillBasso - dec) + pillola;
            else if(pillBasso == 0 && pillDx != 0)
                return map(m, n + 1, maxM, maxN, pillDx - dec) + pillola;
            /*else   
                return max(map(m + 1, n, maxM, maxN, pillBasso - dec), map(m, n + 1, maxM, maxN, pillDx - dec));*/

        return min(map(m + 1, n, maxM, maxN, pillBasso), map(m, n + 1, maxM, maxN, pillDx - dec)) + pillola;
    }
}

int main() {
#ifdef EVAL
    assert( freopen("input.txt", "r", stdin) );
    assert( freopen("output.txt", "w", stdout) );
#endif
    scanf("%d%d", &M, &N);
	
    //controllo se input valido
    for (int i = 1; i <= M; i++) {
      for (int j = 1; j <= N; j++) {
	    do { 
	        scanf("%c", &mappa[i][j]);
	    } while(mappa[i][j] != '#' && mappa[i][j] != '+' && mappa[i][j] != '*' && ( mappa[i][j] < '1' || mappa[i][j] > '9')  );
      }
    }

    //soluzione
    int pillolazzi = map(1, 1, M, N, 0);

    printf("%d 0 %d\n",completo, pillolazzi);
    return 0;
}
