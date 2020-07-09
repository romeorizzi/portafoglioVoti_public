/**
* user:  VR446688
* fname: LUTTERI
* lname: NICOLO
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 10:26:05.449000
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
#define DIMMAX 10000

#define DIMMATRIX 100

int lunghezza;

int panino[DIMMAX];
int gym[DIMMAX];

int C[DIMMAX];
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
		return -valore2 - -valore1;
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

			cout << to_string(i) << " " << to_string(j) << " " << to_string(somma) << endl;

			int v = prendisomma(i, j - 1);
			assert(somma == v);

			if (panino[j] >= panino[i] + somma)
			{
				C[posizione] = i;
				posizione = posizione + 1;
				C[posizione] = j;
				posizione = posizione + 1;

				i = j + 1;
				j = i + 1;
			}
		}
	}
}

void ritorna2()
{
	int attuale = 0;
	for (int i = 0; i < lunghezza; i++)
	{
		tmp[i] = attuale + gym[i];
		attuale = attuale + gym[i];
	}

	return;

	/*for (int r = 1; r - 1 < lunghezza; r++)
	{
		for (int c = r; c < lunghezza; c++)
		{
			tmp[r][c] = tmp[r - 1][c];
		}
	}

	int r;
	for (r = 0; r < lunghezza; r++)
	{
		int attuale;
		if (r == 0)
		{
			attuale = 0;
		}
		else
		{
			attuale = tmp[r - 1][r-1];
		}

		for (int colonna = 0; colonna < lunghezza; colonna++)
		{
			tmp[r][colonna] = attuale + gym[colonna];
			attuale = attuale + gym[colonna];
		}
	}*/

	return;
}

int main()
{
#ifdef EVAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	scanf("%d", &lunghezza);

	for (int i = 0; i < lunghezza; i++)
	{
		scanf("%d %d", &panino[i], &gym[i]);
	}

	ritorna2();
	ritorna();
}
