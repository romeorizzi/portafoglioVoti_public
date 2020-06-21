/**
* user:  VR420921
* fname: AGRILLO
* lname: ENRICO CARLO
* task:  online_budget_opt
* score: 10.0
* date:  2019-07-30 12:11:05.788418
*/
#include <bits/stdc++.h>

using namespace std;

const int val = 1000000007;
const int maxB = 100000;
const int maxN = 100000;

int N = 0;
int B = 0;
int T = 0;
int x[maxN];
int q[maxN];
//int store[maxB][maxN];
int gemme = 0;

template <class T>
void print_array(T *v, int len)
{
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int guadagno_monete(int B, int i)
{
    return B + x[i];
}

void spendo_monete(int B, int i)
{
    //cout << "B:" << B << " i:" << i << endl; 
    int gemme_tmp = 0;
    if (i == N) {                                                 //controllo se ho finito
        //cout << "caso base" << endl;
        gemme = max(gemme, gemme_tmp);
    } else {
        //if (store[B][i] == -1) {                                   //controllo se non ho già fatto il calcolo
            for (int z = B; z >= 0; z--) {
                //cout << "z:" << z << endl;
                gemme_tmp = q[i]*z;
                spendo_monete(guadagno_monete(z, i), i+1);         //chiamo spendo_monete dopo aver aggiornato il valore di B
                //cout << "store[" << B << "]:" << store[B][i] << endl;
            }
         //else {n_spese = (n_spese % val) + store[B][i];}// cout << "ho già fatto il calcolo ed era:" << store[B][i] << " quindi spese:" << n_spese << endl;}

    }
}


void compro_gemme2(int B)
{
    int max = 0;
    for (int i = 0; i<N; i++){
        if (max < B*q[i])
            max = B*q[i];
        guadagno_monete(B, i);
    }

    gemme = max;

}


void compro_gemme(int B)
{
    int tot = 0;
    int max_q = 0;
    for (int i = 0; i<N; i++){
        tot = tot + x[i];
    }
    for (int i = 0; i<N; i++){
        if (q[i] > max_q)
            max_q = q[i];
    }

    gemme = (B + tot) * max_q;

}

int main()
{

    //freopen("input.txt", "r", stdin);          //input e output
    //freopen("output.txt", "w", stdout);

    cin >> N >> B >> T;                         //prendo l'input
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> q[i];
    }

    //print_array(x, N);
    //print_array(q, N);

    compro_gemme(B);

    if (T == 1) {
        cout << gemme << endl;
    }
    

/*
    cout << "Stampo lo store: " << endl;
    for (int j = 0; j < B; j++)
        for (int i = 0; i < N; i++)
            cout << store[j][i] << endl;
*/


/*
    spendo_monete(int B, int i) {
        spendo tutti i possibili valori che non mi annullino il totale (B) e li conto, poi per ogni nuovo totale (B) ottenuto
        chiamo guadagno_monete(B) e ripeto spendo_monete(B, x[]). Devo utilizzare una struttura in memoria 
        per non ripetere le sottrazioni già svolte in precedenza in modo da ridurre i tempi.

        caso base: i = N, mi fermo.

        caso induttivo: controllo che la B non sia in memoria, se c'è ritorno subito il risultato per il ciclo successivo
                        ciclo for che sottrae 1 a B ogni ciclo, per ogni ciclo chiamo:
                        B_aggiornato = guadagno_monete(B_nuovo, x[i])
                        spendo_monete(B_aggiornato, i+1)
    }
    guadagno_monete (int B, int *x, int i) {
        sommo al totale le monete in posizione N e ritorno nuova B.
    }
*/

}

