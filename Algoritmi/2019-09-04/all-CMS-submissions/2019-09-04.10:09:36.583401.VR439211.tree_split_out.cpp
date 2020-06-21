/**
* user:  VR439211
* fname: ARIETTI
* lname: LUCA
* task:  Prob1_tree_split_out
* score: 0.0
* date:  2019-09-04 10:09:36.583401
*/
/**
 *  Template per soluzione in c++ per il problema tree_split_out
 *
 *  Romeo Rizzi, per l'appello di algoritmi 2019-09-04
 *ALBERIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
 */

#include <cassert>
#include <iostream>

using namespace std;

const int MAX_N = 1000001;

int n = 0, input_type;
int in_tree[MAX_N], out_tree[MAX_N];
int costruzione[MAX_N][2];
int posizione_is_a1;
int altro_array[MAX_N];

bool is_a1(int x, int pos){
  for (int i=pos;i>0;i--){
    if(costruzione[i][0]==x){
        //se c'è gia un elemento
        //controllo se ha il bit a 1
        if(costruzione[i][1] == 1){
          posizione_is_a1=i;
          return true;
        }
    }
  }
  return false;
}


int main() {
    // leggere l'input_type:
    cin >> input_type;

    // leggere la sequenza che codifica l'albero in input (in formato input_type):
    int val;
    while (cin >> val)
      in_tree[n++] = val;
    // in questo template di soluzione mi limito a ricopiare l'input in output (non sarà mai la soluzione corretta tranne che per alberi di un solo nodo):
    /*cout << input_type << ' ';

    for(int ii=0; ii<n; ii++)
      cout << in_tree[ii] << ' ';
    cout << endl;
    */
    if(input_type==3){



      //costruisco il mio array
      int i=0;
      int j=0;
      for (;i<n;i++){
        if(is_a1(in_tree[i], j)){
          //e' vero, cioè ho un elemento indietro uguale con bit a 1
          // lo setto a 0 e basta
          costruzione[posizione_is_a1][1]=0;
        }
        else{
          //altrimenti, se non ho elementi uguali con bit a 1, lo aggiungo all'array costruzione, mettendogli il bit a 1
          costruzione[j][0]=in_tree[i];
          costruzione[j][1]=1;
          j++;
        }
      }
      j--;
      /*for(int gg=0;gg<j;gg++){
        cout << costruzione[gg][0];
      }
      cout << "\nquesto era costr\n\n";*/

      //ora ho il mio array costruzione
      // vado a vedere e prendo solo i pari
      int q=0;
      for (i=0;i<j;i++){
        if(costruzione[i][0] % 2 == 0){     //se pari
          altro_array[q]=costruzione[i][0] / 2;
          q++;
        }
      }

      /*for(int gg=0; gg<q; gg++){
        cout << altro_array[gg];
      }*/
//////////////////////////////////
      altro_array[q]=-1;
      q++;
      for(int kk=0;kk<=j;kk++){
        costruzione[kk][0]=-1;
        costruzione[kk][1]=0;
      }
      i=0;
      j=0;
      costruzione[0][0]=0;
      costruzione[0][1]=1;
     // cout << "q vale "<<q<<endl;
      for (;i<q;){
        if(altro_array[i]==-1){
          break;
        }

        if(costruzione[j][0]==altro_array[i+1]){
          //cout<<"si\n";
          costruzione[j][1]=0;
          j++;
          costruzione[j][0]=altro_array[i+1];
          costruzione[j][1]=0;
          j++;
          costruzione[j][0]=altro_array[i+1];
          costruzione[j][1]=1;
          i++;
        }
        else{
          //se non sono uguali
          //lascio cosi e aggiungo solo il numero con bit 1
          //cout<<"no\n";
          j++;
          if(altro_array[i+1]==-1){
            break;
          }
          costruzione[j][0]=altro_array[i+1];
          costruzione[j][1]=1;
          i++;
        }

      }
     // cout << "\n\nstammpa";
      /*for(int ii=0; ii<j; ii++)
        cout << costruzione[ii][0] << ' ';
      cout << endl;*/
      //ora devo copiare quelli col bit a 1
      for (int ij=j-1;ij>=0;ij--){
        //controllo se ha il bit a 1
        if(costruzione[ij][1] == 1){
          costruzione[j][0]=costruzione[ij][0];
          j++;
        }
    
      }

      ///stampo
      cout << input_type << ' ';

      for(int ii=0; ii<j; ii++)
        cout << costruzione[ii][0] << ' ';
      cout << endl;
    

    }


    return 0;
}

