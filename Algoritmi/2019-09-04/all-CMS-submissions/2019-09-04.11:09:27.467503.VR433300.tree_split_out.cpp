/**
* user:  VR433300
* fname: INCUDINI
* lname: MASSIMILIANO
* task:  Prob1_tree_split_out
* score: 0.0
* date:  2019-09-04 11:09:27.467503
*/
/**
 *  Template per soluzione in c++ per il problema tree_split_out
 *
 *  Romeo Rizzi, per l'appello di algoritmi 2019-09-04
 *
 */

#include <cassert>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int MAX_N = 1000000;

int n = 0, input_type;
int in_tree[MAX_N], out_tree[MAX_N];


int main() {

	//assert( freopen("input.txt", "r", stdin) );
    //assert( freopen("output.txt", "w", stdout) );

	// leggere l'input_type:
	cin >> input_type;

	// leggere la sequenza che codifica l'albero in input (in formato input_type):
	int val;
	while (cin >> val)
	in_tree[n++] = val;

	// processo il nodo
	if(input_type == 3) {
	} else {
		assert(false);
	}

	return 0;
}

