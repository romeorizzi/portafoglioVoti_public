/**
* user:  VR436720
* fname: BERTI
* lname: MARCO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 11:16:19.325928
*/
/**
 *  Template per soluzione in c++ per il problema online_budget
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */

#include <cassert>
#include <iostream>
using namespace std;

const int MAX_N = 500;
const int MAX_VAL = 10;

int n, B0, x[MAX_N];

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int main() {
    cin >> n >> B0;
    for(int i = 0; i < n; i++)
      cin >> x[i];
    //print_array(x, n);
    int y[n][MAX_N*MAX_VAL];
    int b = B0;
    int count = 0;
    int S=0;
    bool done = false;
    int max_j=0;

    for(int k=0; k <= max_j; k++){
        b=B0;
        y[0][0]=0;
        for(int i = 0; i < n; i++) {
            print_array(y[k],n);

            cout << "ciclo " << i << " -> ";
            b = b - y[i][k];
            cout << "B value = " << b << endl;
            if(i>0)
                b = b + x[i-1];
            else
                y[i][k]=y[i][k]+1;
            if(y[i][k]<b)
                for(int j=0;j<=b;j++){
                    if(i<n){
                        y[i+1][j]=j;
                    }
                    if(j>max_j)
                        max_j = j;
                }
        }
        if(b >= 0){
            count++;
            cout << "count ++" << endl; 

        }
    }


    S = count % 1000000007;

    cout << S << endl;
    return 0;
}

/*ciclo 1

y[0][0]=0 b=2
y[0][1]=1 y[0][2]=2 b

 */
