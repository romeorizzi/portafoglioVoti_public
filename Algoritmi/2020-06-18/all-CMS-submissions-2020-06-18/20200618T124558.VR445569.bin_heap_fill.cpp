/**
* user:  VR445569
* fname: PADOVANI
* lname: ALAN MICHAEL
* task:  bin_heap_fill
* score: 25.0
* date:  2020-06-18 12:45:58.329876
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <vector>
using namespace std;

int values[1000000];
int e[1000000];
int f[1000000];

int verify_heap_prop_f(int root, int bound){
    if(root >= bound) return 1; // caso base
    // verifica se l'albero con radice posta in root
    // soddisfi la heap prop
    int figlio_sx = 2 * root + 1;
    int figlio_sx_ok;
    int figlio_dx = 2 * (root + 1);
    int temp;
    if(figlio_sx < bound && values[figlio_sx] < values[root] && ( f[figlio_sx] == 1 || f[root] == 1)){
        return 0; // viola la proprieta
    }else{
        if(figlio_sx < bound && values[figlio_sx] < values[root] && f[figlio_sx] == 0 && f[root] == 0){
            // figlio sx viola la proprieta ma posso scambiarlo col padre
            temp = values[figlio_sx];
            values[figlio_sx] = values[root];
            values[root] = temp;
            // li scambio e verifico dal padre
            return verify_heap_prop_f(root, bound);
        }
        
    }
    if(figlio_dx < bound && values[figlio_dx] < values[root] && (f[figlio_dx] == 1 || f[root] == 1)){
        return 0; // viola la proprieta
    }else{
        if(figlio_dx < bound && values[figlio_dx] < values[root] && f[figlio_dx] == 0 && f[root] == 0){
            temp = values[figlio_dx];
            values[figlio_dx] = values[root];
            values[root] = temp;
            // li scambio e verifico dal padre
            return verify_heap_prop_f(root, bound);
        }
    }
    figlio_sx_ok = verify_heap_prop_f(figlio_sx, bound);
    if(figlio_sx_ok == 1){
        // sottoalbero figlio sx verifica proprieta
        return verify_heap_prop_f(figlio_dx, bound);
    }else{
        return 0; // sottoalbero figlio sx 
    }
}

int verify_heap_prop_e(int root, int bound){
    //if(root >= bound || (root != 0 && e[root] == 0) ) return 1; // caso base
    if(root >= bound) return 1; // caso base
    // verifica se l'albero con radice posta in root
    // soddisfi la heap prop
    int figlio_sx = 2 * root + 1;
    int figlio_sx_ok;
    int figlio_dx = 2 * (root + 1);
    int temp;
    if(figlio_sx < bound && values[figlio_sx] < values[root] && e[figlio_sx] == 1){
        return 0; // viola la proprieta
    } 
    if(figlio_dx < bound && values[figlio_dx] < values[root] && e[figlio_dx] == 1){
        return 0; // viola la proprieta
    } 
    figlio_sx_ok = verify_heap_prop_e(figlio_sx, bound);
    if(figlio_sx_ok == 1){
        // sottoalbero figlio sx verifica proprieta
        return verify_heap_prop_e(figlio_dx, bound);
    }else{
        return 0; // sottoalbero figlio sx 
    }
}

int main() {
    //ifstream input_file("input3.txt");
    int n, t, i;
    cin >> n >> t;
    // lettura vettore
    string  line;
    int index;
    for(index = 0; index < n - 1 ; index++){
        getline(cin, line, ' ');
        values[index] = stoi(line);
    }
    
    getline(cin, line, ' ');
    for( i = 0; i < line.size() && line[i]!='\n'; i++){
    }
    values[index] = stoi(line.substr(0, i));
    e[0] = stoi(line.substr(++i, 1));
    for( index = 1; index < n - 1 ; index++){
        getline(cin, line, ' ');
        e[index] = stoi(line);
    }
    getline(cin, line, ' ');
    e[index] = (int) (line[0]) - 48;
    f[0] = (int) (line[2]) - 48;
    for( index = 1; index < n ; index++){
        getline(cin, line, ' ');
        f[index] = stoi(line);
    }
    if(t == 1){
        cout << verify_heap_prop_e(0, n);
    }else{
        // task 2
        cout << verify_heap_prop_f(0, n);
    }
    //input_file.close();
    return 0;
}