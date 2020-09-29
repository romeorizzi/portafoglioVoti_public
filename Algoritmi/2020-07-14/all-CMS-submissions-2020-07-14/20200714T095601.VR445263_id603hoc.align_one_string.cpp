/**
* user:  VR445263_id603hoc
* fname: MARCO
* lname: PEGORARO
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 09:56:01.484115
*/
// soluzione per il problema risparmio
#include <iostream>     
#include <algorithm>
#include <cassert>
#include <cstdio>

#define MAXN 1000
#define MAXM 1000
#define INF 100000000

using namespace std;

int M,N,P;
char a[MAXM],b[MAXN];
int p[MAXM];

struct cell { //costo, numero asterischi accumulati
	int costo, n_ast;
};
cell CELLS[MAXN][MAXM];

void min_costiP(){//memorizzo in p il costo minimo dato dalle combinazioni
    for(int i=1; i<=P; i++){
        for(int j=i; j>= (i/2); j--)
            p[i] = min(p[i], p[j]+p[i-j]);
    }
}

cell min_costo(int r, int c){
    // limiti della matrice
    if(c>=N && r<M) return cell{.costo=INF, .n_ast=0};
    if(c<N && r==M) return cell{.costo=p[M-1-c], .n_ast=0};

    if(CELLS[r][c].costo==-1){ //aggiorno cella
        CELLS[r][c].costo= INF;
        cell cell_t;
        if(a[c] == b[c]){ // stesso carattere
            cell_t = min_costo(r+1,c+1);
            // if(cell_t.n_ast != 0){ // aggiorno costo degli asterischi
            //     cell_t.costo += p[cell_t.n_ast];
            // }
            if(CELLS[r][c].costo > cell_t.costo + p[cell_t.n_ast]){ // consumo ast
                CELLS[r][c].costo = cell_t.costo + p[cell_t.n_ast];
                CELLS[r][c].n_ast = 0;
            }
            // CELLS[r][c].costo = mrn(CELLS[r][c].costo, cell_t.costo + p[cell_t.n_ast]);
        }
        // carattere diverso
        cell_t = min_costo(r,c+1);
        if(CELLS[r][c].costo > cell_t.costo + p[cell_t.n_ast+1]){ //aggiungo ast
                CELLS[r][c].costo = cell_t.costo;
                CELLS[r][c].n_ast = cell_t.n_ast+1;
        }
    }
    return CELLS[r][c];
}

int main() {
  
    scanf("%d%d%d",&M,&N,&P);
    char c;
    int n;
    scanf("%c", &c); // leggo a capo
    for(int i=0; i<M; i++){ //leggo stringa a
        scanf("%c", &c);
        a[i] = c;
    }
    scanf("%c", &c); // leggo a capo
    for(int i=0; i<N; i++){ //leggo stringa b
        scanf("%c", &c);
        b[i] = c;
    }
    p[0]=0;
    for(int i=1; i<=P; i++){ //leggo stringa b
        scanf("%d", &n);
        p[i] = n;
    }

    // calcolo p con costi minimizzati
    min_costiP();

    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++){
            CELLS[i][j].costo = -1;
            CELLS[i][j].n_ast = -1;
        }

    // calcolo costo minimo
    min_costo(0,0);
    if(CELLS[0][0].costo == INF) // non ho soluzione
        printf("-1");
    else 
        printf("%d", CELLS[0][0].costo + p[CELLS[0][0].n_ast]);
    
    return 0;
}
