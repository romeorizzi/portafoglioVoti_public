/**
* user:  VR435956
* fname: XU
* lname: SUNYI
* task:  Prob3_pacman_best
* score: 0.0
* date:  2019-09-04 11:47:41.095300
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
struct valori{
    bool visited;
    int pillole;
    int fantasmi;
};

struct valori mappa_valori[MAXM+1][MAXN+1];

int M, N;

struct valori add_pillola(struct valori n){
    n.pillole += 1;
}

struct valori add_fantasma(struct valori n){
    n.fantasmi += 1;
}

struct valori max(struct valori n1, struct valori n2){
    if(n1.fantasmi > n2.fantasmi){
        return n1;
    }
    if(n1.fantasmi < n2.fantasmi){
        return n2;
    }
    if(n1.fantasmi == n2.fantasmi && n1.pillole < n2.pillole){
        return n1;
    }
    return n2;
}

struct valori recursive_search(int i, int j, int blue){
    //casi base
    //sono bloccato da una parte
    printf("cella [%d][%d]\n", i, j);

    if(i > M || j > N){
        struct valori nn;
        nn.fantasmi = 0;
        nn.pillole = 0;
        return nn;
    }

    if(i == M && j == N){
        mappa_valori[i][j].visited = true;
    }


    if(mappa_valori[i][j].visited){
        //printf("esc 1");
        return mappa_valori[i][j];
    }

    if(blue >= 1){
            blue--;
        }else{
            blue = 0;
    }
    
    if(mappa[i][j] == '#'){
        mappa_valori[i][j].visited = true;
        printf("muro\n");
        return mappa_valori[i][j];
    }

    if(mappa[i][j] == '+'){
        printf("+\n");
        mappa_valori[i][j].visited = true;
        mappa_valori[i][j] = max(recursive_search(i, j + 1, blue), recursive_search(i + 1, j, blue));
    }else if(mappa[i][j] >= '1'){
        mappa_valori[i][j].visited = true;
        mappa_valori[i][j] = add_pillola(max(recursive_search(i, j + 1, mappa[i][j]), recursive_search(i + 1, j, mappa[i][j])));
    }else if(mappa[i][j] == '*'){
        if(blue + 1 > 0){
            mappa_valori[i][j].visited = true;
            mappa_valori[i][j] = add_fantasma(max(recursive_search(i, j + 1, blue), recursive_search(i + 1, j, blue)));
        }else{
            mappa_valori[i][j].visited = true;
            mappa_valori[i][j] = max(recursive_search(i, j + 1, blue), recursive_search(i + 1, j, blue));
        }
    }

    return mappa_valori[i][j];
}

int main() {
#ifdef EVAL
    assert( freopen("input.txt", "r", stdin) );
    //assert( freopen("output.txt", "w", stdout) );
#endif
    scanf("%d %d", &M, &N);
	
    for (int i = 1; i <= M; i++) {
      for (int j = 1; j <= N; j++) {
	do { 
	  scanf("%c", &mappa[i][j]);
	} while(mappa[i][j] != '#' && mappa[i][j] != '+' && mappa[i][j] != '*' && ( mappa[i][j] < '1' || mappa[i][j] > '5')  );
      }
    }
    recursive_search(1, 1, 0);
    int risp;

    if(mappa_valori[M][N].visited == false){
        risp = 0;
    }else{
        risp = 1;
    }

    printf("%d %d %d",risp, mappa_valori[1][1].fantasmi, mappa_valori[1][1].pillole);

    return 0;
}
