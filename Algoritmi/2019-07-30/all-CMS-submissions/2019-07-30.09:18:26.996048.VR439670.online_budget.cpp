/**
* user:  VR439670
* fname: LUCCHESE
* lname: MARCO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 09:18:26.996048
*/
/**
 *  Template per soluzione in c++ per il problema tree_transcode_disc
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int MAX_N = 1000000;
const int MAX_VAL = 10;

int n, B0, x[MAX_N], input_type;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

ifstream fin;
ofstream fout;

vector<int> vec1,vec2;

int writeType_2 (int deep){
    int child;fin>>child;
    int count=1;
    fout<<deep<<" ";
    while(count<child){
        count+=writeType_2(deep+1);
    }
    fout<<deep<<" ";
    return child;
}

int calcVec1(int index1, int index2){
    vec1.push_back(1);
    int deep; deep=vec2[index2];
    while(vec2[index2+ 2*vec1[index1] - 1]>deep){
        vec1[index1]+= calcVec1(index1+vec1[index1],index2+ 2*vec1[index1]-1);
    }
    return vec1[index1];
}

void writeType_1(){
    vec2.push_back(0);
    int temp;
    fin>> temp;
    do{
        fin>>temp;
        vec2.push_back(temp);
    }while(temp>0);
    calcVec1(0,0);
    for(int i =0;i<vec1.size();i++){
        fout<<vec1[i]<<" ";
    }
}

int main() {
    cin >> input_type;
    // leggere la sequenza che codifica l'albero in formato input_type

    // ottenere la codifica nell'altro formato
    fin.open("input1.txt");
    fout.open("output.txt");
    assert(fin);
    assert(fout);
    int type; fin >>type;
    fout<<3-type<<" ";
    if(type==1){
        writeType_2(0);
    }else{
        writeType_1();
    }
    fout<<endl;
    return 0;
    
    cout << 3-input_type << endl;

    // scrivere la nuova codifica dell'albero
    
    return 0;
}

