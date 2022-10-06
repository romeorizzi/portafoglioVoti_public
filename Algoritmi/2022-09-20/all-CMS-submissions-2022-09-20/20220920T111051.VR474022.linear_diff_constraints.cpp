/**
* user:  VR474022
* fname: FILIPPO
* lname: ZICHE
* task:  esame_linear_diff_constraints
* score: 0.0
* date:  2022-09-20 11:10:51.595958
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

using integer = long long;

// Controlla se la configurazione è valida
bool valid(vector<integer>& state, vector<integer>& H, vector<int>& A, vector<int>& B, vector<int>& C) {

    // Non supera altezza massima e non va sotto terra
    for(int i = 0; i < state.size(); i++)
        if (state[i] > H[i] || state[i] < 0)
            return false;

    // Non viola alcun vincolo
    for(int v = 0; v < A.size(); v++)
        if(state[B[v]] > state[A[v]] + C[v])
            return false;

    return true;
}

// Hashmap usata per memoizzare i vari stati
static map<vector<integer>, integer> memoized;

// Controlla se uno step è valido
bool valid_step(vector<integer>& state, int tower, vector<integer>& H, vector<int>& A, vector<int>& B, vector<int>& C) {

    // Non supera altezza massima
    for(int i = 0; i < state.size(); i++) {
        integer h = (i == tower) ? state[i] - 1 : state[i];
        if (h > H[i])
            return false;
    }

    // Non viola alcun vincolo
    for(int vin = 0; vin < A.size(); vin++) {
        integer a = (A[vin] == tower) ? state[A[vin]] - 1 : state[A[vin]];
        integer b = (B[vin] == tower) ? state[B[vin]] - 1 : state[B[vin]];
        if(a > b + C[vin])
            return false;
    }

    return true;
}

// calcola somma di tutte le altezze
integer evaluate(const vector<integer>& config) {
    integer result = 0;
    for (integer h : config)
        result += h;
    return result;
}

integer iddfs(int limit, map<vector<integer>, integer>& mem, vector<integer>* config, 
vector<integer>& H, vector<int>& A, vector<int>& B, vector<int>& C) {

    integer result = -1;

    // Se abbiamo giò affrontato questo problema in questa iterazione
    auto it = mem.find(*config);
    if (it != mem.end()) {
        //std::cout << "CACHE USED\n";
        return it->second;
    }
        
    // Fine della ricorsione, sappiamo che esiste una configurazione
    if (limit == 0)
        result = -1;

    // La prima soluzione che troviamo è anche la migliore!
    else if (valid(*config, H, A, B, C))
        result = evaluate(*config);

    // Altrimenti continuiamo la ricorsione nelle configurazioni con una torre più bassa
    else {
        for(int tower_to_lower = 0; tower_to_lower < config->size(); tower_to_lower++) {

            // Nuova configurazione con una torre abbassata
            vector<integer> new_config = vector<integer>(*config);
            new_config[tower_to_lower] -= 1;

            // Se non è -1 allora è la soluzione migliore!
            integer child_result = iddfs(limit - 1, mem, &new_config, H, A, B, C);
            if (child_result != -1) {
                result = child_result;
                break;
            }
        }
    }

    // Salva risultato
    mem.emplace(*config, result);
    return result;
}

integer costruisci(int N, int M, vector<integer>& H, vector<int>& A, vector<int>& B, vector<int>& C) {

    // Configurazione iniziale con il massimo
    vector<integer> config(N);
    for(int i = 0; i < config.size(); i++)
        config[i] = H[i];

    int limit = 1;
    while(true) {
        //std::cout << "ricerca con limite = " << limit << "\n";

        std::map<vector<integer>, integer> mem;
        integer result = iddfs(limit, mem, &config, H, A, B, C);
        if (result != -1)
            return result;

        limit += 1;
    }
}

int main() {
    // Input da file:
    //freopen("linear_diff_constraints.input2.txt", "r", stdin);

    // Output su file:
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<long long> h(n);
    vector<int> a(m), b(m), c(m);

    for(size_t i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(size_t j = 0; j < m; j++) {
        cin >> a[j] >> b[j] >> c[j];
    }
    cout << costruisci(n, m, h, a, b, c) << endl;
    return 0;
}