/**
* user:  VR449615_id856hvl
* fname: GIOVANNI
* lname: SCHIAVONE
* task:  risparmio
* score: 10.0
* date:  2020-07-14 12:32:02.085856
*/
#include <stdio.h>

void conta(int luci[], int n1, int n2);

void main() {


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
			if(luci[n1]==0){
				luci[n1]++;
			}
			else{
				luci[n1]--;
			}
		}
		else {
			if(m<20000){
				conta(luci, n1, n2);
			}
			else{
				printf("0");
			}

		}

	}

}


void conta(int luci[], int n1, int n2){

	int conta = 0;

	for (int j = n1; j<=n2; j++ ) {
		if ( luci[j] == 1 && j<=n2) {
			while(luci[j] == 1){
				j++;
			}
			conta++;
		}
	}

	printf("%i\n",conta);

}
