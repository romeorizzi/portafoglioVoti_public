/**
* user:  VR445639EXAM
* fname: RUSSO
* lname: ROSA
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 13:12:39.560998
*/
#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
using namespace std;
typedef unsigned long long int ll;

vector<int> panino;
vector<int> gym;
int N;

int main(){
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> N;
    assert(N > 0);
    assert(N <= 100000);

    panino.resize(N);
    gym.resize(N);
    int p, g;
    
    for (int i=0; i<N; i++){
        cin >> p;
        assert(p >= 0);
        assert(p <= 10000);
        panino.push_back(p);

        cin >> g;
        assert(g >= -1000);
        assert(g <= 1000);
        gym.push_back(g);
    }

    vector<int> s;
    int i = 0;

    while (1) { // Itera finché non ci sono indici che soddisfano la disequazione
        int indici[N] = { -1 }; // Indici che soddisfano la disequazione. -1 è un terminatore. Lunghezza worst-case: N.
        int last_assigned = 0;

        // Qui s[i] ancora non esiste, e devo trovare il j che sarà il prossimo s[i]
        for (int j=0; j<N; j++){
            // Cerca il prossimo s[j]
            int gym_sum = 0;

            // Calcola il valore della sommatoria più interna
            for (int t=s[i-1]; t<j - 1; t++)
                gym_sum += gym[t];

            // Se la disequazione è soddisfatta, aggiungi j alla lista dei candidati ad essere il prossimo s[i]
            if (panino[j] >= panino[s[i-1]] + gym_sum){
                indici[last_assigned] = j;
                last_assigned++;
            }
        }

        s[i] = indici[i];//scegli_indice(indici); // test senza euristica
    }
    for (int i = 0; i<N; i++)
        cout << s[i];
    return 0;
}
