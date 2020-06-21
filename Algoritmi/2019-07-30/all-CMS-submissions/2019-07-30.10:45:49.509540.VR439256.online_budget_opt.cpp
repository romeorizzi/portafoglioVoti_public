/**
* user:  VR439256
* fname: MORI
* lname: SAMUELE
* task:  online_budget_opt
* score: 12.0
* date:  2019-07-30 10:45:49.509540
*/
/**
 *  Template per soluzione in c++ per il problema online_budget_opt
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
using namespace std;

const int MAX_N = 1000000;
const int MAX_VAL = 10;

int n, B0, output_type, x[MAX_N], q[MAX_N], is_index_of_last_opportunity[MAX_N];
long int y[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int maxv = 0;
bool new_max = false;

int rec(int budget, int it, int s){
  if(it < n) {
    int j;
    budget += x[it-1];
    it++;
    //cout << "*" << q[it] << "\n";
    for(j=0; j<=budget; j++) {
      rec(budget-j, it, s+j*q[it-1]);
      //cout << "-\n";
    }
  } else {
    //cout << "-" << s << "\n";
    if(s > maxv)
      maxv = s;
    return 0;
  }
}




int main() {
    cin >> n >> B0 >> output_type;
    for(int i = 0; i < n; i++)
       cin >> x[i];
    for(int i = 0; i < n; i++)
       cin >> q[i];
    
    //print_array(x, n);
    //print_array(q, n);


    y[0] = B0;
    for(int i = 1; i < n; i++)
      y[i] = x[i-1];


    for(int i = 0; i <= B0; i++){
      //cout << "#" << B0-i << "\n";
      rec(B0-i, 1, i*q[0]);
    }


    if(output_type == 1)
      cout << maxv << endl;
    else
      print_array(y, n);

    return 0;
}



/*
int rec(int budget, int it){
  if(it < n) {
    int j;
    budget += x[it-1];
    it++;
    
    for(j=0; j<=budget; j++) {
      rec(budget-j, it);
    }
  } else {
    ++c;
    return 0;
  }
}

int main() {
    cin >> n >> B0;
    for(i = 0; i < n; i++)
       cin >> x[i];

    for(i = 0; i <= B0; i++){
      rec(B0-i, 1);
    }

    cout << c << endl;
    return 0;
}
*/