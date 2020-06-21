/**
* user:  VR439218
* fname: MANTOVAN
* lname: FILIPPO
* task:  online_budget
* score: 67.0
* date:  2019-07-30 11:26:04.047737
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 50;
const int MAX_BUDGET = 200;
const int overflow = 1000000007;
//const int MAX_VAL = 10;

int N_PERIODI, B0, monete[MAX_N+1];
int dinamica [MAX_BUDGET] = {0};

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int possibili_scelte(int periodo, int b_rimanente){
    //printf("%d %d \n", periodo, b_rimanente);
    b_rimanente = b_rimanente + monete[periodo];
    


    if (periodo < N_PERIODI){
      int sum=0;
      for (int i=0 ; i<=b_rimanente ; i++){
          sum += possibili_scelte (periodo+1, b_rimanente-i);
      }
      return sum;

    }

    else{
      return 1;
    }


}


int main() {
    ifstream inFile;
    inFile.open("input0.txt");
    int scelte;

    //inFile >> N_PERIODI >> B0;
    cin >> N_PERIODI >> B0;
    monete[0] = 0;
    for(int i = 1; i < N_PERIODI; i++)
        cin >> monete[i];
        //inFile >> monete[i];


    scelte = possibili_scelte(0,B0);
 
    cout << scelte%overflow << endl;

    return 0;
}

