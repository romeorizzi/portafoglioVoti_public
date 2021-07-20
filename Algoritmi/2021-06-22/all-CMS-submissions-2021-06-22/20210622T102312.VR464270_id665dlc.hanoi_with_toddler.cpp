/**
* user:  VR464270_id665dlc
* fname: FABIO
* lname: LENA
* task:  hanoi_with_toddler
* score: 30.0
* date:  2021-06-22 10:23:12.130417
*/
#include <iostream>
using namespace std;

int cont = 0;


void Hannoi(int n, int t, char sorgente, char aux, char destinazione, string conf_attuale, string conf_finale)
{
	string conf_new = "";
	for (int i = 0; i < conf_finale.size(); i++)
		if (i == n)
			conf_new += destinazione;
		else
			conf_new += conf_attuale[i];

	bool last = false;
	if (conf_attuale == conf_finale)
		last = true;

	if (t == 1) {
		if (n == 1 || last)
		{
			cout << "daddy " << "muove il disco " << n << " dal piolo " << sorgente << " al piolo " << destinazione << endl;
			return;
		}

		Hannoi(n - 1, t, sorgente, destinazione, aux, conf_new, conf_finale);
		cout << "toddler " << "muove il disco " << n << " dal piolo " << sorgente << " al piolo " << destinazione << endl;
		Hannoi(n - 1, t, aux, sorgente, destinazione, conf_new, conf_finale);
	}
	else {
		if (n == 1 || last)
		{
			cont++;
			return;
		}

		Hannoi(n - 1, t, sorgente, destinazione, aux, conf_new, conf_finale);
		cont++;
		Hannoi(n - 1, t, aux, sorgente, destinazione, conf_new, conf_finale);
	}
}


int main()
{
	int t;
	int n;
	cin >> t >> n;
	string conf_finale;
	cin >> conf_finale;
	string conf_iniziale = "";
	for (int i = 0; i < n; i++)
		conf_iniziale += "A";

	Hannoi(n, t, 'A', 'C', 'B', conf_iniziale, conf_finale);
	if (t == 0)
		cout << cont << endl;
	return 0;
}