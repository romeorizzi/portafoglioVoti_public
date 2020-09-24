/**
* user:  VR451060_id716xls
* fname: NICHOLAS
* lname: CARON
* task:  gioco_parentesi
* score: 5.0
* date:  2020-09-18 12:42:57.975038
*/
#include<iostream>

using namespace std;


int N;
char fbf[1000000];
int matching[1000000];
int start_odd;
int end_odd;


int count_subFBF_ric(int start, int end)
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
  int meta = matching[start];
  //cout << start + 1 << " " << meta - 1 << " " << meta + 1 << " " << end << endl;
  return 1 + count_subFBF_ric(start + 1, meta - 1) + count_subFBF_ric(meta + 1, end);
}

void findingResult()
{
  for(int i = 0; i < 100; i++)
    matching[i] = -1;
  
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
          matching[i] = j;
          break;
        }
      }
    }
  }
  
  for(; i < 100; i++)
    matching[i] = 0;
  /*
  for(i = 0; matching[i] != 0; i++)
    cout << matching[i] << " ";
  cout << endl;
  */
  
  //conto le macroparentesi
  int count_macro = 0;
  for(i = 0; matching[i] != 0;)
  {
    //cout << "i " << i << endl;
    count_macro++;
    i = matching[i] + 1;
  }
  
  if(count_macro == 1)
    cout << 1 << endl << 0 << " " << matching[0];
  else if(count_macro % 2 == 0)
    cout << 0;
  else
  {
    //conto le subFBF
    int contatore = 0;
    for(i = 0; matching[i] != 0;)
    {
      contatore += count_subFBF_ric(i + 1, matching[i] - 1);
      i = matching[i] + 1;
    }
    
    //cout << "contatore " << contatore << endl;
    
    if(contatore % 2 == 1)
      cout << 1 << endl << start_odd << " " << end_odd << endl;
    else
      cout << 0;
  }
  //((()())())(())()()
}

int main()
{
  cin >> N;
  cin >> fbf;
  
  findingResult();
  return 0;
}
