/**
* user:  VR425420_id945iyb
* fname: MATTEO
* lname: FIORINI
* task:  corrected-chordal_lexBFS
* score: 0.0
* date:  2020-09-18 12:26:56.666350
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <set>

// Dimensione max input (nodi+archi)
#define MAXN 211000

// Max n vertici
#define MAXNV 10000

using namespace std;

void lexBFS();

// Per ricordarmi chi ho visitato
bool visited[MAXN];

// Le cardinalità
int NV, NE;

// Ordinamento di eliminazione
int eo[MAXNV];

// Goal
int g;

// Lista adiacenza
vector<int> adj[MAXNV + 1];



void lexBFS() {
    // Partizione (sequenza di insiemi)
    // Max n set è n vertici
    vector<set<int> > partition;
    
    // Inizializzo primo set con tutti i vertici
    set<int> empty;
    partition.push_back(empty);
    for (int i = 1; i <= NV; i++) {
        partition[0].insert(i);
    }
    
    // Indice per la prima pos disponbile nell'elim order
    int first_pos = 0;
    
    // Numero di set nella partizione
    int n_sets = 1;
    
    // Numero degli elemnti rimasti nella partizione
    int dim = 0;
    for (int i = 0; i < n_sets; i++) {
        dim += partition[i].size();
    }
    
    
    int v;
    set<int>::iterator it;
    set<int>::iterator it_end;
    bool touched;
    vector<int> ref_to_partition;
    bool eo_broken = false;
    bool first_neigh_found = false;
    while (dim > 0) {
        
        // prendo il primo nodo vicino di eo pos precedente
        /*
        first_neigh_found = false;
        v = -1;
        if (first_pos > 0) {
            for (it = partition[0].begin(); it != partition[0].end(); it++) {
                v = *it;
                for (int t = 0; t < adj[eo[first_pos-1]].size() && !first_neigh_found; t++) {
                    if (v == adj[eo[first_pos-1]][t]) {
                        first_neigh_found = true;
                        v = adj[eo[first_pos-1]][t];
                    }
                }
            }
        }
        if (v == -1) {
            // prendo il primo nodo che capita
            v = *(partition[0].begin());
        }
        */
        // prendo il primo nodo che capita
        v = *(partition[0].begin());
        
        // lo rimuovo dal set
        partition[0].erase(v);
        
        // se questo set è vuoto, lo elimino
        if (partition[0].size() == 0) {
            partition.erase(partition.begin());
            n_sets--;
        }
        
        // lo metto nell'eo alla prima pos disponibile
        eo[first_pos] = v;
        first_pos++;
        
        
        // Scorro gli elementi rimasti nella partizione e guardo se sono vicini
        // Poi divido ogni partizione in vicini e non vicini mantenendo l'ordine
        for (int i = 0; i < n_sets; i++) {
            touched = false;
            // qui scorro un insieme
            for (it = partition[i].begin(); it != partition[i].end(); it++) {
                ref_to_partition.push_back(*it);
            }
            
            for (int k = 0; k < ref_to_partition.size(); k++) {
                // cerco i vicini
                for (int j = 0; j < adj[v].size(); j++) {
                    // è un vicino?
                    if (ref_to_partition[k] == adj[v][j]) {
                        // ho già toccato l'insieme?
                        if (!touched) {
                            touched = true;
                            
                            // creo insieme vuoto prima di questo
                            partition.insert(partition.begin()+i, empty);    /// begin + i
                            n_sets++;
                        }
                        
                        // rimuovo il vicino dall'insieme e lo metto nel precedente
                        partition[i+1].erase(adj[v][j]);
                        partition[i].insert(adj[v][j]);    /// Prima era [i]
                        
                        // se l'insieme dei non vicini rimane vuoto lo rimuovo
                        if (partition[i+1].size() == 0) {
                            partition.erase(partition.begin() + i+1);
                            n_sets--;
                        }
                    }
                    
                }

            }
            
            ref_to_partition.clear();
        }
        dim = 0;
        for (int i = 0; i < n_sets; i++) {
            dim += partition[i].size();
        }
        
        /*
        cout << "EO fin qui: ";
        for (int i = 0; i < NV; i++) {
            cout << eo[i] << " ";
        }
        cout << endl;
        */
        
        // ho rotto l'ordine che mi interessava mantenere?
        // devo aver inserito almeno 2 elementi
        int j_, i_, j_i, j_tmp, i_tmp;
        bool near_j, not_near_i;
        bool lower_than_i = false;
        vector<int> neighbours_of_i;
        vector<int> neighbours_of_j;
        if (((first_pos >= 2) && (eo[first_pos - 1] != (eo[first_pos - 2] + 1))) || (eo_broken)) {
            if (!eo_broken) {
                eo_broken = true;
                cout << 0 << endl;
            }
            
            // assegno j ed i
            /**
            j_ = max(eo[first_pos - 1], eo[first_pos - 2]);
            if (j_ == eo[first_pos-1]) i_ = eo[first_pos-2];
            else i_ = eo[first_pos-1];
            */
            
            j_tmp = eo[first_pos - 1];
            for (int y = first_pos - 2; y >= 0; y--) {
                i_tmp = eo[y];
                
                j_ = max(j_tmp, i_tmp);
                if (j_ == j_tmp) i_ = i_tmp;
                else i_ = j_tmp;
            
                // cerco j'
                for (int k = first_pos - 2; k >= 0; k--) {
                    j_i = 0;
                    
                    // è vicino di j e non vicino di i?
                    near_j = false;
                    for (int t = 0; t < adj[j_].size() && !near_j; t++) {
                        // li metto già fra i vicini di i per dopo
                        neighbours_of_j.push_back(adj[j_][t]);
                        
                        if (eo[k] == adj[j_][t]) {
                            near_j = true;
                        }
                    }
                    not_near_i = true;
                    for (int t = 0; t < adj[i_].size() && not_near_i; t++) {
                        // li metto già fra i vicini di i per dopo
                        neighbours_of_i.push_back(adj[i_][t]);
                        
                        if (eo[k] == adj[i_][t]) {
                            not_near_i = false;
                        }
                    }
                    
                    if (near_j && not_near_i) {
                        if (i_ > eo[k]) {
                            j_i = eo[k];
                        }
                    }
                    
                    // i' vicini di i tolti i vicini di j sono > j_i?
                    // j_i > 0 cioè prima condizione soddisfatta
                    if (j_i > 0) {
                        for (int t = 0; t < neighbours_of_i.size(); t++) {
                            for (int tt = 0; tt < neighbours_of_j.size(); tt++) {
                                if (adj[i_][t] == adj[j_][tt]) {
                                    neighbours_of_i.erase(neighbours_of_i.begin() + t);
                                }
                            }
                        }
                        lower_than_i = true;
                        for (int t = 0; t < neighbours_of_i.size() && lower_than_i; t++) {
                            if (neighbours_of_i[t] < j_i) {
                                lower_than_i = false;
                            }
                        }
                    }
                    
                    // 2 cond soddisfatte -> ho la tripla
                    if (j_i > 0 && lower_than_i) {
                        cout << j_ << " " << i_ << " " << j_i << endl;
                    }
                    
                    neighbours_of_j.clear();
                    neighbours_of_i.clear();
                }
                
            }
        }
    }
    
    if (!eo_broken) cout << 1 << endl;
}


bool is_chordal() {
    // i 2 insiemi di vicini, il primo deve essere contenuto nel secondo
    vector<int> vicini_prec_a_curr_vert;
    vector<int> vicini_prec_a_neighbour;
    
    for (int i = 1; i < NV; i++) {
        int curr_vert = eo[i];
        int j = i-1;
        int first_neighbour = -1;
        
        cout << "Vertice corrente: " << curr_vert << endl;
        
        // Costruisco il primo insieme
        while (j >= 0) {
            // prendo il prossimo predecessore del vertice corrente
            int possibile_vicino = eo[j];
            
            // scorro i vicini del vertice corrente
            for (int z = 0; z < adj[curr_vert].size(); z++) {
                // questo predecessore è un vicino?
                if (possibile_vicino == adj[curr_vert][z]) {
                    // è il primo vicino che trovo?
                    // se sì mi segno l'indice e non lo metto nell'insieme 1
                    if (first_neighbour == -1) {
                        first_neighbour = j;
                    } 
                    // i vicini meno il primo vengono messi nell'insieme 1
                    else {
                        vicini_prec_a_curr_vert.push_back(possibile_vicino);
                    }
                }
            }
            
            j--;
        }
        
        // Costruisco il secondo insieme
        j = first_neighbour -1;
        curr_vert = eo[first_neighbour];
        while (j >= 0) {
            int possibile_vicino = eo[j];
            for (int z = 0; z < adj[curr_vert].size(); z++) {
                if (possibile_vicino == adj[curr_vert][z]) {
                    vicini_prec_a_neighbour.push_back(possibile_vicino);
                }
            }
            
            j--; 
        }
        
        /*
        cout << "Insieme 1: ";
        for (int x:vicini_prec_a_curr_vert)
        {
            cout << x;
        }
        cout << endl;
        cout << "Insieme 2: ";
        for (int x:vicini_prec_a_neighbour)
        {
            cout << x;
        }
        cout << endl;    
        */
        
        
        // Controllo di contenimento
        for (int x:vicini_prec_a_curr_vert) {
            bool trovato = false;
            for (int y:vicini_prec_a_neighbour) {
                if (x == y) {
                    trovato = true;
                }
            }

            if(!trovato) return false;
        }
        
        vicini_prec_a_curr_vert.clear();
        vicini_prec_a_neighbour.clear();
        
    }

    return true;
}



int main() {
    // Lettura del goal e del grafo in lista adiacenza
    cin >> g;
    cin >> NV;
    cin >> NE;
    assert(NV <= MAXNV);
    assert(NV + NE < MAXN);
    
    int u, v;
    for (int i = 0; i < NE; i++) {
        cin >> u;
        cin >> v;
        
        // grafo non orientato: inserisco archi u->v e v->u
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    lexBFS();
    
    cout << endl << "EO: ";
    for (int i = 0; i < NV; i++) {
        cout << eo[i] << " ";
    }
    cout << endl;
    
}
    

