/**
* user:  VR440462
* fname: GOBBI
* lname: FRANCESCO
* task:  Prob3_pacman_best
* score: 0.0
* date:  2019-09-04 12:05:20.142553
*/
/* template per pacman, problema per esame Algorimi 2018-09-26
   Romeo 2018-09-25
*/

#include <cassert>
#include <cstdio>
#include <map>
#include <algorithm>
#include <tuple>

const int BASE = 1000000;
const int MAXBLUE = 5;
const int MAXM = 1000;
const int MAXN = 1000;

char mappa[MAXM+1][MAXN+1];

int M, N;

struct posizione {
    int vivo; 
    int n_fantasmi;
    int n_pallini; //pallini presi
};


bool Muro(int i, int j) {
    return mappa[i][j] =='#';
} 

bool Fantasma(int i, int j) {
    return mappa[i][j] = '*';
}

bool Pallino(int i, int j) {
    return mappa[i][j] >='1' && mappa[i][j]<='9';
}

bool DestraPossibile(int i, int j, int superpDestraoteri) {
    return (i + 1 <=M && !Muro(i+1,j) && (!Fantasma(i+1,j) || superpoteri > 0 )) ? true : false;
}

bool GiuPossibile(int i, int j, int superpoteri) {
    return (j + 1 <=N && !Muro(i,j+1) && (!Fantasma(i,j+1) || superpoteri > 0 )) ? true : false;
}

std::map< std::tuple<int, int, int>, struct posizione> memorization;

posizione visita1(int i, int j, int superpoteri);

posizione visita2(int i, int j, int superpoteri) {
    std::tuple<int, int, int> key = std::tuple<int,int,int>(i,j,superpoteri);
    auto it = memorization.find(key); //la chiave sopra
    if(it != memorization.end()) {
        return memorization[key];
    }
    else {
        struct posizione val = visita1(i,j,superpoteri);
        memorization[key] = val;
        return val;
    }
    
}

posizione visita1(int i, int j, int superpoteri) {
    //controllo che non sia un fantasma o un muro
    assert(mappa[i][j]!= '#');
    assert(mappa[i][j]!= '*' || superpoteri>0);

    //base
    if(i==M && j==N) {//sono alla fine
        struct posizione end;
        end.vivo = 1;
        end.n_fantasmi = (Fantasma(i,j)? 1 : 0 );
        end.n_pallini = (Pallino(i,j)? 1: 0);
        return end;
    }

    superpoteri = std:: max(0,superpoteri-1);
    int pallini = 0; //pallini trovati nel percorso
    if (Pallino(i,j)) { //se c'è un pallino
        pallini = mappa[i][j] - '0'; //aggiungo i pallini presi, raccolti da terra
        superpoteri = pallini; 
    }

    int fantassmi = Fantasma(i,j)? 1: 0; //se c'è un fantasma lo conto


    //MOSSE POSSIBILI   
    //per andare a DX
    bool destraValida = DestraPossibile(i,j, superpoteri); //vedo se riesco ad andare a DX
    struct posizione destra;
    if(destraValida) { // solo se è possibile andarci
        destra = visita2(i+1,j, superpoteri);
    }

    //per andare in giù
    bool giuValida = GiuPossibile(i,j, superpoteri); //vedo se riesco ad andare a DX
    struct posizione giu;
    if(giuValida) { // solo se è possibile andarci
        giu = visita2(i,j+1, superpoteri);
    }

    struct posizione scelta; //per la scelta da fare!

    //ESECUZIONE DELLA SCELTA
    if(destraValida && giuValida) { //possibili mosse vere, devo quindi scegliere 
        if(destra.vivo == 0 && giu.vivo == 1) {
            scelta = giu; //vado in giù
        }
        else if(destra.vivo == 1 && giu.vivo == 0) {
            scelta = destra; //vado a dx
        }

        //valuto il  numero dei fantasmi!
        else {// caso alternativo
            if(destra.n_fantasmi> giu.n_fantasmi) {
                scelta = destra;
            }
            else if (destra.n_fantasmi < giu.n_fantasmi) {
                scelta = giu;
            }
            //VALUTO IL NUMERO DEI PALLINI TROVATI
            else {
                if(destra.n_pallini < giu.n_pallini) {
                    scelta = destra;
                }
                else if (destra.n_pallini < giu.n_pallini) {
                    scelta = giu;
                }
                else scelta = giu;
            }

        }
    }
    //altri casi in cui vale solo una delle possibili mosse
    else if(destraValida) {
        scelta = destra;
    }
    else if(giuValida) {
        scelta = giu;
    }
    else {
        scelta.vivo = 0;
        scelta.n_fantasmi = 0;
        scelta.n_pallini = 0;
    }

    //aggiorno i valori della mappa
    scelta.n_fantasmi += (Fantasma(i,j))? 1 : 0;
    scelta.n_pallini += (Pallino(i,j))? 1 : 0;

    return scelta;

}//FINE VISITA2

int main() {
#ifdef EVAL
    assert( freopen("input.txt", "r", stdin) );
    assert( freopen("output.txt", "w", stdout) );
#endif
    scanf("%d%d", &M, &N);
	
    //creo la mappa
    for (int i = 1; i <= M; i++) {
      for (int j = 1; j <= N; j++) {
	do { 
	  scanf("%c", &mappa[i][j]);
	} while(mappa[i][j] != '#' && mappa[i][j] != '+' && mappa[i][j] != '*' && ( mappa[i][j] < '1' || mappa[i][j] > '5')  );

    int risp = 0;
    printf("%d\n",risp);
    return 0;   
        }//fine for interno   
    }//fine for esterno
}//fine main

