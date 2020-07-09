/**
* user:  VR445479
* fname: BOSCHI
* lname: FEDERICO
* task:  poldo_sums
* score: 2.0
* date:  2020-06-18 12:17:48.522579
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

// Ritorna i possibili successori di un numero nella sequenza
set<int> successors(int n, vector<int>* panino, vector<int>* gym){
    set<int> successors;
    int i;
    for(i=n+1; i<panino->size(); i++){
        int j, somma = 0;
        for(j=n; j<i; j++){
            somma += (*gym)[j];
        }
        if((*panino)[i] >= (*panino)[n]+somma){
            successors.insert(i);
        }
    }
    return successors;
}

// Calcola la sequenza massima dato un numero iniziale
void sequences(int n, int* level, vector<int>* panino, vector<int>* gym, set<int>* max_sequence, set<int>* sequence, vector<set<int>>* succs, vector<int>* explored){
    (*explored)[n] = *level;
    for(int s : (*succs)[n]){
        sequence->insert(s);
        (*level)++;
        if((*level) > (*explored)[s]){
            sequences(s, level, panino, gym, max_sequence, sequence, succs, explored);
        }
    }
    if((*succs)[n].empty()){
        if(sequence->size() > max_sequence->size()){
            max_sequence->clear();
            for(int elem : *sequence){
                max_sequence->insert(elem);
            }
        }
    }
    sequence->erase(n);
    (*level)--;
}

int main() {
    ifstream myFile("input.txt");
    int N, i;
    myFile >> N;
    vector<int> panino(N);
    vector<int> gym(N);
    for(i=0; i<N; i++){
        myFile >> panino[i];
        myFile >> gym[i];
    }
    myFile.close();

    vector<int> explored(N);
    vector<set<int>> succs(N);
    for(i=0; i<N; i++){
        explored[i] = 0;
        succs[i] = successors(i,&panino,&gym);
    }


    set<int> final_sequence;
    int n;
    for(n=0; n<N; n++){
        set<int> max_sequence, sequence;
        sequence.insert(n);
        int level = 0;
        sequences(n, &level, &panino, &gym, &max_sequence, &sequence, &succs, &explored);
        if(max_sequence.size() > final_sequence.size()){
            final_sequence = max_sequence;
        }
    }

    ofstream myOutFile("output.txt");
    myOutFile << final_sequence.size() << endl;
    for (int elem : final_sequence) {
        myOutFile << elem << ' ';
    }
    myOutFile.close();

    return 0;
}
