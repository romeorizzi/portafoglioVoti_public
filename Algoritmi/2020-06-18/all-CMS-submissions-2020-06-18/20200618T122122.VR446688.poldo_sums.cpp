/**
* user:  VR446688
* fname: LUTTERI
* lname: NICOLO
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 12:21:22.847712
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

#define EVAL
#define DIMMAX 100000

int lunghezza;

int panino[DIMMAX];
int gym[DIMMAX];

int sol[DIMMAX];
int posizione = 0;

int tmp[DIMMAX];

int prendisomma(int primo, int secondo)
{
	if (primo - 1 == secondo)
		return tmp[secondo];

	int valore1 = tmp[secondo];
	int valore2 = tmp[primo - 1];

	if (valore1 < 0 && valore2 < 0)
	{
		return -valore2 + valore1;
	}
	else
	{
		if (valore2 - valore1 < 0)
		{
			return valore1 - valore2;
		}
		else
		{
			return valore2 - valore1;
		}
	}
}

void ritorna()
{
	for (int i = 0; i < lunghezza; i++)
	{
		for (int j = i + 1; j < lunghezza; j++)
		{
			int somma = 0;
			for (int z = i; z < j; z++)
			{
				somma = somma + gym[z];
			}

			//cout << to_string(i) << " " << to_string(j) << " " << to_string(somma) << endl;

			//int v = prendisomma(i, j - 1);
			//assert(somma == v);

			if (panino[j] >= panino[i] + somma)
			{
				sol[posizione] = i;
				posizione = posizione + 1;
				sol[posizione] = j;
				posizione = posizione + 1;

				i = j + 1;
				j = i + 1;
			}
		}
	}
}

void prepara()
{
	int attuale = 0;
	for (int i = 0; i < lunghezza; i++)
	{
		tmp[i] = attuale + gym[i];
		attuale = attuale + gym[i];
	}

	return;
}

int main()
{
#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d", &lunghezza);

	for (int i = 0; i < lunghezza; i++)
	{
		scanf("%d %d", &panino[i], &gym[i]);
	}

	prepara();
	ritorna();

	cout << to_string(posizione) + " ";
	for (int i = 0; i < posizione - 1; i++)
	{
		cout << to_string(sol[i]) + " ";
	}
	cout << sol[posizione - 1] << endl;
}
