/**
* user:  VR424402
* fname: DARIENZO
* lname: PAOLO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 11:19:57.264308
*/
#include <cassert>
#include <cstdio>

const int MAX_N = 1000000;
int num_children[MAX_N];
int num_descendants[MAX_N];
int depth[MAX_N*2];

int read_children_format(int root, int d){
	depth[root] = d;
	num_descendants[root] = 1;
	for(int i = 1; i <= num_children[root]; i++){
		num_descendants[root] += read_children_format(root + num_descendants[root], d + );
	}
	return num_descendants[root];
}

int posW;
void read_descendants_format(int root, int d){

	depth[posW++] = d;
	num_children[root] = 0;
	int n_opened = 1;
	while(n_opened < num_descendants[root]){
		num_children[root]++;
		read_descendants_format(root+n_opened, d+1);
		n_opened += num_descendants[root+n_opened];
	}
	depth[posW++] = d;
}

int posR;
int read_depth_format(int root, int d){
	assert(depth[posR] == d);
	num_children[root] = 0;
	num_descendants[root] = 1;
	while(depth[++posR] > d){
		num_descendants[root] += read_depth_format(root + num_descendants[root], d+1);
	}
	return num_descendants[root];
}

int main(){
	#ifdef EVAL
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
	#endif
	int input_format, output_format;
	scanf("%d", &num_descendants[0]);
	printf("%d ", output_format = 3 - input_format);
	if(input_format == 1) {
		scanf("%d", &num_descendants[0]);
		int n = num_descendants[0];
		for(int i = 1; i < n; i++){
			scanf("%d", &num_descendants[i]);
		}
		posW = 0;
		read_descendants_format(0, 0);
		
		for(int i = 0; i < 2*n; i++)
			printf("%d ", depth[i]);
		printf("\n");
	}
	else{
		int n = 0;
		scanf("%d", &depth[n++]);
		scanf("%d", &depth[n++]);
		while(depth[n-1] > 0)
			scanf("%d", &depth[n++]);
		
		assert(n%2==0);
		posR = 0;
		assert(read_depth_format(0,0) == n/2);
		
		for(int i = 0; i < n/2; i++)
			printf("%d ", num_descendants[i]);
		printf("\n");
		
		return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
