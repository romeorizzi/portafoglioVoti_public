/**
* user:  VR440462
* fname: GOBBI
* lname: FRANCESCO
* task:  Prob2_hanoi_equal_disks
* score: 60.0
* date:  2019-09-04 10:41:53.535424
*/
#include <iostream>
#include <cstdio>
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


unsigned long long int count() {
	long long unsigned int sum=0;

 	for(int i=1; i<=disks.size(); i++){
		sum=sum+card[i-1]*pow(2,disks.size()-i);
	}
	return sum;
}

void sposta_disco(int N, int from, int to) {
    printf("Sposto il disco %d dal piolo %c al piolo %c\n",
            N, from, to);
}

void sposta_torre(int N, char from, char to, char piolo_di_appoggio) {
    // sposta una torre di N dischi (da 1 a N)
    // incolonnati nel piolo from
    // portandoli incolonnati nel piolo to
    assert(N >= 0);
    if(N == 0) return;

    assert(N >= 1);

    sposta_torre(N-1, from, piolo_di_appoggio, to);
    sposta_disco(N, from, to);
    sposta_torre(N-1, piolo_di_appoggio, to, from);
}

int main(){
    scanf("%i %i", &mode, &N);
    int tmp;
    for (int i = 0; i<N; i++){
        scanf("%i", &tmp);
        if (disks.size() == 0 || disks[disks.size()-1] != tmp){
            disks.push_back(tmp);
            card.push_back(0);
        }
        card[disks.size()-1] = card[disks.size()-1]+1;
        //printf("%i ", partSum[disks.size()-1]);
    }
    if (mode == 0)
    printf("%llu", count());
    else
    sposta_torre(N, 'A', 'B', 'C');

    return 0;
}
