/**
* user:  VR464270_id665dlc
* fname: FABIO
* lname: LENA
* task:  hanoi_with_toddler
* score: 0.0
* date:  2021-06-22 07:58:53.523145
*/
#include <iostream>
//#include <fstream>
using namespace std;


//ifstream fcin("input.txt");
//ofstream fcout("output.txt");

void Hannoi(int n, char sorgente, char destinazione, char aux, int pers) {
	// Settaggio persona
	string persona;
	if (pers == 1)
		persona = "toddler";
	else
		persona = "daddy";
	
	// Algoritmo Hannoi ricorsivo
	if(n == 1){
		cout << persona << " muove il disco " << n << " dal piolo " << sorgente << " al nodo " << destinazione  << endl;
		return;
	}
	Hannoi(n - 1, sorgente, aux, destinazione, pers * -1);
	cout << persona << " muove il disco " << n << " dal piolo " << sorgente << " al nodo " << destinazione << endl;
	Hannoi(n - 1, aux, destinazione, sorgente, pers * -1);
}	

int main() {

	int t, n;
	char carattere_arrivo;
	cin >> t >> n >> carattere_arrivo;

	char aux;
	if (carattere_arrivo == 'B')
		aux = 'C';
	else
		aux = 'B';

	if (t == 0) {
		cout << (n * n) - 1 << endl; // formula generale per il numero di mosse di Hannoi dato n (evito ricorsione così)
	}
	else
		Hannoi(n, 'A', carattere_arrivo, aux, -1);
}



