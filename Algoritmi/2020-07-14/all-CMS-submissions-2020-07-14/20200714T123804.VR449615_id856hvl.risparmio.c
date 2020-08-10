/**
* user:  VR449615_id856hvl
* fname: GIOVANNI
* lname: SCHIAVONE
* task:  risparmio
* score: 23.0
* date:  2020-07-14 12:38:04.458105
*/
#include <stdio.h>

void conta(int a[], int n1, int n2);

void main() {


	int n=0 , m=0 ;
	int op=0, n1=0, n2=0;

	scanf("%i", &n);
	scanf("%i", &m);

	int a[n];
	for(int k=0;k<n;k++){
		a[k]=0;
	}

	//leggo input ed eseguo
	for (int i=0; i<m; i++) {
		scanf("%i", &op);
		scanf("%i", &n1);
		if(op == 2){
			scanf("%i", &n2);
		}

		if (op==1) {
			if(a[n1]==0){
				a[n1]++;
			}
			else{
				a[n1]--;
			}
		}
		else {
			conta(a, n1, n2);
		}

	}

}


void conta(int a[], int n1, int n2){

	int c = 0;

	for (int j = n1; j<=n2; j++ ) {
		if ( a[j] == 1 && (j==n1 || a[j-1]==0)) {

			c++;
		}
	}

	printf("%i\n",c);

}
