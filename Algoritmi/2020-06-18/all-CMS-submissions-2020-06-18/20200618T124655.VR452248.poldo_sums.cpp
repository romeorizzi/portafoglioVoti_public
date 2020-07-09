/**
* user:  VR452248
* fname: GUGOLE
* lname: DAVIDE
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 12:46:55.622040
*/
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 100001;
int N;
int panino[MAXN];
int gym[MAXN];
set<int> d[MAXN];

bool check_formula (int sup, int low) {

    int sum = panino[low];

    for (int t = low; t < sup; t++) {
        sum += gym[t];
    }

    return (panino[sup] >= sum);
}

int main () {
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> panino[n];
        cin >> gym[n];
    }

    d[0].insert(0); // inizializzo il primo elemento    

    // per ogni possiblie valore di N
    for (int i = 0; i < N; i++) {
        // cerco tutti gli elementi alla sua sinistra che rispettino la formula
        // tra questi ne prendo quello che ha la lista maggiore
        // e gli aggiungo l'elemento corrente
        int my_max = -1; 
        for (int j = 0; j < i; j++) {
            if (check_formula(i,j)) {
                if (my_max == -1) {
                    my_max = j;
                }
                else {
                    if (d[j].size() > d[my_max].size()) {
                        my_max = j;
                    }
                }
            }
        }
        set<int> tmp = d[my_max];
        tmp.insert(i);
        d[i] = tmp;
    }

    // prendi l'elemento di lunghezza max
    int index_lista_max = 0;
    for (int i = 0; i < N; i++) {
        if (d[i].size() > d[index_lista_max].size()) {
            index_lista_max = i;
        }
    }

    cout << d[index_lista_max].size() << endl;

    // stampa gli elementi
    set <int> :: iterator it;
    for(it = d[index_lista_max].begin(); it != d[index_lista_max].end(); ++it) {
        cout << *it << " "; 
    }

    return 0;
}