/**
* user:  VR451823EXAM
* fname: CINQUETTI
* lname: ETTORE
* task:  gioco_cifre
* score: 0.0
* date:  2020-06-18 11:53:00.093767
*/
#include <stdio.h>
using namespace std;

int main (void) {

	int number;
	scanf("%d", &number);

	if(number%10 == 0) printf("0");
	else {
		int x = number%10 - 1;
		printf("1"); printf("%d", x);
	}


}