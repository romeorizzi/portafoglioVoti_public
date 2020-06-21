/**
* user:  VR439237
* fname: DEPALO
* lname: CHRISTIAN
* task:  tree_transcode_disc
* score: 50.0
* date:  2019-07-30 11:42:58.006924
*/
#include <iostream>
using namespace std;

const int MAX_N = 1000000;

int num_descendants[MAX_N];
int depths[MAX_N];
int n = 0;

int posR;
int to_codifica_1(int root, int depth) {
    
    if(num_descendants[root] == 1) {
      depths[root] = depth;
      return num_descendants[root];
    }

    depths[root] = depth;
    int tot = 1;
    depth++;

    while(tot < num_descendants[root]) {
      posR--;
      tot += to_codifica_1(posR, depth);
    }
    
    cout << num_descendants[root] << " ";

    for(int i = root-1; i >= 0; i--) {
      if(depths[i] == depth) {
        cout << num_descendants[i] << " ";
      }
    }

}

int posW;
int to_codifica_2(int root) {
    int tot = 1;
    
    while(tot < num_descendants[root]) {
        posW++;
        tot += to_codifica_2(posW);
    }

    cout << num_descendants[root] << " ";
    return num_descendants[root];
}


int main() {
    int type;
    cin >> type;
    
    int val;
    while(cin >> val) {
      num_descendants[n++] = val;
    }

    cout << 3-type << " ";
    if(type == 1) {

      posW = 0;
      
      to_codifica_2(posW);
    }
    
    else {
      posR = n-1;
      cout << "posR: " << posR << endl;
      //to_codifica_1(posR, 0);
    }

    return 0;
}
