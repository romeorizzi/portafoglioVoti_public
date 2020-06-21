/**
* user:  VR424402
* fname: DARIENZO
* lname: PAOLO
* task:  online_budget
* score: 67.0
* date:  2019-07-30 11:58:44.210197
*/
//#include <cassert>
//#include <iostream>
#include <bits/stdc++.h>
//#include <algorithm>

using namespace std;

const int maxN = 50;
const int maxB = 200;
//const int MAX_VAL = 10;
const int VAL = 10000000007;

int N = 0;
int B = 0;
int x[maxN];
int store[maxB];
int n_spese = 0;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int guadagno_monete(int B, int i) {
	return B + x[i];	
}
/*
void spendo_monete(int B, int i){
	
	if(i == N) {
		n_spese++;
		store[B] = n_spese;
	}
	else {
		if(store[B] == -1){ //non l'ho ancora calcolato
			for(int z = B; z >= 0; z--){
				spendo_monete(guadagno_monete(z, i), i + 1);
			}
		}
		else {
			n_spese = n_spese + store[B];
		}
	}
	
}
*/

/*
void spendo_monete(int B, int i){

	if(store[B] == -1){ //non l'ho ancora calcolato
	
		if(i == N) {
			n_spese++;
			store[B] = n_spese;
		}
		else {
			for(int z = B; z >= 0; z--){
				spendo_monete(guadagno_monete(z, i), i + 1);
			}
		}
	
	}
	else {
		n_spese = (n_spese + store[B]) % VAL;
	}
	
}
*/

void spendo_monete(int B, int i){

	if(i == N)
		n_spese++;
	else {
		for(int z = B; z >= 0; z--){
				spendo_monete(guadagno_monete(z, i), i + 1);
			}
	}
	
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> N >> B;
	
	for(int i = 0; i < N; i++){
		cin >> x[i];
	}
	
    //print_array(x, n);
	
	fill_n(store, 200, -1);
	
	spendo_monete(B, 0);
	
	//cout << n_spese % VAL << "\n";
	cout << n_spese << "\n";

}





