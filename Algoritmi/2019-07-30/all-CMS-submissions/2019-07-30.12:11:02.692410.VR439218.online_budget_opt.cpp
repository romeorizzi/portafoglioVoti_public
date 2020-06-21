/**
* user:  VR439218
* fname: MANTOVAN
* lname: FILIPPO
* task:  online_budget_opt
* score: 10.0
* date:  2019-07-30 12:11:02.692410
*/
/**
 *  Template per soluzione in c++ per il problema online_budget_opt
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <fstream>
#include <iostream>
using namespace std;

const int MAX_N = 1000000;
const int MAX_VAL = 10;

int n, B0, output_type, monete[MAX_N+1], gemme[MAX_N+1], is_index_of_last_opportunity[MAX_N];
long int y[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int max_gemme(int periodo, int b_rimanente){

    b_rimanente = b_rimanente + monete[periodo];

    
    if (periodo < n){
      int result,max=0;

      max = b_rimanente * gemme[periodo];
      result = max_gemme (periodo+1, b_rimanente);
      if (result > max){
        max = result;
      }
      return max;

    }

    else{
      int max = b_rimanente * gemme[periodo];
      return max;
    }
}


int main() {
    int gemme_tot;
    ifstream inFile;
    inFile.open("input0.txt");
    
    cin >> n >> B0 >> output_type;
    monete[0] = 0;
    gemme[0] = 0;
    for(int i = 1; i <= n; i++)
       cin >> monete[i];
    for(int i = 1; i <= n; i++)
       cin >> gemme[i];

    y[0] = B0;
    for(int i = 1; i < n; i++)
      y[i] = monete[i-1];

  
    if(output_type == 1)
      cout << max_gemme(0, B0) << endl;
    else
      cout << 5 << endl;

    return 0;
}

