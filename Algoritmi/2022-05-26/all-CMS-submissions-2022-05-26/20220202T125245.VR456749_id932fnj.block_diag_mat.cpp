/**
* user:  VR456749_id932fnj
* fname: FEDERICO
* lname: GANASSINI
* task:  block_diag_mat
* score: 0.0
* date:  2022-02-02 12:52:45.253150
*/
#include <cassert>
#include <cstdio>

#define MAX_DIM 300

int t, m, n; //t -> task, m -> n° righe, n -> colonne
int mat[MAX_DIM][MAX_DIM];	

//matr. quad., no perm.
int decomp_1() {
	int n_blocchi = 0;
	
	for(int k = 0; k < m; k++) {
		
		int j = k, i = k;
		
		//Controllo la riga
		while(mat[k][j] == 0 && j < n) {
			j++;
		}
		
		if(j != n) {
			i = j;
		}
		
		//Controllo la colonna
		while(mat[i][k] == 0 && i < m) {
			i++;
		}
		
		if(i != m)
			k = i;
		else
			k = j;
		
		n_blocchi++;
	}
	
	return n_blocchi;
}

//matr. gen., no perm.
int decomp_2() {
	return 0;
}

//matr. gen., sì perm.
int decomp_3() {
	return 0;
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
		printf("%d", decomp_2());

	}
	else if(t == 3) {
		//matr. gen., sì perm.
		printf("%d", decomp_3());
	}
        
  return 0;
}
