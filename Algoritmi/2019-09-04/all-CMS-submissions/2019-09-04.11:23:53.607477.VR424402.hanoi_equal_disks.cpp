/**
* user:  VR424402
* fname: D'ARIENZO
* lname: PAOLO
* task:  Prob2_hanoi_equal_disks
* score: 60.0
* date:  2019-09-04 11:23:53.607477
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <cassert>

using namespace std;

int mode;
int N;
vector<int> disks;
vector<int> card;
vector<int> partSum;

unsigned long long int count(){
	long long int sum = 0;
	
	for (int i = 1; i <=disks.size(); i++){
		sum=sum+card[i-1]*pow(2, disks.size()-i);
	}
	
	return sum;
}

void sposta_disco(int n, char from, char to){
	printf("sposta il disco %d dal piolo %c al piolo %c\n", n, from, to);
}

void sposta_torre(int N, char from, char to, char aux){
		
		if (N == 0)
		return;
		
	sposta_torre(N-1, from, aux, to);
	sposta_disco(N, from, to);
	sposta_torre(N-1, aux, to, from);
}

int main(){

	scanf("%i %i", &mode, &N);
	int tmp;
	for(int i=0; i < N; i++) {
		scanf("%i", &tmp);
		if(disks.size() == 0 || disks[disks.size() - 1] != tmp){
			disks.push_back(tmp);
			card.push_back(0);
		}
		card[disks.size() - 1] = card[disks.size() - 1] + 1;
	}
	if(mode == 0)
		printf("%i", count());
	else
		sposta_torre(N, 'A', 'B', 'C');
	return 0;
}
