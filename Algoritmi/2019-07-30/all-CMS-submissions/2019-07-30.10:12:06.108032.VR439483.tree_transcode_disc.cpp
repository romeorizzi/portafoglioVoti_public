/**
* user:  VR439483
* fname: MIRKO
* lname: MORATI
* task:  tree_transcode_disc
* score: 40.0
* date:  2019-07-30 10:12:06.108032
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 1000000;
const int MAX_VAL = 10;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

void cod1to2(int *nodes, int *sum, int l, int p) {
    static int cur = 1;
    if (sum[p] == nodes[p]) return;
//    cout << "p: " << p << " cur: " << cur << "\t";
//    print_array(sum, l);
    while (sum[p] < nodes[p]) {
        if (cur < l && nodes[cur] > 1) {
            sum[p] += nodes[cur];
            cod1to2(nodes, sum, l, cur++);
        } else if (cur < l) {
            while (nodes[cur] == 1 && sum[p] < nodes[p]) {
//                cout << "p: " << p << " cur: " << cur << "\t";
//                print_array(sum, l);
                if (sum[p] < nodes[p]) {
                    cout << nodes[cur] << " ";                    
                    // cout << "leaf of " << nodes[p] << " -> " << nodes[cur] << "\n";
                    sum[p] += nodes[cur];
                }
                else {
                    
                    break;            
                }
                cur++;
            }
        }
    }
    cout << nodes[p] << " ";
    // cout << p << endl;
}

int main() {
    int t = 0;
    int nodes[MAX_N];
    int l = 0;
    cin >> t;
    for (; cin >> nodes[l]; l++);
    
    int sum[l];
    for (int i = 0; i < l; sum[i++] = 1);

    if (t == 1) {
        cout << "2 ";
        cod1to2(nodes, sum, l, 0);
    }
    else

    return 0;
}

