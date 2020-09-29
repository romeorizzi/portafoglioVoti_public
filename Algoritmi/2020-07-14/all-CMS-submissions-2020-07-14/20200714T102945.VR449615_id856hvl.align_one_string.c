/**
* user:  VR449615_id856hvl
* fname: GIOVANNI
* lname: SCHIAVONE
* task:  align_one_string
* score: 2.0
* date:  2020-07-14 10:29:45.676067
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int costo(char str[], int cost[], int m);
int find (char a[], char b[], char b_1[], int i1, int i2, int cost[]);

void main (int argc, char *argv[]) {

	int n, m, p;

	scanf("%i", &m);
	scanf("%i", &n);
	scanf("%i", &p);

	char a[m];
	char b[n];

	scanf("%s", a);
	scanf("%s", b);

	int cost[p+1];

	for (int i=0; i<p+1; i++){
		scanf("%i", &cost[i]);
	}

	char b_1[m];
	memset(b_1,0,m);
	for (int k=0; k<m; k++) {
		b_1[k] = '*';
	}

	printf("%i",find(a,b,b_1,0,0,cost));


	exit(0);

}

int find (char a[], char b[], char b_1[], int i1, int i2, int cost[]){
	int n1, n2;

	if (i2 == strlen(b)) {
		return costo(b_1, cost,strlen(a));
	}

	for (int i=i1; i<strlen(a); i++) {
		//trovato
		if(a[i] == b[i2]) {

			char b_2[strlen(a)];

			for (int k=0; k<strlen(a); k++) {
				b_2[k] = b_1[k];
			}

			b_2[i]=a[i];

			n1 = find(a, b, b_2, i+1, i2+1, cost);

			n2 = find(a, b, b_1, i+1, i2, cost);

			if ( n1 != -1 || n2 != -1) {
				if(n1==-1){
					return n2;
				}
				else if(n2==-1){
					return n1;
				}
				else if(n1<n2){
					return n1;
				}
				else {
					return n2;
				}
			}
			else {
				return -1;
			}
		}
	}

	return -1;
}

int costo(char str[], int cost[], int m) {



	int count=0;
	int cos=0;
	for (int i=0; i<m;i++) {
		if(str[i]=='*'){
			count++;
		}
		else{
			cos += cost[count];
			count=0;
		}
	}
	cos += cost[count];
	return cos;
}
