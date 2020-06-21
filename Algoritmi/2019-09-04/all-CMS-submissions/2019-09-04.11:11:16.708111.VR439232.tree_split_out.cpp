/**
* user:  VR439232
* fname: PENZO
* lname: MICHELE
* task:  Prob1_tree_split_out
* score: 30.0
* date:  2019-09-04 11:11:16.708111
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

int n = 0, input_type;
int in_tree[MAX_N], out_tree[MAX_N], livelli[MAX_N];
int  pos_r=0;

void evapora3(){
  if (n==1 || pos_r == n){
    return;
    }
  

  int livello = in_tree[pos_r];

  if(livello %2 == 0)
  {
    if(livello>0)
    {
      cout << livello - (livello/2) << " ";
    }
    else
    {
      cout << livello << " ";
    }
  }


  pos_r++;
  evapora3();
  
}

void crea_livelli(int depth)
{
  if(pos_r == n){return;}
    //return;

  livelli[pos_r] = depth;

  if(in_tree[pos_r] == 0){return;}
    //return;

  depth++;
  int n_figli=in_tree[pos_r];
  for(int i =0; i<n_figli;i++){
    pos_r++;
    crea_livelli(depth);
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
    //cout << input_type << ' ';
  int sum=0;

  switch(input_type){
    case 1:
     /* cout << input_type << ' ';
      crea_livelli(0);

      for(int i=0; i<n; i++){
        sum=0;
        int depth=livelli[i];

        if(depth%2==0){
        
          if(in_tree[i] == 0){
            cout << 0 << " ";
            continue;
          }

          for(int j=i; j<n;j++){
            if(livelli[j] == depth+2)
            {
              sum++;
            }
            cout << sum << " ";
          }
          
        }
      }*/
      break;  
    case 2:
      cout << input_type << " ";
      break;
    case 3:
      cout << input_type << " ";
      evapora3();
      cout << endl;
      break;
    default:
      break;  
  }

    return 0;
}

