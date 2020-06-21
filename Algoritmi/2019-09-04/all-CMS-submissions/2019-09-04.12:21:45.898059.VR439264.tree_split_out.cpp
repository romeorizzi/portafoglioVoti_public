/**
* user:  VR439264
* fname: CREMA
* lname: EMANUELE
* task:  Prob1_tree_split_out
* score: 30.0
* date:  2019-09-04 12:21:45.898059
*/
/**
 *  Template per soluzione in c++ per il problema tree_split_out
 *
 *  Romeo Rizzi, per l'appello di algoritmi 2019-09-04
 *
 */

#include <cassert>
#include <iostream>

using namespace std;

const int MAX_N = 1000000;

int n = 0, input_type, out_n=0;  
int in_tree[MAX_N], out_tree[MAX_N];

int inverse(int n) {
  if(n == 0) {
    return 1; 
  } 
  return 0; 
}

void resolve(int from, int to, int odd) {  
  int i = from; int touched; 
  while(i<to && i<n) { 
    touched = 0; 
    // cout << "entra\n";
    if(in_tree[i]%2 == odd && in_tree[i]>=0) { 
      int j=i+1; 
      while(in_tree[i] != in_tree[j] && j<n)  {
	j++; 
      } 
    
      in_tree[i] = -1; 
      in_tree[j] = -1; 

      for(int c=i+1;c<j;c++) {
	in_tree[c]--; 
      }
      resolve(i+1,j,inverse(odd)); 
      //cout << "Finito\n"; 
      i = j + 1; 
      touched = 1; 
      
    } 
    if(!touched) { 
      i++; 
    } 
  }
}  

void construct_out() {
  for(int i = 0;i<n;i++) {
    if(in_tree[i]>=0) {
      out_tree[out_n++] = in_tree[i]; 
    }
  }
}

int main() {
    // leggere l'input_type:
    cin >> input_type;

    // leggere la sequenza che codifica l'albero in input (in formato input_type):  
    int val;
    while (cin >> val)
      in_tree[n++] = val;

    // in questo template di soluzione mi limito a ricopiare l'input in output (non sarà mai la soluzione corretta tranne che per alberi di un solo nodo):
    resolve(0,n,1); 
    construct_out(); 

    cout << input_type << ' ';

    for(int i=0; i<out_n; i++)
      cout << out_tree[i] << ' ';
    cout << endl;
    
    return 0;
}

