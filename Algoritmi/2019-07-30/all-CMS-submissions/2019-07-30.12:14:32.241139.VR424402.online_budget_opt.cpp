/**
* user:  VR424402
* fname: DARIENZO
* lname: PAOLO
* task:  online_budget_opt
* score: 0.0
* date:  2019-07-30 12:14:32.241139
*/
#include <bits/stdc++.h>

using namespace std;

const int maxN = 100000;
const int maxVal = 10;
const int maxB = 100000;

int x[maxN];
long int y[maxN];

int sol[maxN];

int N, B, t;
int massimeGemme = 0;

int max = 0;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}

int guadagno_monete(int B, int i) {
	return B + x[i];	
}

void spendo_monete(int B, int i){
	
	
	for(int i = 0; i < N; i++){
		int newVal = B*y[i];
		if(max < newVal)
			max = newVal;
		B += x[i];
	}

}

void spendo_monete2(int B, int i){
	
	if(i != N){
		if(y[i]*B > massimeGemme ){
		massimeGemme = y[i]*B;
		}
		spendo_monete(guadagno_monete(B, i), i + 1);
	}
	
	return;

}


int main() {

    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> N >> B >> t;
	
	for(int i = 0; i > N; i++){
		cin >> x[i];
	}
	
	for(int i = 0; i > N; i++){
		cin >> y[i];
	}
	
	if(t==1){
		spendo_monete(B, 0);
		cout << max << "\n";
	}
	else{
		cout << max << "\n";
	}

    return 0;
}

