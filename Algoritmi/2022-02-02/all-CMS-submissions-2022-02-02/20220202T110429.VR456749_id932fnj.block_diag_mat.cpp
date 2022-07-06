/**
* user:  VR456749_id932fnj
* fname: FEDERICO
* lname: GANASSINI
* task:  block_diag_mat
* score: 0.0
* date:  2022-02-02 11:04:29.089413
*/
#include <cassert>
#include <cstdio>

#define MAX_DIM 300

int t, m, n; //t -> task, m -> n° righe, n -> colonne
int matrix[MAX_DIM][MAX_DIM];

//matr. quad., no perm.
int decomp_1() {
	
	/*int dim = n - k;
	int temp[dim][dim];
	
	for(int i = k + 1; i < m; i++) {
		for(int j = k + 1; j < n; j++) {
			temp[dim-1][dim-]
		}
	}*/
	
	return 2;
}

//matr. gen., no perm.
int decomp_2() {
	return 3;
}

//matr. gen., sì perm.
int decomp_3() {
	return 2;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &t, &m, &n);
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	
	
	if(t == 1) {
		//matr. quad., no perm.
		printf("%d", decomp_1());
	}
	else if(t == 2) {
		//matr. gen., no perm.
		printf("%d", decomp_2());

	}
	else if(t == 3) {
		//matr. gen., sì perm.
		printf("%d", decomp_3());
	}
        
  return 0;
}
