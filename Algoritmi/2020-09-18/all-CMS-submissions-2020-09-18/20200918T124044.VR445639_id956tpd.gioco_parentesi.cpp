/**
* user:  VR445639_id956tpd
* fname: ROSA
* lname: RUSSO
* task:  gioco_parentesi
* score: 5.0
* date:  2020-09-18 12:40:44.059714
*/
#include<iostream>

using namespace std;


int N;
char fbf[1000000];
int accoppiamenti[1000000];
int start_odd;
int end_odd;


int count_sottoparentesi_ric(int start, int end)
{
	if(start > end)
	{
		return 0;
	}
	if(start == end - 1)
	{
		return 1;
	}
	//cout << start << " " << end << endl;
	int meta = accoppiamenti[start];
	//cout << start + 1 << " " << meta - 1 << " " << meta + 1 << " " << end << endl;
	return 1 + count_sottoparentesi_ric(start + 1, meta - 1) + count_sottoparentesi_ric(meta + 1, end);
}

void calcola_esito()
{
	for(int i = 0; i < 100; i++)
		accoppiamenti[i] = -1;
	
	int i;
	for (i = 0; fbf[i] != '\0'; i++)
	{
		if(fbf[i] != ')')
		{
			int left = 0;
			//cout << "i " << i << endl;
			for(int j = i + 1; fbf[j] != '\0'; j++)
			{
				//cout << "j " << j << endl;
				if(fbf[j] == '(')
				{
					left++;
				}
				else
				{
					left--;
				}
				
				if(left < 0)
				{
					accoppiamenti[i] = j;
					break;
				}
			}
		}
	}
	
	for(; i < 100; i++)
		accoppiamenti[i] = 0;

	
	//conto le macroparentesi
	int count_macro = 0;
	for(i = 0; accoppiamenti[i] != 0;)
	{
		//cout << "i " << i << endl;
		count_macro++;
		i = accoppiamenti[i] + 1;
	}
	
	if(count_macro == 1)
		cout << 1 << endl << 0 << " " << accoppiamenti[0];
	else if(count_macro % 2 == 0)
		cout << 0;
	else
	{
		//conto le sottoparentesi
		int count = 0;
		for(i = 0; accoppiamenti[i] != 0;)
		{
			count += count_sottoparentesi_ric(i + 1, accoppiamenti[i] - 1);
			i = accoppiamenti[i] + 1;
		}
		
		if(count % 2 == 1)
			cout << 1 << endl << start_odd << " " << end_odd << endl;
		else
			cout << 0;
	}
}

int main()
{
	cin >> N;
	cin >> fbf;
	
	calcola_esito();
	return 0;
}
