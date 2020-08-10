/**
* user:  VR447268_id713ast
* fname: PIETRO
* lname: TAROCCO
* task:  risparmio
* score: 0.0
* date:  2020-07-14 12:06:35.552982
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
static FILE *file;
static vector<int> lights;
static vector<int> operazione2;
static long long int N;
static long long int M;
static int op;
static int cell;
static int i1, i2;


int main(){

	#ifdef EVAL
	  file = fopen("input.txt", "r");
	#else
	  file = stdin;
	#endif
  	assert(fscanf(file, "%lld %lld", &N, &M)==2);
  
	bool lights_On=false;
	int counter;
	int c=0;
	lights.resize(N);
	operazione2.resize(M);

	for (int i=0; i<N; i++){
		lights[i]=0;
	}
    
	for (int j=0; j<M; j++){
		assert(fscanf(file, "%d", &op)==1);

		if(op==1){
			assert(fscanf(file, "%d", &cell)==1);
			if (lights[cell]==0) lights[cell]=1;
			else if(lights[cell]==1) lights[cell]=0;
		}
		if(op==2){

			counter=0;
			lights_On=false;
			assert(fscanf(file, "%d %d", &i1, &i2)==2);

			for(int i=i1; i<=i2; i++){

				if(!lights_On && lights[i]==1){
					counter+=1;
					lights_On=true;
				}

				else if(lights_On && lights[i]==0){
					lights_On=false;
				}
			}
		}
		operazione2[c] = counter;
		c+=1;
	}

	fclose(file);
	#ifdef EVAL
		file = fopen("output.txt", "w");
	#else
		file = stdout;
	#endif
	operazione2.resize(c);
	for(int i=0; i<c; i++){
		fprintf(file, "%d\n", operazione2[i]);
	}
	fclose(file);
}
