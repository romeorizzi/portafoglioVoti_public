/**
* user:  VR447271EXAM
* fname: BALLINI
* lname: LEONARDO
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 10:42:34.593290
*/
#include <iostream>
using namespace std;
int main(){
	int num;
	cin >> num;
	if(num%10 == 0)
		cout << 0 <<"\n";
	else
		cout << 1 << " " << num % 10 << "\n";
}
