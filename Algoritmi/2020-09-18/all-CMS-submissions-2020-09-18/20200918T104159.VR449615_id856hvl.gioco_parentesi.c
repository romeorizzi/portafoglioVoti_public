/**
* user:  VR449615_id856hvl
* fname: GIOVANNI
* lname: SCHIAVONE
* task:  gioco_parentesi
* score: 5.0
* date:  2020-09-18 10:41:59.817576
*/
#include <stdio.h>
#include <stdlib.h>

int n,n1,n2;
int conta(char str[]);

void main() {


	n=0;
	scanf("%i", &n);
	char str[n];

	scanf("%s", str);


	if(conta(str)==1)
		printf("1\n%i %i",n1,n2);
	else
		printf("0");

	exit(0);

}

int conta(char str[n]){
	int count=0;
	int times=0;

	for (int i=0;i<n;i++){

		if(count==0) {
			times++;
		}

		if(*(str+i)=='('){
			if(count==0 && times==1){
				n1=i;
			}
			count++;
		}
		else{
			count--;

			if(count==0 && times==1){
				n2=i;
			}
		}
	}

	return times%2;

}
