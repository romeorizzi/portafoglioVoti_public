/**
* user:  VR449615_id856hvl
* fname: GIOVANNI
* lname: SCHIAVONE
* task:  risparmio
* score: 23.0
* date:  2020-07-14 08:24:24.180497
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void main (int argc, char *argv[]) {


	int n=0 , m=0 ;

	scanf("%i", &n);
	scanf("%i", &m);

	int luci[n];
	for(int k=0;k<n;k++){
		luci[k]=0;
	}

	bool serie = false;
	int conta = 0;

	//leggo input ed eseguo
	for (int i=0; i<m; i++) {

		int op=0, n1=0, n2=0;
		scanf("%i", &op);
		scanf("%i", &n1);
		if(op == 2){
			scanf("%i", &n2);
		}

		if (op==1) {
			luci[n1]++;

		}
		else {

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

			serie = false;
			conta = 0;

		}

	}

	exit(0);

}
