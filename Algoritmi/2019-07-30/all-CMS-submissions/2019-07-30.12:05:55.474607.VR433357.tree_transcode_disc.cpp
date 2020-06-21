/**
* user:  VR433357
* fname: MOSCHIN
* lname: FEDERICO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 12:05:55.474607
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

int uno_due(int nodo){
  int letto;
  int sum =1;

  while (sum < nodo){
    cin>>letto;
    sum+=uno_due(letto);
  }

  cout <<nodo<< " ";
  return nodo;
}


void due_uno(int nodo,int sum){
  int next;
 /* if(nodo == sum){
     cout <<nodo<< " ";
  }*/
  if(cin >> next){

    if(nodo < next){
      due_uno(next,nodo);
    }
    else{
      due_uno(next,1);
    }
    cout <<nodo<< " ";
    return;
  }
   cout <<nodo<< " ";
}



void due_uno_rev(int nodo,int sum){
  int next;
  
  if(cin >> next){
    due_uno_rev(next,sum)
    cout <<nodo<< " ";
    return;
  }
  else{//File finito, sono alla radice e la stampo
    cout <<nodo<< " ";
    return;
  }
}

/*
void due_uno(int lastcount,int pos,int previous_print){
  if(x[pos == -1]){
    return;
  }

  if(lastcount+1 >= x[pos]){
    x[pos] = -1;
    due_uno(x[pos],pos+1);
    cout <<nodo<< " ";
    return;
  }
  else{
    due_uno(lastcount+1,pos+1);
  }
}*/

int main() {
    cin >> input_type;
    int read =0;
    int size =0;
    int elem;
    int i= 0;
    int sum = 0;

    cin>>size;
    if(input_type == 1){
      //cout<<size<<endl;
      cout << "2 ";
      uno_due(size);
    }
    else{
      //cout << "1 ";
      /*while(cin >> elem){ //Riempio array
        i++;
        cout <<elem<< " ";
      }*/
      cout << "1 ";

      due_uno_rev(size,1);
    }
    // leggere la sequenza che codifica l'albero in formato input_type

    // ottenere la codifica nell'altro formato
    
    //cout << 3-input_type << endl;

    // scrivere la nuova codifica dell'albero
    
    return 0;
}

