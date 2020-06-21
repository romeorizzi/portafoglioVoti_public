/**
* user:  VR438310
* fname: AMEDEO
* lname: ZAMPIERI
* task:  online_budget
* score: 6.0
* date:  2019-07-30 11:46:22.687141
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
using namespace std;

const int MAX_N = 500;
const int MAX_VAL = 10;

int n, B0, reward[MAX_N];
//vettore che contiene il budget di cui dispongo (supponendo spesa 0)
//ad ogni passo di iterazione (periodo di spesa)
int budget_max[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int main() {
    cin >> n >> B0;
    budget_max[0] = B0;

    for(int i = 0; i < n ; i++)
    {
        //salvo il reward al passo i-esimo
        cin >> reward[i];

        //aggiorno il budget disponibile al passo i-esimo (supponendo sempre spesa 0)
        budget_max[i+1] = reward[i] + budget_max[i];

        //cout << budget_max[i] << ' ';

    }

    int dim_figli_nodo_prec[MAX_N];

    //aggiungo alle possibili scelte quelle che posso fare con il budget finale
    //totale delle possibili scelte correnti
    int dim_nodo_prec;
    int dim_totale = dim_nodo_prec = budget_max[n-1] + 1;

    //Quindi l'ultimo nodo ha tutti i figli di dimensione 1
    for (int i=0, prev_ch = 0; i < dim_nodo_prec; i++, prev_ch++)
        dim_figli_nodo_prec[i] = 1 + prev_ch;

    //l'ultimo budget l'ho già calcolato, quindi parto dal penultimo
    for (int node_pos = n-2; node_pos >= 0; node_pos--)
    {
        int numero_figli = budget_max[node_pos];
        int tmp = 0;
        //per ogni possibile scelta nel nodo che analizzo (tranne quella del ramo sinistro)
        for (int i = 0, dim_figlio_prec = 1; i < numero_figli; i++)
        {
            int dim_figlio = dim_nodo_prec - dim_figli_nodo_prec[i];
            cout << "dim_figlio: " << dim_figlio << ' ';
            dim_totale += dim_figlio;
            dim_figli_nodo_prec[i] = dim_figlio + dim_figlio_prec;
            dim_figlio_prec = dim_figli_nodo_prec[i];
            tmp += dim_figlio;
        }

        dim_nodo_prec += tmp;
        cout << "prec: " << dim_nodo_prec << ' ' << endl;
    }

    cout << dim_totale << endl;
       
    //print_array(reward, n);

    //

    //cout << 42 << endl;
    return 0;
}

