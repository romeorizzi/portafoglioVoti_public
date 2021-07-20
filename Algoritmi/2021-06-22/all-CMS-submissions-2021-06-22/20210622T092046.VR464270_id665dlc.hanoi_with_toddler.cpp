/**
* user:  VR464270_id665dlc
* fname: FABIO
* lname: LENA
* task:  hanoi_with_toddler
* score: 0.0
* date:  2021-06-22 09:20:46.894752
*/
#include <iostream>
#include <fstream>
using namespace std;


ifstream fcin("input.txt");
ofstream fcout("output.txt");

void Hannoi(int n,int n_max, char sorgente, char destinazione, char aux, int pers, string conf_attuale,  string conf_finale) {
	// Settaggio persona
	string persona;
	if (pers == 1)
		persona = "toddler";
	else
		persona = "daddy";
	
	if (conf_attuale == conf_finale) {
		return;
	}

	// Algoritmo Hannoi ricorsivo
	if(n == 1){
		fcout << persona << " muove il disco " << n << " dal piolo " << sorgente << " al nodo " << destinazione  << endl;
		return;
	}
	
	string conf_nuova = "";
	for (int i = 1; i <= n_max; i++) {
		if (i == n) {
			conf_nuova += destinazione;
		}
		else
			conf_nuova += conf_attuale[i - 1];
	}
	cout << conf_attuale <<endl;
	cout << conf_nuova <<endl;
	Hannoi(n - 1, n_max, sorgente, aux, destinazione, pers * -1, conf_nuova, conf_finale);
	fcout << persona << " muove il disco " << n << " dal piolo " << sorgente << " al nodo " << destinazione << endl;
	Hannoi(n - 1, n_max, aux, sorgente, destinazione, pers * -1, conf_nuova, conf_finale);
}	

int main() {
	
	int t, n;
	string conf_finale;
	fcin >> t >> n >> conf_finale;

	string conf_iniziale = "";
	for (int i = 1; i <= n; i++)
		conf_iniziale += "A";

	if (t == 0) {
		fcout << (n * n) - 1 << endl; // formula generale per il numero di mosse di Hannoi dato n (evito ricorsione così)
	}
	else
		Hannoi(n, n,'A', 'B', 'C', -1, conf_iniziale, conf_finale);
}



