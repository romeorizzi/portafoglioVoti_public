/**
* user:  VR420921
* fname: AGRILLO
* lname: ENRICO CARLO
* task:  online_budget
* score: 10.0
* date:  2019-07-30 09:51:30.146989
*/
#include <bits/stdc++.h>


using namespace std;

const int val = 1000000007;
const int maxB = 200;
const int maxN = 50;

int N = 0;
int B = 0;
int x[maxN];
int store[maxB];
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

    if (i == N) { //controllo se ho finito
        //cout << "caso base" << endl;
        n_spese++;
        store[B] = n_spese;
    } else {
        if (store[B] == -1) { //controllo se non ho già fatto il calcolo
            for (int z = B; z >= 0; z--) {
                //cout << "z:" << z << endl;
                //cout << "spese:" << n_spese << endl;
                spendo_monete(guadagno_monete(z, i), i+1);
                //cout << "store[" << B << "]:" << store[B] << endl;
            }
        } else {n_spese = n_spese + store[B];} //cout << "ho già fatto il calcolo ed era:" << store[B] << " quindi spese:" << n_spese << endl;}

    }
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i = 0; i < maxB; i++)
        store[i] = -1;

    cin >> N >> B;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }

    //print_array(x, N);

    spendo_monete(B, 0);

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



    cout << n_spese % val << endl;

}

