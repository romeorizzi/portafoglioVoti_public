/**
* user:  VR451823EXAM
* fname: CINQUETTI
* lname: ETTORE
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 12:09:40.695169
*/
#include<fstream>
#include<iostream>
using namespace std;

int main (void) {

	int number;
	cin >> number;

	if(number%10 == 0) printf("0");
	else {
		int x = number%10;
		printf("1"); printf(" %d", x);
	}


}
