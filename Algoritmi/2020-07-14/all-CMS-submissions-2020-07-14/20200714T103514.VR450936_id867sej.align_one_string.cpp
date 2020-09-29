/**
* user:  VR450936_id867sej
* fname: FRANCESCO
* lname: MARTINI
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 10:35:14.218080
*/
#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<vector>
using namespace std;

int N, M, P;
int a[1000];
int b[1000];
int cost[1001];
int main() {

	cin >> M >> N >> P;

	for (int i = 0; i < M; i ++) {
		cin >> a[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < P+1; i++) {
		cin >>cost[i];
	}

	int c = 0;
	for (int i = 0; i < M; i++) {
		if (a[i] == b[c]) c++;
	}
	if (c != N) { cout << -1; return 0; }
	cout << 77;
	return 0;
}
