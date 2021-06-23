/**
* user:  VR450855_id649cns
* fname: CARLO
* lname: VERONESI
* task:  bridges_and_cutnodes
* score: 0.0
* date:  2021-06-22 11:42:29.330970
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string.h>
using namespace std;
#include <list>

void list_print(list<int> l)
{
    list<int>::iterator it;
    for(it = l.begin(); it != l.end(); it++){
        cout <<  *it << " ";
    }
    cout << "\n";
}



bool checkRaggiungibile(list<int> *adiacenti, int n, int eliminato){
    // Segno i vertici visitati
    bool *visitati = new bool[n];
    for (int i = 0; i < n; i++)
        visitati[i] = false;
    // Visito il primo
    visitati[inizio] = true;

    int posiz = inizio;
    cout << "inizio " << inizio << endl;
    for(int elem : adiacenti[posiz]){
        //int elem = adiacenti[i];
        cout << elem << endl;
        if(elem == fine)
            return true;
        
        if(!visitati[elem]){
            visitati[elem] = true;
            inizio++;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n;
    int m;
    int t;

    string testa;
    string input_str;
    std::vector<pair<int, int>> archi;

    cin >> t >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> edge.first >> edge.second;
        adiacenti[edge.first].push_back(edge.second);
        adiacenti[edge.second].push_back(edge.first);
        archi.push_back(edge);
    }

    switch(t){
        case 1: 
            cout << "uno" << endl;
            // Rimuovo un nodo alla volta e controllo
            for(int i = 0; i < n; i++){
                cout << i << endl;
                // Controllo se riesco a raggiungere tutti i nodi
                bool out = checkRaggiungibile(adiacenti, n, i); // i verrà ignorato
                cout << out;
            }
        break;
        case 2: cout << "due" << endl;
        break;
        case 3: cout << "tre" << endl;
        break;
    }

    return 0;
}
