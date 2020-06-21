/**
* user:  VR424402
* fname: D'ARIENZO
* lname: PAOLO
* task:  Prob1_tree_split_out
* score: 0.0
* date:  2019-09-04 11:07:12.632092
*/
#include <iostream>

using namespace std;

const int MAX_VAL = 1000000;

int kids[MAX_VAL];
int num_descendants[MAX_VAL];
int depth[MAX_VAL*2];

int posR, posW;

int node_index = 0;

void print_array1(int n){
	for(int i = 0; i < n; i++)
		cout << " " << kids[i];
}

int remove_cod1(int root, int d) {

	root = node_index;
	if (d % 2 == 0){
		if(kids[root] != 0){
			int tmp = kids[root];
			for(int i = 0; i < tmp; i++){
				kids[root] += remove_cod1(node_index, d + 1);
			}
			
			kids[root] -= tmp;
		}
	}
	else {
		for(int i = 0; i < kids[root]; i++) {
			remove_cod1(node_index++, d + 1);
		}
		int tmp = kids[root];
		kids[root] = -1;
		return tmp;
	}
	return 0;
}

int remove_cod2(int root, int d) {

	int somma = 0;
	if ( d % 2 == 0) {
		if (num_descendants[root] == 1)
			return 1;
		
		while (num_descendants[root] > 1) {
			num_descendants[root] -= num_descendants[++node_index];
			somma += remove_cod2(node_index, d + 1);
		}
		
		num_descendants[root] = somma + 1;
	}
	else {
		if (num_descendants[root] == 1) {
			num_descendants[root] = -1;
		}
		
		while (num_descendants[root] > 1){
			num_descendants[root] -= num_descendants[++node_index];
			somma += remove_cod2(node_index, d + 1);
		}
		num_descendants[root] = -1;
		return somma;
	}
	return -1;
}

void remove_cod3(int root, int d){ 


}

int main(){

	int cod, n = 1;
	cin >> cod;
	if(cod == 1){
		cin >> kids[0];
		n += kids[0];
		for(int i = 1; i < n; i++) {
			cin >> kids[i];
			if (kids[i] > 0)
				n += kids[i];
		}
		
		cout << 1 << " ";
		if(remove_cod1(0, 0) == 0) {
			for(int i = 0; i < n; i++){
				if(kids[i] != -1)
					cout << kids[i] << " ";
				}
			}
		}
		else {
		if (cod == 2) {
			cin >> num_descendants[0];
			n = num_descendants[0];
			for(int i = 1; i < n; i++) {
				cin >> num_descendants[i];
			}
			
			if (remove_cod2(0, 0) == 1) {
				if (num_descendants[0] > 1)
					num_descendants[0]++;
				cout << 2 << " ";
				for(int i = 0; i < n; i++) {
					if(num_descendants[i] != -1)
						cout << num_descendants[i] << " ";
				}
			}
		}
		else {
		}
	}
	
	return 0;

}		
		
		
		
		
		
		
		
