/**
* user:  VR418781
* fname: BRENTEGANI
* lname: MATTEO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 11:23:33.640812
*/
/**
 *  Template per soluzione in c++ per il problema tree_transcode_disc
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1000000;
const int MAX_VAL = 10;

int n, B0, x[MAX_N], input_type;

int num_children[MAX_N];
int num_descendants[MAX_N];
int depth[MAX_N*2   ];

int posw;
template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}
    

int read_child(int root, int d) {

    depth[root] = d;
    num_descendants[root] = 1;
    for (int i = 1; i < num_children[root]; i++) {
        num_descendants[i] += read_child(root + num_children[root], d+1);
    }
}

int read_desc(int root, int d, int posW) {
    depth[posW++] = d;
    num_children[root] = 0;
    int n_open = 1;
    while (n_open < num_descendants[root]){
        num_children[root]++;
        read_desc(root+n_open,d+1, posW);
        n_open += num_descendants[root+n_open];
    }
    depth[posW] = d;
}
 
int pos;
int read_depth(int root, int d) {
     assert(depth[pos] == d);
     num_children[root] = 0;
     num_descendants[root] = 1;
     while(depth[++pos] > d){
         num_descendants[root] +=read_depth(root+ num_descendants[root], d+1);
     }
 }

int main() {
    //cin >> input_type;
    for(int i = 0; i < n; i++)
       cin >> num_children[i];
    if (num_children[0] == 1) {
        cout << &num_descendants[0];
        
        for(int i = 0; i < n; i++) {
            cout << &num_children[i];
            //posW = 0;
            read_desc(0,0, 0);

            for (int j = 0; j < 2*n; j++) {
                cout << depth[j];
            }
        }
    } else {
        int n = 0;
        scanf("%d", &depth[n++]);
        scanf("%d", &depth[n++]);
        while(depth[n-1] > 0)
            scanf("%d", &depth[n++]);

        for (int i= 0; i < n/2; i++) {
            cout << num_descendants[i];
        }
        read_depth(0,0);
    }
    // leggere la sequenza che codifica l'albero in formato input_type


    // ottenere la codifica nell'altro formato
    
    return 0;
    // scrivere la nuova codifica dell'albero
    
}

