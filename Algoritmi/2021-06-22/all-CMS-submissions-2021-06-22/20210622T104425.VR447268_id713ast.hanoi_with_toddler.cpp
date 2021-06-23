/**
* user:  VR447268_id713ast
* fname: PIETRO
* lname: TAROCCO
* task:  hanoi_with_toddler
* score: 10.0
* date:  2021-06-22 10:44:25.036569
*/
#include<iostream>
#include <cstdio>
#include <cassert>
using namespace std;

long long int numero_mosse(int n){
	assert(n >= 1);
	if(n == 1) return 1;
	return 2 * numero_mosse(n-1) + 1;
}

int main() {

    int t, N;
    cin >> t >> N;
    if(t==0){
		cout << numero_mosse(N);
	}

    return 0;
}
