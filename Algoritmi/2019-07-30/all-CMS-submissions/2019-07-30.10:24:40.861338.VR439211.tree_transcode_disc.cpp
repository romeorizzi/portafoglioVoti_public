/**
* user:  VR439211
* fname: ARIETTI
* lname: LUCA
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 10:24:40.861338
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

int n, x[MAX_N], y[MAX_N], input_type;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int main() {
    cin >> input_type;
    // leggere la sequenza che codifica l'albero in formato input_type
    if(input_type == 1){
      cin >> n;
      x[0] = n;
      for(int i = 1; i < n; i++)
        cin >> x[i];
      
      //clono array
      int x_clone[MAX_N];
      for(int i=0;i<n;i++){
        x_clone[i]=x[i];
      }

    
      // ottenere la codifica nel formato 2
      int j=0;
      int junk=0;
      int padre=0;
      if(n==1){
        y[0]=1;
      }
      else{
        for(int i=0; i<n; i++){
          if(x[i]==1){
            y[j]=1;
            j++;
            if(x_clone[padre] == x[padre])
              junk++;
            x[padre]--;
            x[i]=0;
            junk++;

            if(x[padre]-1 == 0){
              //cerco tutti i numeri !=1 sul clone per metterli in y
              for(int ii=i; ii>=0;ii--){
                if(x_clone[ii]>1 && x[ii]!=0){
                  if(x_clone[ii] != x[ii]){
                    y[j]=x_clone[ii];
                    j++;
                    x[ii]=0;
                  }
                  else{
                    i=-1;
                    break;
                  }
                }
                if(x_clone[ii]==junk){
                    //junk=0;
                    i=-1; //-1 perche poi il for fa +1

                    break;
                }
              }

              

            }
            

          }
          else if(x[i]!=0){
            padre=i;
          }
          else{
            //se zero sottraggo il junk al padre
            if(x_clone[padre] == x[padre]){
              x[padre] = x[padre] - junk;
              junk++;
            }
           
          }

        }
      }
    }
    // ottenere la codifica nell'altro formato
    
    cout << 3-input_type << " ";

    // scrivere la nuova codifica dell'albero
    print_array(y,n);
    return 0;
}

