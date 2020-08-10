/**
* user:  VR445569_id588nzp
* fname: ALAN MICHAEL
* lname: PADOVANI
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 11:21:06.663190
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

short int m, n, p;
// stringhe a e b
char a[1000];
char b[1000];
// costi
int cost[1001];

bool possible = false;

// se la posizione non è stata definita costo infinito
int get_costo(int pos){
    if(pos <= p){
        if(!possible && pos > 0) possible = true;
        return cost[pos];
    }
    return numeric_limits<int>::max();
}

// ritorna il costo minimo per espandere la stringa b dal carattere in posizione index_b
// rispetto la stringa a dal carattere in posizione index_a
// num_ast asterischi che ho già aggiunto in precedenza e non ancora coperti
int cost_from_char(int index_b, int index_a, int num_ast){
    if(index_b >= n && index_a >= m){
        return get_costo(num_ast); // fine stringa caso base non aggiungo nessun carattere pago asterischi rimanenti
    }
    if(index_b >= n && index_a < m){
        return get_costo(num_ast + m - index_b); // finisco la stringa a ma non b (aggiugno * alla fine)
    }
    int temp3 = numeric_limits<int>::max();
    while(a[index_a] != b[index_b] && index_a < m){
        index_a++; // sono diversi i caratteri avanzo con a
        num_ast++; // numero di * da inserire
        temp3 = min(temp3, cost_from_char(index_b + 1, index_a, num_ast));
    }
    int temp, temp2;
    if(index_a < m){
        // esistono ancora caratteri da coprire in a
        // i caratteri a[index_a] e b[index_b] sono uguali
        // posso scegliere se continuare con asterischi o coprire con il carattere
        // copro con asterisco
        temp2 = cost_from_char(index_b + 1, index_a + 1, num_ast + 1);
        // copro col carattere
        // chiamata ricorsiva sui prossimi caratteri di a e b
        temp = get_costo(num_ast) + cost_from_char(index_b + 1, index_a + 1, 0);
        temp = min(temp, temp3);
        // posso continuare a vedere se trovo altre occorrenze di questo carattere b in a
        if(temp2 == 0){
            cout << index_b + 1 << endl;
            cout << index_a + 1 << endl;
            cout << num_ast + 1 << endl;
            cout << endl << endl;
        }
        return min(temp, temp2);
    }else{
        // ho raggiunto la fine di a
        return min(temp3, get_costo(num_ast));
    }
}

int main() {
    //ifstream input_file("input_0.txt");
    cin >> m >> n >> p;
    short int i = 0;
    cin >> a; // popolo stringa a
    cin >> b; // popolo stringa b
    // popolo vettore dei costi
    for(i = 0; i <= p; i++){
        cin >> cost[i];
    }
    //input_file.close();
    int result = cost_from_char(0, 0, 0);
    if(possible){
        cout << result << endl;
    }else{
        cout << "-1" << endl;
    }
    return 0;
}