/**
* user:  VR424402
* fname: DARIENZO
* lname: PAOLO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 10:54:12.316489
*/
#include <bits/stdc++.h>


using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

vector<int> vec1, vec2;

int writeType2(int deep){
	int child;
	cin >> child;
	int count = 1;
	cout << deep << " ";
	while(count < child){
		count =+ writeType2(deep + 1);
	}
	cout << deep << " ";
	return child;
}

void writeType1(){
	vec2.push_back(0);
	int temp;
	cin >> temp;
	do {
		cin >> temp;
		vec2.push_back(temp);
	}
	while (temp > 0);
	calcVec1(0, 0);
	for(int i = 0 ; i < vec1.size(); i++) {
		cout << vec1[i] << " ";
	}	
}

int calcVec1(int index1, int index2){
	vec1.push_back(1);
	int deep;
	deep = vec2[index2];
	while(vec2[index2 + 2*vec1[index1] - 1] > deep){
		vec1[index1] += calcVec1(index1 + vec1[index1], index2 + 2*vec1[index1] - 1);
	}
	return vec1[index1];	
	}
	
	
int main(){
	
	assert(cin);
	assert(cout);
	int type;
	cin >> type;
	cout << 3-type << " ";
	if(type == 1) {
		writeType2(0);
	}
	else {
		writeType1();
	}
	cout << "\n";
	
	return 0;

}
































