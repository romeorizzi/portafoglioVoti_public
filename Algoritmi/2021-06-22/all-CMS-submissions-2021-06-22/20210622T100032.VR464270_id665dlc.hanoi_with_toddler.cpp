/**
* user:  VR464270_id665dlc
* fname: FABIO
* lname: LENA
* task:  hanoi_with_toddler
* score: 30.0
* date:  2021-06-22 10:00:32.636079
*/
#include <iostream>
using namespace std;

int cont = 0;


void Hannoi(int n, int t, char sorgente, char aux, char destinazione)
{
	if (t == 1) {
		if (n == 1)
		{
			cout << "daddy " << "muove il disco " << n << " dal piolo " << sorgente << " al piolo " << destinazione << endl;
			return;
		}

		Hannoi(n - 1, t, sorgente, destinazione, aux);
		cout << "toddler " << "muove il disco " << n << " dal piolo " << sorgente << " al piolo " << destinazione << endl;
		Hannoi(n - 1, t, aux, sorgente, destinazione);
	}
	else {
		if (n == 1)
		{
			cont++;
			return;
		}

		Hannoi(n - 1, t, sorgente, destinazione, aux);
		cont++;
		Hannoi(n - 1, t, aux, sorgente, destinazione);
	}
}


int main()
{
	int t;
	int n;
	cin >> t >> n;
	string conf_finale;
	cin >> conf_finale;

	Hannoi(n, t, 'A', 'C', 'B');
	if (t == 0)
		cout << cont << endl;
	return 0;
}