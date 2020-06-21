/**
* user:  VR439620
* fname: MOLINARI
* lname: DAVIDE
* task:  biancaneve
* score: 10.0
* date:  2019-06-25 10:50:33.675195
*/
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

int sequenzaNani[200000];
int posizioniNani[200000];

void SpostaNani(int p1, int p2)
{
    posizioniNani[sequenzaNani[p2]] = p1;
    posizioniNani[sequenzaNani[p1]] = p2;
}
bool ControllaAltezze(int h1,int h2, int N)
{
    int maxH = max(h1,h2);
    int minH = min(h1,h2);
    int start = min(posizioniNani[h1],posizioniNani[h2]);
    int fine = max(posizioniNani[h1],posizioniNani[h2]);
    for(int h = 1;h <= N;h++)
    {
        if(posizioniNani[h] >= start && posizioniNani[h] <= fine && (h < minH || h > maxH ))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    fstream in;
    int M,N,tipo,par1,par2;
    bool ok;
    //in.open("att/input1.txt",ios::in);
    in.open("input.txt",ios::in);
    in >> N >> M;
    for (int i = 0; i < N; i++)
    {
        in >> sequenzaNani[i];
        posizioniNani[sequenzaNani[i]] = i;
    }
    
    for (int i = 0; i < M; i++)
    {
        in >> tipo >> par1 >> par2;
        if (tipo == 1)
            SpostaNani(par1-1,par2-1);
        else{
            if( ControllaAltezze(par1,par2,N) == true)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
