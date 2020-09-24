/**
* user:  VR449410_id693zhn
* fname: ANDREA
* lname: MULTINEDDU
* task:  gioco_parentesi
* score: 0.0
* date:  2020-09-18 10:17:13.587942
*/
#include<iostream>

using namespace std;


char fbf[100];
int accoppiamenti[100];
int start_dispari;
int end_dispari;


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
	cout << start << " " << end << endl;
	int meta = accoppiamenti[start];
	cout << start + 1 << " " << meta - 1 << " " << meta + 1 << " " << end << endl;
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
			int aperte = 0;
			//cout << "i " << i << endl;
			for(int j = i + 1; fbf[j] != '\0'; j++)
			{
				//cout << "j " << j << endl;
				if(fbf[j] == '(')
				{
					aperte++;
				}
				else
				{
					aperte--;
				}
				
				if(aperte < 0)
				{
					accoppiamenti[i] = j;
					break;
				}
			}
		}
	}
	
	for(; i < 100; i++)
		accoppiamenti[i] = 0;
	/*
	for(i = 0; accoppiamenti[i] != 0; i++)
		cout << accoppiamenti[i] << " ";
	cout << endl;
	*/
	
	//conto le macroparentesi
	int count_macro = 0;
	for(i = 0; accoppiamenti[i] != 0;)
	{
		//cout << "i " << i << endl;
		count_macro++;
		i = accoppiamenti[i] + 1;
	}
	
	if(count_macro % 2 == 0)
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
		
		cout << "count " << count << endl;
		
		if(count % 2 == 1)
			cout << 1 << endl << start_dispari << " " << end_dispari << endl;
		else
			cout << 0;
	}
	//((()())())(())()()
}

int main()
{
	cin >> fbf;
	
	calcola_esito();
	
	return 0;
}
