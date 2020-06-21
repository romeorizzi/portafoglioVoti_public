/**
* user:  VR439346
* fname: MASOTTO
* lname: GIOVANNI
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 10:36:47.512469
*/
/**
 *  Template per soluzione in c++ per il problema tree_transcode_disc
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> childVec[1000000];
int numNode=0;
int nChild[1000001];
int input_type;

int codifica_1(int node){
    int nFigli;
    int tree =0;
    fin >> nFigli;//prendo e metto dentro all'array
    nChild[node] = nFigli;
    nFigli =nFigli-1;

    while(tree < nFigli){
    numNode++;
    childVec[node].push_back(numNode);
    tree = tree+ codifica_1(numNode);
    }
    return nChild[node];
}

int myprint(int node){
    for(int i =0; i<childVec[node].size();i++){
    int a = childVec[node][i];
    myprint(a);
    }
    fout << nChild[node]<< " ";

}

int main() {

    int input_type;
    fin >> input_type;
    if (input_type ==1){
    codifica_1(0);
    fout << "2";
    myprint(0);
    }

    /*//int input_type;
    //cin >> input_type;

    fin >> input_type;//cosi leggo il primo carattere mi dice il tipo di codifca
    cout << input_type;
    if(input_type==1){
    codifica_1(0);
    cout << "2";
    myprint(0);
    }
    cout << endl;
    /*fout << 3-input_type << " ";
    if (input_type == 2){
    printf("ciao");
    }
    else printf("no");*/
    // leggere la sequenza che codifica l'albero in formato input_type

    // ottenere la codifica nell'altro formato

   // cout << 3-input_type << endl;

    // scrivere la nuova codifica dell'albero

    return 0;
}























