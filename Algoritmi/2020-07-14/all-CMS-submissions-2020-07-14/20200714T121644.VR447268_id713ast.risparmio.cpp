/**
* user:  VR447268_id713ast
* fname: PIETRO
* lname: TAROCCO
* task:  risparmio
* score: 0.0
* date:  2020-07-14 12:16:44.847001
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

using namespace std;
static FILE *file;
static int cell;
static int l, r;
static vector<int> lights;
static vector<int> operazione2;
static long long int N;
static long long int M;
static int operazione;

int main(){

	#ifdef EVAL
	  file = fopen("input.txt", "r");
	#else
	  file = stdin;
	#endif

	assert(fscanf(file, "%lld %lld", &N, &M)==2);
	lights.resize(N);
	operazione2.resize(M);
	int c=0;
	bool lightsOn=false;
	int counter;

	for (int i=0; i<N; i++){
		lights[i]=0;
	}
    
	for (int j=0; j<M; j++){
		assert(fscanf(file, "%d", &operazione)==1);

		if(operazione == 1){
			assert(fscanf(file, "%d", &cell)==1);
			if (lights[cell]==0) lights[cell]=1;
			else if(lights[cell]==1) lights[cell]=0;
		}
		if(operazione==2){
			counter=0;
			lightsOn=false;
			assert(fscanf(file, "%d %d", &l, &r)==2);
			for(int i=l; i<=r; i++){
				if(!lightsOn && lights[i]==1){
					counter+=1;
					lightsOn=true;
				}
				else if(lightsOn && lights[i]==0){
					lightsOn=false;
				}
			}
			operazione2[c] = counter;
			c+=1;
		}
	}

	fclose(file);

	#ifdef EVAL
		file = foperazioneen("output.txt", "w");
	#else
		file = stdout;
	#endif
		operazione2.resize(c);
		for(int i=0; i<c; i++){
			fprintf(file, "%d\n", operazione2[i]);
		}
	fclose(file);
}
