/**
* user:  VR439620
* fname: MOLINARI
* lname: DAVIDE
* task:  Prob1_tree_split_out
* score: 30.0
* date:  2019-09-04 11:33:38.337456
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
int in_tree[MAX_N], out_tree[MAX_N];

int main() {
    // leggere l'input_type:
    cin >> input_type;

    // leggere la sequenza che codifica l'albero in input (in formato input_type):
    int val;
    while (cin >> val)
      in_tree[n++] = val;

    // in questo template di soluzione mi limito a ricopiare l'input in output (non sarà mai la soluzione corretta tranne che per alberi di un solo nodo):
    if(in_tree[0] == 1) cout << input_type << ' ';
    if(input_type == 3)
    {
        int j = 0;
        out_tree[j] = 3;
        j++;
        for(int i = 0; i < n; i++)
        {
            if(in_tree[i] % 2 == 0)
            {
                out_tree[j] = in_tree[i];
                j++;
            }
        }
        for(int i = 1; i < j ; i++)
        {
            out_tree[i] = out_tree[i]/2;
        }
        n = j;
    }
    for(int i=0; i<n; i++)
      cout << out_tree[i] << ' ';
    cout << endl;
    
    return 0;
}

