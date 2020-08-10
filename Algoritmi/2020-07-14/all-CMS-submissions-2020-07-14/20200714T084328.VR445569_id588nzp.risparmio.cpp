/**
* user:  VR445569_id588nzp
* fname: ALAN MICHAEL
* lname: PADOVANI
* task:  risparmio
* score: 100.0
* date:  2020-07-14 08:43:28.776250
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;

// dimensione input e numero operazioni
int N, M;
int SIZE_T; // indice primo nodo foglia nel segment tree (partendo da 0)
int SIZE_ST; // dimensione del segment tree

int st[262144]; // segment tree che contiene il numero di intervalli per ogni nodo
short int st_sx[262144]; // segment tree di appoggio che indica se il range corrispondente inizia con un 1
short int st_dx[262144]; // segment tree di appoggio che indica se il range corrispondente termina con un 1
// servono per poter capire se posso unire gli intervalli tra nodi vicini

// aggiorna foglia corrispondente e propaga modifica verso l'alto (indice parte da 0)
void update(int pos){
    pos = pos + SIZE_T;
    int value = 1 - st[pos]; // nuovo valore

    // aggiorno foglia
    st[pos] = value;
    st_sx[pos] = value;
    st_dx[pos] = value;

    // salgo sul padre
    pos = pos / 2;
    while(pos > 0){
        // variabili temporanee contenti il valore attuale del nodo prima dell'aggiornamento
        int temp = st[pos], temp_sx = st_sx[pos], temp_dx = st_dx[pos];
        if(st_dx[ 2 * pos] == 0 || st_sx[ 2*pos + 1] == 0){
            // figlio sinistro e figlio destro non terminano o iniziano con 1 rispettivamente
            // non posso unire un intervallo che inizia nel sx e termina nel dx
            st[pos] = st[ 2 * pos] + st[ 2 * pos + 1];
            // sommo semplicemente il numero di intervalli
        }else{
            if(st_dx[2 * pos] == 1 && st_sx[ 2 * pos + 1] == 1){
                // figlio sinistro e figlio destro terminano e iniziano con 1 rispettivamente
                // posso unire un intervallo che inizia nel sx e termina nel dx
                st[pos] = st[ 2 * pos] + st[ 2 * pos + 1] - 1;
                // sommo gli intervalli ma sottraggo uno altrimenti l'intervallo 
                // che è coperto un po' dal sx e un po' dal dx lo conto 2 volte
            }
        }
        st_sx[pos] = st_sx[ 2 * pos]; // se ha 1 a sx dipende dal figlio sx
        st_dx[pos] = st_dx[2 * pos + 1]; // se ha 1 a dx dipende dal figlio dx
        if(st[pos] == temp && st_sx[pos] == temp_sx && st_dx[pos] == temp_dx){
            return; // non c'è stata modifica
        }
        // salgo sul padre
        pos = pos / 2;
    }
    return;
}

// connette il nodo sinistro col destro creando un nodo ibrido che diventa il padre di entrambi
// num intervalli nodo sinistro, se nodo sinistro ha 1 a sx, se nodo sinistro ha 1 a dx
// num intervalli nodo destro, se nodo destro ha 1 a sx, se nodo destro ha 1 a dx
vector<int> link_nodes(int left_v, short int left_l, short int left_r, int right_v, short int right_l, short int right_r){
    vector<int> node; // nodo padre
    int node_v, node_l, node_r; // valori del nodo padre

    // logica seguente analoga alla funzione update(int pos)
    if(left_r == 0 || right_l == 0){
        // figlio sinistro e figlio destro non terminano o iniziano con 1 rispettivamente
        // non posso unire un intervallo che inizia nel sx e termina nel dx
        node_v = left_v + right_v;
        // sommo semplicemente il numero di intervalli
    }else{
        if(left_r == 1 && right_l == 1){
            // figlio sinistro e figlio destro terminano e iniziano con 1 rispettivamente
            // posso unire un intervallo che inizia nel sx e termina nel dx
            node_v = left_v + right_v - 1;
            // sommo gli intervalli ma sottraggo uno altrimenti l'intervallo 
            // che è coperto un po' dal sx e un po' dal dx lo conto 2 volte
        }
    }
    node_l = left_l; // se ha 1 a sx dipende dal figlio sx
    node_r = right_r; // se ha 1 a dx dipende dal figlio dx

    // valorizzo le informazioni raccolte nel padre
    node.push_back(node_v);
    node.push_back(node_l);
    node.push_back(node_r);
    return node;
}

// conta intervalli dalla left alla right (indice parte da 0)
int num_int(int left, int right){
    // sistemo indici
    left = left + SIZE_T;
    right = right + SIZE_T + 1; // right viene decrementato all'inizio

    if(left == right) return st[left]; //nodo foglia

    // informazioni che accumulo mentre risalgo dalla due direzioni
    int cum_l[4] = {0, 0, 0}; // value sx dx
    int cum_r[4] = {0, 0, 0}; // value sx dx
    vector<int> temp; // variabile di appoggio
    bool left_f = true, right_f = true; // prima visita per ogni lato
    int ii = 0; // indice
    while(left < right){
        if(left % 2 == 1){
            if(left_f){ // prima volta inizializzo cum_l
                cum_l[0] = st[left];
                cum_l[1] = st_sx[left];
                cum_l[2] = st_dx[left];
                left_f = false;
            }
            else{
                // connetto nodo attuale con tutte le info che ho (alla sua sx)
                temp = link_nodes(cum_l[0], cum_l[1], cum_l[2],
                        st[left], st_sx[left], st_dx[left]);
                // aggiorno la variabile cumulativa
                ii = 0;
                for (auto i = temp.cbegin(); i != temp.cend(); ++i, ii++) 
                    cum_l[ii] = *i;
            }
            // proseguo verso dx
            left++;
        }
        if(right % 2 == 1){
            right--;
            if(right_f){ // prima volta popolo cum_r
                cum_r[0] = st[right];
                cum_r[1] = st_sx[right];
                cum_r[2] = st_dx[right];
                right_f = false;
            }
            else{
                // connetto nodo attuale con le informazioni collezionate (alla sua dx)
                temp = link_nodes(st[right], st_sx[right], st_dx[right],
                            cum_r[0], cum_r[1], cum_r[2]);
                // aggiorno la variabile cumulativa
                ii = 0;
                for (auto i = temp.cbegin(); i != temp.cend(); ++i, ii++) 
                    cum_r[ii] = *i; 
            }
        }
        // risalgo l'albero
        left = left / 2;
        right = right / 2;
    }
    // creo nodo finale
    temp = link_nodes(cum_l[0], cum_l[1], cum_l[2],
                cum_r[0], cum_r[1], cum_r[2]);
    // ritorno valore
    return *temp.cbegin();
}

int main() {
    //ifstream input_file("input_1.txt");
    cin >> N >> M;

    int depth = 0; // profondita del segment tree
    while(pow(2.0, depth) < N) depth++;

    SIZE_T = pow(2.0, depth); // indice primo nodo foglia
    SIZE_ST = 2 * SIZE_T; // dimensione segment tree
    
    // non e' necessario inizializzare il segment tree in quanto
    // esso contiene tutti 0 (variabile globale) e corrisponde alla situazione iniziale
    // con tutte le luci spente

    bool init_scenario = true; // non sono stati fatti ancora cambiamenti dall'inizio
    int i = 0, pos = 0, j, k, ii;
    short int op; // tipo operazione
    string line;
    getline(cin, line); // prima riga già elaborata
    for(i = 0; i < M; i++){
        // svolgo le operazioni
        getline(cin, line);
        op = line[0] - '0'; 
        if(op == 2){
            // query
            if(init_scenario){
                cout << "0" << endl;
            }else{
                // sono state fatte delle modifiche
                line = line.substr(2, line.size() - 2);
                for(ii = 0; ii < line.size() && line[ii]!=' ';){
                    ii++;
                }
                // ii contiene indice dello spazio
                j = stoi(line.substr(0, ii));
                k = stoi(line.substr(ii + 1, line.size() - ii - 1));
                cout << num_int(j, k) << endl;
            }
        }else{
            // aggiornamento
            if(init_scenario){ // prima modifica, non più situazione iniziale
                init_scenario = false;
            }
            pos = stoi(line.substr(2, line.size() - 2));
            update(pos);
            // TODO: update lazy
            /*
            // stampa ST
            int ii;
            for(ii = 0; ii < SIZE_ST ; ii++){
                cout << ii << " " << st_sx[ii] << " " << st[ii] << " " << st_dx[ii] << endl;
            }
            cout << endl;
            */
        }
    }
    //input_file.close();
    return 0;
}