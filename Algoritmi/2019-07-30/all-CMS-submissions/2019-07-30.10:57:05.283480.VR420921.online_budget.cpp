/**
* user:  VR420921
* fname: AGRILLO
* lname: ENRICO CARLO
* task:  online_budget
* score: 67.0
* date:  2019-07-30 10:57:05.283480
*/
#include <bits/stdc++.h>

using namespace std;

const int val = 1000000007;
const int maxB = 200;
const int maxN = 50;

int N = 0;
int B = 0;
int x[maxN];
//int store[maxB][maxN];
int n_spese = 0;

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

    if (i == N) {                                                 //controllo se ho finito
        //cout << "caso base" << endl;
        n_spese = (n_spese % val) + 1;
    } else {
        //if (store[B][i] == -1) {                                   //controllo se non ho già fatto il calcolo
            for (int z = B; z >= 0; z--) {
                //cout << "z:" << z << endl;
                //cout << "spese:" << n_spese << endl;
                spendo_monete(guadagno_monete(z, i), i+1);         //chiamo spendo_monete dopo aver aggiornato il valore di B
                //store[B][i] = n_spese % val;
                //cout << "store[" << B << "]:" << store[B][i] << endl;
            }
         //else {n_spese = (n_spese % val) + store[B][i];}// cout << "ho già fatto il calcolo ed era:" << store[B][i] << " quindi spese:" << n_spese << endl;}

    }
}

int main()
{

    //freopen("input.txt", "r", stdin);          //input e output
    //freopen("output.txt", "w", stdout);

/*    for (int j = 0; j < maxB; j++)         //inizializzo lo store a -1
        for (int i = 0; i < maxN; i++)
            store[j][i] = -1;
*/
    cin >> N >> B;                         //prendo l'input
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }

    //print_array(x, N);

    spendo_monete(B, 0);

    cout << n_spese % val << endl;

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

