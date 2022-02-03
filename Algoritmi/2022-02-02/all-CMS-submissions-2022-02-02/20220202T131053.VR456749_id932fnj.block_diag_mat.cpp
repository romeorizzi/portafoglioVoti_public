/**
* user:  VR456749_id932fnj
* fname: FEDERICO
* lname: GANASSINI
* task:  block_diag_mat
* score: 0.0
* date:  2022-02-02 13:10:53.945576
*/
#include <cassert>
#include <cstdio>

#define MAX_DIM 300

int t, m, n; //t -> task, m -> n° righe, n -> colonne
int mat[MAX_DIM][MAX_DIM];	

//matr. quad., no perm.
int decomp_1() {
	int n_blocchi = 0;

	for(int k = 0; k < m; n_blocchi++) {
		int tmp = -1;		
		int j = k, i = k;
		
		//Controllo la riga
		for(j = k; j < n; j++) {
			if(mat[k][j] != 0)
				tmp = j;
		}
		
		if(tmp != -1)
			i = tmp;
		else
			i = k;
		
		//Controllo la colonna
		for(; i < m; i++) {
			if(mat[i][k] != 0)
				tmp = i;
		}
		
		if(tmp != -1)
			k = tmp;
		else
			k++;
	}
	
	return n_blocchi;
}

//matr. gen., no perm.
int decomp_2() {
	int n_blocchi = 0;
	return n_blocchi;
}

//matr. gen., sì perm.
int decomp_3() {
	int n_blocchi = 0;
	return n_blocchi;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d%d%d", &t, &m, &n);
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	
	if(t == 1) {
		//matr. quad., no perm.
		printf("%d", decomp_1());
	}
	else if(t == 2) {
		//matr. gen., no perm.
		printf("%d", decomp_1());

	}
	else if(t == 3) {
		//matr. gen., sì perm.
		printf("%d", decomp_1());
	}
        
  return 0;
}
