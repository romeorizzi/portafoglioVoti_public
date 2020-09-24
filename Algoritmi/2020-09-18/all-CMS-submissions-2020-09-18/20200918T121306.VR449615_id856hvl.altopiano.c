/**
* user:  VR449615_id856hvl
* fname: GIOVANNI
* lname: SCHIAVONE
* task:  altopiano
* score: 25.0
* date:  2020-09-18 12:13:06.111461
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>

void conta(int a[], int n1, int n2);

int main() {
    int n,m,z;
    int op,n1,n2;

    scanf("%i",&n);
    scanf("%i",&m);

    int a[n];
	for(int k=0;k<n;k++){
		scanf("%i",&z);
        a[k]=z;
	}

    for (int i=0; i<m; i++) {

    	scanf("%i", &op);
		scanf("%i", &n1);
        scanf("%i", &n2);

		if (op==1) {
			a[n1] += n2;
		}
		else {
			conta(a, n1, n2);
		}
	}
}


void conta(int a[], int n1, int n2){

	float max = 0.5;
    int temp;

	for (int j = n1; j<=n2-2; j++ ) {
		if ( a[j] == a[j+1] && a[j]==a[j+2] ) {

			temp = a[j];
            if(temp>max || max==0.5){
                max=temp;
            }
		}
	}

    if(max==0.5){
        printf("NESSUN_ALTOPIANO\n");
    }
    else{
        temp = max;
        printf("%i\n",temp);
    }

}
