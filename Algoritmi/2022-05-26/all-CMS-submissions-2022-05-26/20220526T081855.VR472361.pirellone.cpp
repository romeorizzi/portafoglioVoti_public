/**
* user:  VR472361
* fname: PERANTONI
* lname: ELIA
* task:  pirellone
* score: 50.0
* date:  2022-05-26 08:18:55.925598
*/
#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

const int bits_count = 500;
using row_t = bitset<bits_count>;

int m, n;
row_t mat[500]{0};

// flips_rows[i]=1 IFF the i-th row (zero-indexed) should be flipped
bool flip_rows[500];

int main() {
	ifstream f_in{"input.txt"};
	ofstream f_ou{"output.txt"};
	
	f_in >> m >> n;

	row_t mask = ~((~0) << n);
	cout << "Mask:" << endl << mask << endl;
	cout << "--------------------------------" << endl;


	for(int row=0;row<m;row++) {
		for(int col=0;col<n;col++){
			int light;
			f_in >> light;

			if(light) {
				mat[row].set(n-col-1);
			}
		}
	}

	for(int row=0;row<m;row++) {
		cout << mat[row] << endl;
	}
	cout << "--------------------------------" << endl;


	for(int row=1;row<m;row++) {
		if (mat[row] == mat[0]) {
			// Do nothing
		} else if (mat[row] == (~mat[0] & mask)) {
			flip_rows[row] = true;
		} else {
			for(int row=0;row<m;row++) {
				f_ou << 0;
				if(row < m-1) f_ou << " ";
			}
			f_ou << endl;
			for(int col=0;col<n;col++) {
				f_ou << 0;
				if(col < n-1) f_ou << " ";
			}
			f_ou << endl;
			return 0;
		}
	}

	for(int row=0;row<m;row++) {
		cout << "Flip " << row << ": " << flip_rows[row] << endl;
	}
	cout << "--------------------------------" << endl;

	for(int row=0;row<m;row++) {
		f_ou << flip_rows[row];
		if(row < m-1) f_ou << " ";
	}
	f_ou << endl;
	for(int col=0;col<n;col++) {
		f_ou << mat[0][n-col-1];
		if(col < n-1) f_ou << " ";
	}
	f_ou << endl;
}
