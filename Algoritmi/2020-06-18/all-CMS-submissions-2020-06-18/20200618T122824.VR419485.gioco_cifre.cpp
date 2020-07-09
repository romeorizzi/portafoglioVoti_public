/**
* user:  VR419485
* fname: QUINCI
* lname: OLIVIO
* task:  gioco_cifre
* score: 0.0
* date:  2020-06-18 12:28:24.818017
*/


#include<bits/stdc++.h>
using namespace std;


#define PLAYER1 1
#define PLAYER2 2


int calculateMex(unordered_set<int> Set)
{
    int Mex = 0;

    while (Set.find(Mex) != Set.end())
        Mex++;

    return (Mex);
}

// Una funzione per calcolare il numero di Grundy di 'n'
int calculateGrundy(int n, int Grundy[],int s[])
{//........accumulate
   Grundy[s[0]] = n-s[0];
    Grundy[s[1]] = n-s[1];
    Grundy[s[2]] = n-s[2];
    Grundy[s[3]] = n-s[3];
    //.....................

            if (Grundy[n] != -1)
        return (Grundy[n]);

    unordered_set<int> Set; // Una tabella hash

    for (int i=1; i<=4; i++)
                    Set.insert (calculateGrundy (n-i, Grundy,s));


    Grundy[n] = calculateMex (Set);

    return (Grundy[n]);
}
int ss,dd;
// Una funzione per dichiarare il vincitore del gioco
void uscita(int turno, int piles[],
                    int Grundy[], int n)
{int orr =Grundy[piles[0]];
int vert =Grundy[piles[1]];//
//if (orr != 0)
int nim_sum=(orr^vert);
int mm=(piles[0]-1);
if ((nim_sum) < mm)
            {ss =piles[0]-(nim_sum);
            dd=piles[1];
            }
else
            {  dd =piles[1]-(nim_sum);
            ss=piles[0];

            }

    int xorValue = Grundy[piles[0]];//primo perno

    for (int i=1; i<=n-1; i++)
        xorValue = xorValue ^ Grundy[piles[i]];//XOR tra i due perni

    if (xorValue != 0)
    {    int pos1=piles[0]-(orr^vert);
        if (turno == PLAYER1)
            printf("Player 1 vincera'\n%d %d", ss,dd);

        else
            printf("Player 2 vincera'\n");
    }
    else
    {
        if (turno == PLAYER1)
            printf("Player 2 vincera'\n");
        else
            printf("Player 1 vincera'\n");
    }

    return;
}




int main()
{ std::fstream in("input.txt");
  std::ofstream out("output.txt");

   int L;
    in >> L;
int s[10] = {0};
   int f=0;
   int LL=L;
   while (LL > 0)
   {

      s[f]= (LL % 10);
     f=f+1;
      LL /= 10;
}

    int piles[] = {L};
    int n = 1;


    int maximum = *max_element(piles, piles + n);

    int Grundy[maximum + 1];
    memset(Grundy, -1, sizeof (Grundy));

    for (int i=0; i<=n-1; i++)
   calculateGrundy(piles[i], Grundy,s);

    uscita(PLAYER1, piles, Grundy, n);


    return (0);
}
