/**
* user:  VR450936_id867sej
* fname: FRANCESCO
* lname: MARTINI
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 12:58:17.274183
*/
#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<vector>
using namespace std;

int N, M, P;
string a;
string b;
string sol;
int cost[1001];
int m[1001][1001];
int mino = 10000000;

int calc_min(string s) {

	int sum = 0;
	int c = 0;
	for (int i = 0; i < M; i++) {
		
		if (sol[i] == '*') { 
			c++; }
		else {
			sum += cost[c];
			c = 0;
		}

	}

	sum += cost[c];
	return sum;
}


void calc_string(int in, int cn)
{
	int v;
	if (in == M && cn == N) {
		v = calc_min(sol);
		if (v < mino) 
			mino = v;
		return;
	}

	if (cn == N || b[cn] != a[in]){
		sol[in] = '*';
		calc_string(in+1, cn);
		return;
	}

	sol[in] = b[cn];
	calc_string(in+1, cn+1);

	sol[in] = '*';
	calc_string(in+1, cn);
	return;
}


int main() {

	cin >> M >> N >> P;

	cin >> a;
	
	cin >> b;
	sol = a;
	for (int i = 0; i < 1001; i++) {
		cost[i]=1000000000000;
	}

	for (int i = 0; i < P+1; i++) {
		cin >>cost[i];
	}

	int c = 0;
	for (int i = 0; i < M; i++) {
		if (a[i] == b[c]) c++;
	}
	if (c != N) { cout << -1; return 0; }
	
	for (int i = 2; i < 1001; i++) {
		for (int c = i-1; c >= 0; c--) {
			if (cost[c] + cost[i-c] < cost[i]) {
				cost[i] = cost[c] + cost[i - c];

			}
		}
	}
	
	calc_string(0, 0);



	cout << mino;


	return 0;
}
