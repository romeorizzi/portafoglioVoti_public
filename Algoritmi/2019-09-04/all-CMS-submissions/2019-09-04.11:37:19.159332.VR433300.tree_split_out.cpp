/**
* user:  VR433300
* fname: INCUDINI
* lname: MASSIMILIANO
* task:  Prob1_tree_split_out
* score: 66.0
* date:  2019-09-04 11:37:19.159332
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

struct tree {
	int nfigli;
	int ndiscendenti;
	int livello;
	std::vector<struct tree> figli;
};

std::tuple<struct tree, int> input_1(int i, int livello)
{
	struct tree node;
	node.nfigli = in_tree[i];
	node.livello = livello;

	// cout << "(i=" << i << ") figli = " << node.nfigli << "\n";

	for(int j = 0; j < node.nfigli; j++) {

		std::tuple<struct tree, int> temp = input_1(i+1, livello+1);
		struct tree childtree = std::get<0>(temp);
		node.figli.push_back(childtree);

		i = std::get<1>(temp);
	}

	return std::tuple<tree, int>(node, i);
}

std::tuple<struct tree, int> input_2(int i, int livello)
{
	struct tree node;
	node.ndiscendenti = in_tree[i];
	node.livello = livello;

	// cout << "(i=" << i << ") discendenti = " << node.ndiscendenti << "\n";

	int sommaDiscendenti = 1;
	while(sommaDiscendenti < node.ndiscendenti) {

		std::tuple<struct tree, int> temp = input_2(i+1, livello+1);
		struct tree childtree = std::get<0>(temp);
		node.figli.push_back(childtree);

		i = std::get<1>(temp);
		sommaDiscendenti += childtree.ndiscendenti;
	}

	return std::tuple<tree, int>(node, i);
}

std::tuple<struct tree, int> input_3(int i)
{
	struct tree node;
	node.livello = in_tree[i];
	i++;

	while(in_tree[i] != node.livello) {
		std::tuple<struct tree, int> temp = input_3(i);

		struct tree childtree = std::get<0>(temp);
		node.figli.push_back(childtree);

		i = std::get<1>(temp) + 1;
	}

	return std::tuple<tree, int>(node, i);
}

void evapora(struct tree* evennode)
{
	std::vector<struct tree> nipoti;
	for(auto it = evennode->figli.begin(); it != evennode->figli.end(); ++it) {
		struct tree oddnode = *it;
		for(auto it = oddnode.figli.begin(); it != oddnode.figli.end(); ++it) {
			struct tree nephew = (*it);
			evapora(&nephew);
			nipoti.push_back(nephew);
		}
	}

	evennode->figli.clear();
	evennode->ndiscendenti = 1;
	evennode->nfigli = nipoti.size();

	for(auto it = nipoti.begin(); it != nipoti.end(); ++it) {
		evennode->figli.push_back(*it);
		evennode->ndiscendenti += (*it).ndiscendenti;
	}
}

void print_1(struct tree* node)
{
	cout << (node->nfigli) << " ";
	for(auto it = node->figli.begin(); it != node->figli.end(); ++it) {
		print_1(&(*it));
	}
}

void print_2(struct tree* node)
{
	cout << (node->ndiscendenti) << " ";
	for(auto it = node->figli.begin(); it != node->figli.end(); ++it) {
		print_2(&(*it));
	}
}


void print_3(struct tree* node, int divider)
{
	cout << (node->livello / divider) << " ";
	for(auto it = node->figli.begin(); it != node->figli.end(); ++it) {
		print_3(&(*it), divider);
	}
	cout << (node->livello / divider) << " ";
}

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
	if(input_type == 1) {
		struct tree node = std::get<0>(input_1(0, 0));
		evapora(&node);
		cout << "1 ";
		print_1(&node);

	} else if(input_type == 2) {
		struct tree node = std::get<0>(input_2(0, 0));
		evapora(&node);
		cout << "2 ";
		print_2(&node);

	} else if(input_type == 3) {
		struct tree node = std::get<0>(input_3(0));
		evapora(&node);
		cout << "3 ";
		print_3(&node, 2);

	} else {
		assert(false);
	}

	return 0;
}

