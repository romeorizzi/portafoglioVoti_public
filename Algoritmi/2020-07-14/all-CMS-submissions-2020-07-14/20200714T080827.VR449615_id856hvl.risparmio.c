/**
* user:  VR449615_id856hvl
* fname: GIOVANNI
* lname: SCHIAVONE
* task:  risparmio
* score: 0.0
* date:  2020-07-14 08:08:27.968138
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main (int argc, char *argv[]) {


	int n=0 , m=0 ;

	scanf("%i", &n);
	scanf("%i", &m);

	int luci[n];
	memset(luci, 0, n);

	int count = 0;
	int interv = 0;

	//leggo input ed eseguo
	for (int i=0; i<m; i++) {

		int op=0, n1=0, n2=0;
		scanf("%i", &op);
		scanf("%i", &n1);
		if(op == 2){
			scanf("%i", &n2);
		}

		if (op==1) {
			if (luci[n1] == 0) {
				luci[n1] = 1;
			}
			else {
				luci[n1] = 1;
			}
		}
		else {

			for (int j = n1; j<=n2; j++ ) {

				if ( luci[j] == 1) {
					if(count == 0){
						count++;
						interv++;
					}
				}
				else {
					count=0;
				}
			}

			printf("%i\n",interv);

			count = 0;
			interv = 0;

		}

	}

	exit(0);

}
