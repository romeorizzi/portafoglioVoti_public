/**
* user:  VR424402
* fname: D'ARIENZO
* lname: PAOLO
* task:  Prob2_hanoi_equal_disks
* score: 20.0
* date:  2019-09-04 10:26:43.917043
*/
#include <cassert>
#include <cstdio>
#include <cmath>

using namespace std;

const int DEBUG = 0;
const int MAXN = 100000;

int t, N;
int d[MAXN+1];
int k[MAXN+1];

typedef long long unsigned int llu;

unsigned long long int count (int diversi, int k[]){
	llu sum = 0;
	
	for(int i = 1; i <= diversi; i++){
		sum = sum+k[i] * pow(2, diversi-i);
	}
	return sum;
}

void sposta_disco(int n, char from, char to){
	printf("sposta il disco %d dal piolo %c al piolo %c\n", n, from, to);
}

void sposta_torre(int N, char from, char to, char aux){

	if (N == 0)
		return;
	/*
	sposta_torre(N-1, from, aux, to);
	sposta_disco(N, from, to);
	sposta_torre(N-1, aux, to, from);
	*/
	sposta_torre(N-1, from, aux, to);
	if(N-1 == N){
		sposta_torre(N-1, from, aux, to);
		sposta_torre(N-1, aux, to, from);
	}
	sposta_torre(N-1, aux, to, from);
}

int main(){

	scanf("%d%d", &t, &N);
	
	for(int i = 1; i <= N; i++){
		scanf("%d", &d[i]);
	}
	
	llu num_mosse = 1;
	
	int diversi = 0, check = 1, occ = 1;
	
	for(int i = 1; i <= N; i++){
		for(int j = i + 1; j <= N; j++) {
		
			if(d[i] == d[j]){
				check = 0;
				occ++;
			}
		}
		
		if(check == 1){
			diversi++;
			k[i] = 1;
		}
		else {
			k[i] = occ;
		}
		
		occ = 1;
		check = 1;
	}
	
	if (t == 0)
		printf("%llu\n", num_mosse = count(diversi, k));
	else
		sposta_torre(N, 'A', 'C', 'B');
		 
	
	return 0;

}

