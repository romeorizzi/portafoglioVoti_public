/**
* user:  VR472058
* fname: ALESSANDRO
* lname: FURIA
* task:  A_seq
* score: 0.0
* date:  2022-06-29 11:00:26.903823
*/
#include <fstream>
#include <stdlib.h>
#include <iostream>
#define N 10000

using namespace std;

int g, n;
int s[N];
int reversed[N];
int cresc[N];
int decresc[N];
int sum[N];

int max(int start){
	int max = 0;
	for(int i=start; i<n; i++){
		if(s[i] < s[start]){
			if(decresc[i] > max){
				max=decresc[i];
			}
		}
	}
	return max;
}

int max_reverse(int start){
	int max = 0;
	for(int i=start; i<n; i++){
		if(reversed[i] < reversed[start]){
			if(cresc[i] > max){
				max=cresc[i];
			}
		}
	}
	return max;
}

int max_total(){
	int max = 0;
	for(int i=0; i<n; i++){
		if(sum[i] > max){
			max = sum[i];
		}
	}
	return max;
}

int main(){

	cin >> g;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> s[i];
	}

	for(int i=0; i<n; i++){
		reversed[i]=s[n-1-i];
	}


	for(int i=n-1; i>=0; i--){
		decresc[i] = 1 + max(i);
	}

	for(int i=n-1; i>=0; i--){
		cresc[i] = 1 + max_reverse(i);
	}

	int appo[N];

    for(int i=0; i<n; i++){
        appo[i] = cresc[n-1-i];
	}

	for(int i=0; i<n; i++){
		sum[i]=appo[i]+decresc[i]-1;
	}


	int max = max_total();

	if(g == 1)
        cout << max;

    else if(g == 2){
        int count = 0;
        for(int i=0; i<n; i++){
            if(sum[i] == max)
                count++;
        }
        cout << count%1000000007;
    }

    cout << "\n";

    for(int i=0; i<n; i++){
		cout << appo[i];
	}

	cout << "\n";

	for(int i=0; i<n; i++){
		cout << decresc[i];
	}

	cout << "\n";

	for(int i=0; i<n; i++){
		cout << sum[i];
	}

	return 0;
}


