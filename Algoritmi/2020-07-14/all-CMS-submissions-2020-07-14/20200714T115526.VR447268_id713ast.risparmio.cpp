/**
* user:  VR447268_id713ast
* fname: PIETRO
* lname: TAROCCO
* task:  risparmio
* score: 0.0
* date:  2020-07-14 11:55:26.287412
*/
#include <iostream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;
static FILE *file;
static int N;
static int M;
static int operazione;
static int cell;
static int l, r;

int main(){

	#ifdef EVAL
	  file = fopen("input.txt", "r");
	#else
	  file = stdin;
	#endif

  	assert(fscanf(file, "%d %d", &N, &M)==2);
	vector<int> lights(N,0);
	vector<int> operazione_2(M, 0);
	int c=0;
	bool lights_On=false;
	int counter;
    
	for (int j=0; j<M; j++){
		assert(fscanf(file, "%d", &operazione)==1);
		if(operazione==1){
			assert(fscanf(file, "%d", &cell)==1);
			if (lights[cell]==0) lights[cell]=1;
			else if(lights[cell]==1) lights[cell]=0;
		}
		if(operazione==2){
			counter=0;
			lights_On=false;
			assert(fscanf(file, "%d %d", &l, &r)==2);
			for(int i=l; i<=r; i++){
				if(lights[i]==1 && !lights_On){
					counter+=1;
					lights_On=true;
				}
				else if(lights[i]==0 && lights_On){
					lights_On=false;
				}
			}
		}
		operazione_2[c] = counter;
		c+=1;
	}
	fclose(file);

	#ifdef EVAL
	  file = fopen("output.txt", "w");
	#else
	  file = stdout;
	#endif

	operazione_2.resize(c);
	for(int i=0; i<c; i++){
		fprintf(file, "%d\n", operazione_2[i]);
	}
	fclose(file);
}
