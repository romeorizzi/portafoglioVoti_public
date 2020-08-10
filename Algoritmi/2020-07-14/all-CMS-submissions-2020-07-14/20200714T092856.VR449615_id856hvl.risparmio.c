/**
* user:  VR449615_id856hvl
* fname: GIOVANNI
* lname: SCHIAVONE
* task:  risparmio
* score: 23.0
* date:  2020-07-14 09:28:56.450942
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void conta(int luci[], int n1, int n2){

	bool serie = false;
	int conta = 0;

	for (int j = n1; j<=n2; j++ ) {
		if ( luci[j]%2 == 1) {
			if(!serie){
				serie=true;
				conta++;
			}
		}
		else {
			serie=false;
		}
	}

	printf("%i\n",conta);

};

void main (int argc, char *argv[]) {


	int n=0 , m=0 ;
	int op=0, n1=0, n2=0;

	scanf("%i", &n);
	scanf("%i", &m);

	int luci[n];
	for(int k=0;k<n;k++){
		luci[k]=0;
	}

	//leggo input ed eseguo
	for (int i=0; i<m; i++) {

		scanf("%i", &op);
		scanf("%i", &n1);
		if(op == 2){
			scanf("%i", &n2);
		}

		if (op==1) {
			luci[n1]++;

		}
		else {
			conta(luci, n1, n2);
		}

	}

	exit(0);

}
