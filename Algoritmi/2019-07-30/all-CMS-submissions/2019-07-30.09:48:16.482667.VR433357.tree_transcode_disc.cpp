/**
* user:  VR433357
* fname: MOSCHIN
* lname: FEDERICO
* task:  tree_transcode_disc
* score: 40.0
* date:  2019-07-30 09:48:16.482667
*/
/**
 *  Template per soluzione in c++ per il problema tree_transcode_disc
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
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

int uno_due(int nodo,int nfigli){
  if(nfigli == 1){
    cout<< nodo<< " ";
    return nodo;
  }

  int letto;
  int sum =1;

  while (sum < nfigli){
    cin>>letto;
    sum+=uno_due(letto,letto);
  }

  cout <<nodo<< " ";
  return nodo;
}

int main() {
    cin >> input_type;
    int read =0;
    int size =0;
    if(input_type == 1){

      cin>>size;
      //cout<<size<<endl;
      cout << "2 ";
      uno_due(size,size);
    }
    else{
      cout << "1 ";
    }
    // leggere la sequenza che codifica l'albero in formato input_type

    // ottenere la codifica nell'altro formato
    
    //cout << 3-input_type << endl;

    // scrivere la nuova codifica dell'albero
    
    return 0;
}

