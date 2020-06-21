/**
* user:  VR409637
* fname: GERMINIANI
* lname: SAMUELE
* task:  mst
* score: 35.0
* date:  2019-02-26 10:54:28.956875
*/
#include <bits/stdc++.h>
int mst(int N, int M, int* A, int* B, int* P, int* C, int* D){
	int adj[N][N];

	//init adj to zero
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			adj[i][j]=0;
		}
	}


	//transform the input to adj lists
	for (int i0 = 0; i0 < M; i0++) {
		adj[A[i0]][B[i0]]=P[i0];
		adj[B[i0]][A[i0]]=P[i0];
	}
	/*
	   for(int i=0;i<N;i++){
	   for(int j=0;j<N;j++){
	   std::cout<<adj[i][j]<<" ";
	   }
	   std::cout<<"\n";
	   }
	   */

	//it follows an simple implementation of Prims's algorithm

	bool mstSet[N];
	//it will store the constructed msp
	int constructed[N];
	//it will store key values to pick edges
	int keys[N];

	//init keys
	for(int i=0; i<N;i++){
		keys[i]= INT_MAX;
		mstSet[i]=false;
	}

	constructed[0]=-1;
	keys[0]=0;


	for(int k=0;k<N-1;k++){
		int minKey;
		int min = INT_MAX;
		for(int i=0;i<N;i++){
			if(mstSet[i]==false && keys[i] < min){
				min= keys[i];
				minKey= i;
			}

		}
		mstSet[minKey]= true;
		for(int i=0;i<N;i++){
			if(adj[minKey][i] && mstSet[i]==false && adj[minKey][i]< keys[i]){
				constructed[i]= minKey;
				keys[i]=adj[minKey][i];
			}
		}
	}


	int minimo=0;
	for(int i=1;i<N;i++){
		minimo+=adj[i][constructed[i]];
	}

	
	for(int i=1;i<N;i++){
		C[i-1]=constructed[i];
		D[i-1]=i;
	}

	return minimo;







	return 1;
}

