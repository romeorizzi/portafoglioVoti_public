/**
* user:  VR445569
* fname: PADOVANI
* lname: ALAN MICHAEL
* task:  bin_heap_fill
* score: 4.0
* date:  2020-06-18 11:05:40.592508
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

int verify_heap_prop(int root, int bound){
    if(root >= bound) return 1; // caso base
    // verifica se l'albero con radice posta in root
    // soddisfi la heap prop
    int figlio_sx = 2 * root + 1;
    int figlio_sx_ok;
    int figlio_dx = 2 * (root + 1);
    int temp;
    if(figlio_sx < bound && values[figlio_sx] < values[root] && e[figlio_dx] == 1){
        return 0; // viola la proprieta
    }else{
        if(figlio_sx < bound && values[figlio_sx] < values[root] && e[figlio_dx] == 0 && e[root] == 0){
            // figlio sx viola la proprieta ma posso scambiarlo col padre
            temp = values[figlio_sx];
            values[figlio_sx] = values[root];
            values[root] = figlio_sx;
            // li scambio e verifico dal padre
            return verify_heap_prop(root, bound);
        }
    }
    if(figlio_dx < bound && values[figlio_dx] < values[root] && e[figlio_dx] == 1){
        return 0; // viola la proprieta
    }else{
        if(figlio_dx < bound && values[figlio_dx] < values[root] && e[figlio_dx] == 0 && e[root] == 0){
            temp = values[figlio_dx];
            values[figlio_dx] = values[root];
            values[root] = temp;
            // li scambio e verifico dal padre
            return verify_heap_prop(root, bound);
        }
    }
    figlio_sx_ok = verify_heap_prop(figlio_sx, bound);
    if(figlio_sx_ok == 1){
        // sottoalbero figlio sx verifica proprieta
        return verify_heap_prop(figlio_dx, bound);
    }else{
        return 0; // sottoalbero figlio sx 
    }
}

int main() {
    //ifstream input_file("input1.txt");
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
    for( i = 1; i < n ; i++){
        getline(cin, line, ' ');
        e[i] = stoi(line);
    }
    if(t == 1){
        cout << verify_heap_prop(0, n);
    }
    //input_file.close();
    return 0;
}